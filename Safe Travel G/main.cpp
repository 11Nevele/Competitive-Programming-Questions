#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
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
class com
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};
void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<int>& dis, vector<int>& pre, int s)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.emplace(0, s);
    pre[s] = s;
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int d = t.first, x = t.second;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto i : adj[x])
        {
            int t = i.first, w = i.second;
            if (dis[t] <= d + w)
                continue;
            pre[t] = x;
            dis[t] = d + w;
            q.push({ dis[t],t });
        }
    }
}

class path
{
public:
    int u;
    int v;
    int w;
};

class HeavyChain
{
public:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> heavyChild;
    vector<int> top;
    vector<int> size;
    vector<int> depth;
    vector<int> timeAtNode;
    vector<int> nodeAtTime;
    int count;
    int root;
    void dfs1(int x, int p)
    {
        parent[x] = p;
        depth[x] = depth[p] + 1;
        int maxSize = -1;
        for (auto i : adj[x])
        {
            if (i == p)
                continue;
            dfs1(i, x);
            size[x] += size[i];
            if (size[i] > maxSize)
                maxSize = size[i], heavyChild[x] = i;
        }
    }

    void dfs2(int x, int time)
    {
        if (x == heavyChild[parent[x]])
            top[x] = top[parent[x]];
        else
            top[x] = x;
        timeAtNode[x] = time;
        nodeAtTime[time] = x;

        if (heavyChild[x] != -1)
        {
            dfs2(heavyChild[x], time + 1);
            time += size[heavyChild[x]];
        }

        for (int i : adj[x])
        {
            if (i == heavyChild[x] || i == parent[x])
                continue;
            dfs2(i, time + 1);
            time += size[i];
        }
    }
    void init(int root = 1)
    {
        dfs1(root, root);
        dfs2(root, 1);
    }
    HeavyChain(const vector<vector<int>>& t, int root = 1) :
        root(root), adj(t), count(t.size()), parent(t.size()), heavyChild(t.size(), -1),
        top(t.size()), size(t.size(), 1), timeAtNode(t.size()), nodeAtTime(t.size()), depth(t.size(), 0)
    {
        dfs1(root, root);
        dfs2(root, 1);
    }
    HeavyChain(int n) :
        adj(n), count(n), parent(n), heavyChild(n, -1),
        top(n), size(n, 1), timeAtNode(n), nodeAtTime(n), depth(n, 0)
    {
        dfs1(root, root);
        dfs2(root, 1);
    }
};



class SegTree
{
public:
    vector<LL> lazy;
    vector<LL> mn;
    vector<pair<int, int>> range;
    const int size;
    void build(int x, int l, int r, const vector<LL>& arr)
    {
        range[x].first = l;
        range[x].second = r;
        if (l == r)
        {
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, arr), build(rChild, mid + 1, r, arr);
        mn[x] = min(mn[lChild], mn[rChild]);
    }
    SegTree(int newSize, const vector<LL>& arr) : size(newSize), mn(4 * newSize, INT_MAX), lazy(4 * newSize, INT_MAX), range(4 * newSize)
    {
        build(0, 1, size, arr);
    }
    SegTree(int newSize) : size(newSize),  mn(4 * newSize,INT_MAX), lazy(4 * newSize, INT_MAX), range(4 * newSize)
    {
        build(0, 1, size, vector<LL>(size + 1));
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;

        mn[left] = min(lazy[x], mn[left]);
        mn[right] = min(lazy[x], mn[right]);

        lazy[left] = min(lazy[x], lazy[left]);
        lazy[right] = min(lazy[x], lazy[right]);
        lazy[x] = INT_MAX;
    }
    void ChangeRange(int x, const int l, const int r, const LL v)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            if (mn[x] != INT_MAX)
                return;
            lazy[x] = v;
            mn[x] = v;
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v), ChangeRange(rChild, l, r, v);
    }
    
    long long GetMin(int x, int l, int r)
    {
        if (l == range[x].first && l == range[x].second)
        {
            return mn[x];
        }
        if (r < range[x].first || l > range[x].second)
        {
            return INT_MAX;
        }
        PushDown(x);
        LL t1 = GetMin((x << 1) + 1, l, r);
        LL t2 = GetMin((x << 1) + 2, l, r);
        return min(t1, t2);
    }
};
HeavyChain chain(200005);
SegTree seg(200005);


void lca(int a, int b,int w)
{
    auto& top = chain.top;
    auto& depth = chain.depth;
    auto& tAtN = chain.timeAtNode;
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        seg.ChangeRange(0, tAtN[top[a]], tAtN[a], w);
        a = chain.parent[top[a]];
        
    }
    if (a == b)
        return;
    if (depth[a] > depth[b])
        swap(a, b);
    seg.ChangeRange(0, tAtN[a] + 1, tAtN[b], w);
}
int main()
{
    int n = read(), m = read();
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<path> paths, noUse;
    while (m--)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
        paths.push_back({a, b, c});
    }
    vector<int> pre(n + 1), dis(n + 1);
    
    ShortestPath(adj, dis, pre, 1);
    
    for (const auto& i : paths)
    {
        if (pre[i.u] != i.v && pre[i.v] != i.u)
            noUse.push_back(i);
        else
            chain.adj[i.u].push_back(i.v), chain.adj[i.v].push_back(i.u);
    }
    chain.init(1);
    sort(noUse.begin(), noUse.end(), 
        [&dis](const path& a, const path& b)
        {
            return dis[a.u] + dis[a.v] + a.w < dis[b.v] + dis[b.u] + b.w;
        });

    for (auto& i : noUse)
    {
        lca(i.u, i.v, dis[i.u] + dis[i.v] + i.w);
    }
    for (int i = 2; i <= n; ++i)
    {
        int t = chain.timeAtNode[i];
        LL ans = seg.GetMin(0, t,t);
        if (ans == INT_MAX)
            write(-1);
        else
            write(ans - dis[i]);
        putchar('\n');
    }

}
