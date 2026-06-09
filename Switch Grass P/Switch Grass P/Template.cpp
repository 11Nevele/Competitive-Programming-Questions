#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline long long readLL()
{
    long long ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
class DSU
{
private:
    std::vector<size_t> parent;

public:
    std::vector<size_t> cnt;
    DSU(size_t size) :parent(size), cnt(size, 1)
    {
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }
    size_t Find(size_t x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Unite(size_t a, size_t b)
    {
        int pa = parent[Find(a)], pb = parent[Find(b)];
        if (cnt[pa] > cnt[pb])
        {
            cnt[pa] += cnt[pb];
            parent[pb] = pa;
        }
        else
        {
            cnt[pb] += cnt[pa];
            parent[pa] = pb;
        }
    }
};
class Edge
{
public:
    int x;
    int y;
    int d;
    bool operator <(const Edge& other) const
    {
        return d < other.d;
    }
};
class node
{
public:
    int x;
    int w;
};
vector<vector<node>> adj(200005);
vector<int> parent(200005), parentLength(200005), color(200005), cur(200005, -1);
vector<unordered_map<int, int>> mps(200005);
vector<multiset<int>> nodeMx(200005);
vector<multiset<pair<int, int>>> sets(200005);
multiset<int> best;
LL MST(int n, vector<Edge>& edges)
{
    LL ans = 0;
    DSU dsu(n + 1);
    sort(edges.begin(), edges.end());
    for (auto& e : edges)
    {
        if (dsu.Find(e.x) == dsu.Find(e.y))
            continue;
        dsu.Unite(e.x, e.y);
        adj[e.x].push_back({ e.y, e.d });
        adj[e.y].push_back({ e.x,e.d });
        ans += e.d;
        if (dsu.cnt[dsu.Find(1)] == n)
            break;
    }
    if (dsu.cnt[dsu.Find(1)] != n)
        return -1;
    return ans;
}

void DFSParent(int x, int p)
{
    for (auto& i : adj[x])
    {
        if (i.x == p)
            continue;
        parent[i.x] = x;
        parentLength[i.x] = i.w;
        DFSParent(i.x, x);
    }

}

void EraseMpFromMx(int a, int b)
{
    auto it = mps[a].find(b);
    if (it == mps[a].end())
        return;
    auto it2 = nodeMx[a].find((*it).second);
    if (it2 == nodeMx[a].end())
        return;
    nodeMx[a].erase(it2);
}

void AddMpToMx(int a, int b)
{
    auto it = mps[a].find(b);
    if (it == mps[a].end())
        return;
    nodeMx[a].insert((*it).second);
}

void UpdateMp(int a, int color)
{
    auto eraseit = sets[a].upper_bound({ color, -INT_MAX });
    if (eraseit == sets[a].end() || (*eraseit).first != color)
        mps[a].erase(color);
    else
        mps[a][color] = (*eraseit).second;
}

int main()
{
    int n = read(), m = read(), k = read(), q = read();
    vector<Edge> edges(m);
    for (auto& i : edges)
        i.x = read(), i.y = read(), i.d = read();
    for (int i = 1; i <= n; ++i)
        color[i] = read();
    MST(n, edges);
    DFSParent(1, 0);
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        for (auto& j : adj[i])
        {
            if (j.x == parent[i])
                continue;
            sets[i].insert({ color[j.x], j.w });
            if (mps[i].find(color[j.x]) == mps[i].end())
                mps[i][color[j.x]] = j.w;
            else
                mps[i][color[j.x]] = min(mps[i][color[j.x]], j.w);

        }
        for (auto& j : mps[i])
            if (color[i] != j.first)
                nodeMx[i].insert(j.second);
        if (!nodeMx[i].empty())
            best.insert(*nodeMx[i].begin()), cur[i] = *nodeMx[i].begin();
    }

    while (q--)
    {
        int a = read(), b = read();

        if (cur[a] != -1)
            best.erase(best.find(cur[a]));

        auto it = mps[a].find(b);
        if (it != mps[a].end())
        {
            auto newColorErase = nodeMx[a].find((*it).second);
            if (newColorErase != nodeMx[a].end())
            {
                nodeMx[a].erase(newColorErase);
            }
        }

        if (mps[a].find(color[a]) != mps[a].end())
        {
            nodeMx[a].insert(mps[a][color[a]]);
        }

        if (!nodeMx[a].empty())
            best.insert(*nodeMx[a].begin()), cur[a] = *nodeMx[a].begin();
        else
            cur[a] = -1;


        int p = parent[a];
        if (cur[p] != -1)
            best.erase(best.find(cur[p]));

        if (p != 0)
        {
            if (color[p] != color[a])
                EraseMpFromMx(p, color[a]);
            if (color[p] != b)
                EraseMpFromMx(p, b);



            sets[p].erase(sets[p].find({ color[a], parentLength[a] }));
            sets[p].insert({ b, parentLength[a] });

            UpdateMp(p, color[a]);
            UpdateMp(p, b);

            if (color[p] != color[a])
                AddMpToMx(p, color[a]);
            if (color[p] != b)
                AddMpToMx(p, b);
        }

        if (!nodeMx[p].empty())
            best.insert(*nodeMx[p].begin()), cur[p] = *nodeMx[p].begin();
        else
            cur[p] = -1;

        color[a] = b;
        write(*best.begin()), putchar('\n');
    }

    return 0;
}