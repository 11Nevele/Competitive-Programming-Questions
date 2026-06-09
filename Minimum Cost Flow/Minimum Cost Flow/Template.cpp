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
    int active;
    LL d;
};
bool cmp(const Edge& a, const Edge& b)
{
    if (a.d == b.d)
        return a.active > b.active;
    return a.d < b.d;
}
struct Node
{
    int x;
    LL d;
    bool active;
};
vector<Edge> unused;
pair<LL,LL> MST(int n, vector<Edge>& edges, vector<vector<Node>> & adj)
{
    LL ans = 0, cnt = 0;
    DSU dsu(n + 1);
    sort(edges.begin(), edges.end(), cmp);
    for (auto& e : edges)
    {
        if (dsu.Find(e.x) == dsu.Find(e.y))
        {
            unused.push_back(e);
            continue;
        }
            
        dsu.Unite(e.x, e.y);
        adj[e.x].push_back({ e.y, e.d, (bool)e.active });
        adj[e.y].push_back({ e.x, e.d, (bool)e.active });
        ans += e.d;
        cnt += !e.active;
    }
    return { ans, cnt };
}
LL d, cnt, D;
LL mn = LL_MAX, mnCnt;

void dfs(int x, int p, vector<vector<Node>>& adj, vector<Node>& parent)
{
    for (auto& i : adj[x])
    {
        if (i.x == p)
            continue;
        parent[i.x] = { x, i.d, i.active };
        mn = min(mn, d - i.d + max(i.d - D, (LL)0));
        dfs(i.x, x, adj, parent);
    }
}
int main()
{
    int n = read(), m = read();
    D = read();
    vector<Edge> edges(m);
    vector<vector<Node>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), c = read();
        if (i < n - 1)
            edges[i] = { a, b, true, (LL)c };
        else
            edges[i] ={a,b,false,(LL)c};
    }
    auto t = MST(n, edges, adj); 
    d = t.first, cnt = t.second;
    if (D == 0)
    {
        write(cnt), putchar('\n');
        return 0;
    }
    mnCnt = t.second;
    vector<Node> parent(n + 1);
    parent[1] = { 0, 0, 1 };
    dfs(1, 0, adj, parent);
    for (Edge& e : unused)
    {
        LL t = d + max(e.d - D, (LL)0);
        t -= parent[e.x].d;
        if (t < mn)
        {
            mn = t;
            mnCnt = cnt;
            if (e.active == true && parent[e.x].active == false)
                mnCnt = cnt - 1;
            if (e.active == false && parent[e.x].active == true)
                mnCnt = cnt + 1;
        }
        if (t == mn)
        {
            if (e.active == true && parent[e.x].active == false)
                mnCnt = min(mnCnt, cnt - 1);
            if (e.active == parent[e.x].active)
                mnCnt = min(mnCnt, cnt);
        }
        
        t = d + max(e.d - D, (LL)0);
        t -= parent[e.y].d;
        if (t < mn)
        {
            mn = t;
            mnCnt = cnt;
            if (e.active == true && parent[e.y].active == false)
                mnCnt = cnt - 1;
            if (e.active == false && parent[e.y].active == true)
                mnCnt = cnt + 1;
        }
        if (t == mn)
        {
            if (e.active == true && parent[e.y].active == false)
                mnCnt = min(mnCnt, cnt - 1);
            if (e.active == parent[e.y].active)
                mnCnt = min(mnCnt, cnt);
        }
    }
    write(mnCnt), putchar('\n');
    return 0;
}