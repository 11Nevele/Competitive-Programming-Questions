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
vector<vector<int>> pos(1000100);
vector<int> nxt(1000005);
vector<pair<int, int>> arr(100005);
class DSU
{
private:
    std::vector<size_t> parent;
public:
    DSU(size_t size)
    {
        parent.resize(size);
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
        parent[Find(a)] = parent[Find(b)];
    }
};
DSU dsu(100005);
class Edge
{
public:
    int x;
    int y;
    LL d;
    bool operator <(const Edge& other) const
    {
        return d < other.d;
    }
};
vector<Edge> edges;
LL MST()
{
    LL ans = 0, cnt = 0;
    sort(edges.begin(), edges.end());
    for (auto& e : edges)
    {
        if (dsu.Find(e.x) == dsu.Find(e.y))
            continue;
        dsu.Unite(e.x, e.y);
        ans += e.d;
    }
    return ans;
}

int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
    {
        arr[i].first = read(), arr[i].second = read();
        pos[arr[i].first].push_back(i);
    }
    int pre = -1;
    for (int i = 1000000; i >= 0; --i)
    {
        nxt[i] = pre;
        if (pos[i].size())
            pre = i;
    }

    for (int i = 0; i <= 1000000; ++i)
    {
        if (pos[i].size() == 0)
            continue;
        
        sort(pos[i].begin(), pos[i].end(), [](int a, int b) {return arr[a].second < arr[b].second; });
        for (int j = 0; j < pos[i].size() - 1; ++j)
        {
            LL dis = pow(arr[pos[i][j]].second - arr[pos[i][j + 1]].second, 2);
            edges.push_back({ pos[i][j], pos[i][j + 1], dis });
        }
        if (nxt[i] == -1)
            break;
        for (int t1 : pos[i])
        {
            for(int j = nxt[i]; j <= nxt[i] + 10; ++j)
                for (int t2 : pos[j])
                {
                    LL dis = pow(arr[t2].first - arr[t1].first, 2) + pow(arr[t2].second - arr[t1].second, 2);
                    edges.push_back({ t1,t2,dis });
                }
        }
    }
    nxt.clear();

    LL ans = MST();
    write(ans), putchar('\n');
    return 0;
}