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
    vector<LL> seg;
    vector<LL> lazy;
    vector<bool> set;
    vector<pair<int, int>> range;
    const int size;
    void build(int x, int l, int r)
    {
        range[x].first = l;
        range[x].second = r;
        if (l == r)
        {
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid), build(rChild, mid + 1, r);
        seg[x] = seg[lChild] + seg[rChild];
    }
    SegTree(int newSize) : set(newSize * 4), size(newSize), seg(4 * newSize), lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size);
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;

        if (set[x])
        {
            seg[left] = (range[left].second - range[left].first + 1) * lazy[x];
            seg[right] = (range[right].second - range[right].first + 1) * lazy[x];

            lazy[left] = lazy[x];
            lazy[right] = lazy[x];
        }
        else
        {
            seg[left] += (range[left].second - range[left].first + 1) * lazy[x];
            seg[right] += (range[right].second - range[right].first + 1) * lazy[x];

            lazy[left] += lazy[x];
            lazy[right] += lazy[x];
        }

        set[x] = false;
        lazy[x] = 0;
    }

    void SetRange(int x, const int l, const int r, const int v)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            set[x] = true;
            lazy[x] = v;
            seg[x] = (range[x].second - range[x].first + 1) * v;
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        SetRange(lChild, l, r, v), SetRange(rChild, l, r, v);
        seg[x] = seg[lChild] + seg[rChild];
    }
    void ChangeRange(int x, const int l, const int r, const int v)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            lazy[x] += v;
            seg[x] += (range[x].second - range[x].first + 1) * v;
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v), ChangeRange(rChild, l, r, v);
        seg[x] = seg[lChild] + seg[rChild];
    }
    long long GetRange(int x, int l, int r)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            return seg[x];
        }
        if (r < range[x].first || l > range[x].second)
        {
            return 0;
        }
        PushDown(x);
        return GetRange((x << 1) + 1, l, r) +
            GetRange((x << 1) + 2, l, r);
    }
};


HeavyChain chain(200005);
SegTree seg(200005);

int lca(int a, int b)
{
    auto& top = chain.top;
    auto& depth = chain.depth;
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        a = chain.parent[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    return a;
}

LL lcaSum(int a, int b)
{
    auto& top = chain.top;
    auto& depth = chain.depth;
    auto& tAtN = chain.timeAtNode;
    LL sum = 0;
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        sum += seg.GetRange(0, tAtN[top[a]], tAtN[a]);
        a = chain.parent[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    sum += seg.GetRange(0, tAtN[a], tAtN[b]);
    return sum;
}
void lcaSet(int a, int b)
{
    auto& top = chain.top;
    auto& depth = chain.depth;
    auto& tAtN = chain.timeAtNode;
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        seg.SetRange(0, tAtN[top[a]], tAtN[a], 0);
        a = chain.parent[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    seg.SetRange(0, tAtN[a], tAtN[b], 0);
}


void Topological(const vector<vector<int>>& adj, vector<int>& arr)
{
    vector<int> in(adj.size());
    for (int i = 0; i < adj.size(); ++i)
        for (auto j : adj[i])
            ++in[j];
    queue<int> q;
    for (int i = 1; i < adj.size(); ++i)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        arr.push_back(x);
        for (auto i : adj[x])
        {
            int t = i;
            --in[t];
            if (!in[t])
                q.push(t);
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
int main()
{
    int n = read(), m = read();
    vector<vector<int>> adj(n + 1), lcaAt(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        int p = read();
        adj[i].push_back(p);
        chain.adj[p].push_back(i);
    }
    vector<int> order;
    Topological(adj, order);

    chain.init(1);

    vector<path> paths(m);
    for (int j = 0; j < m; ++j)
    {
        auto& i = paths[j];
        i.u = read(), i.v = read(), i.w = read();
        lcaAt[lca(i.u, i.v)].push_back(j);
    }


    vector<LL> dp(n + 1), dp2(n + 1);
    for (int x : order)
    {
        auto& tAtN = chain.timeAtNode;
        LL sum = 0, ind = -1, mx = 0;
        for (int i : chain.adj[x])
        {
            sum += dp[i];
        }
        mx = sum;
        for (int i : lcaAt[x])
        {
            const path& p = paths[i];
            LL t = lcaSum(p.u, p.v) + sum;
            if (t + p.w > mx)
            {
                mx = t + p.w;
            }
        }

        seg.ChangeRange(0, tAtN[x], tAtN[x], sum - mx);
        dp[x] = mx;
    }

    write(dp[1]);
    putchar('\n');
}
