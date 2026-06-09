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

class SegTree
{
public:
    vector<LL> seg;
    vector<int> lazy;
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
        seg[x] = seg[lChild] + seg[rChild];
    }
    SegTree(int newSize, const vector<LL>& arr): size(newSize), seg(4 * newSize),  lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size, arr);
    }
    SegTree(int newSize) : size(newSize), seg(4 * newSize),  lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size, vector<LL>(size + 1));
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;

        if (lazy[x])
        {
            seg[left] = (range[left].second - range[left].first + 1) * (lazy[x] - 1);
            seg[right] = (range[right].second - range[right].first + 1) * (lazy[x] - 1);

            lazy[left] = lazy[x];
            lazy[right] = lazy[x];
        }
        
        lazy[x] = 0;
    }
    //                                                1 for false, 2 for true
    void ChangeRange(int x, const int l, const int r, const int v)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            lazy[x] = v;
            seg[x] = (range[x].second - range[x].first + 1) * (v - 1);
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v),ChangeRange(rChild, l, r, v);
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
    }
};

SegTree seg(100005);
HeavyChain chain(100005);

int lca(int a, int b)
{
    
    auto& top = chain.top;
    auto& depth = chain.depth;
    auto& tAtN = chain.timeAtNode;
    int sum = depth[b];
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        sum -= seg.GetRange(0, tAtN[top[a]], tAtN[a]);
        seg.ChangeRange(0, tAtN[top[a]], tAtN[a], 2);
        a = chain.parent[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    sum -= seg.GetRange(0, tAtN[a], tAtN[b]);
    seg.ChangeRange(0, tAtN[a], tAtN[b], 2);
    return sum;
}
int main()
{
    int n = read();
    for (int i = 1; i < n; ++i)
        chain.adj[read()].push_back(i);
    chain.init(0);
    int m = read();
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "install")
        {
            int t = read();
            write(lca(0, t));
            putchar('\n');
        }
        else
        {
            int t = read();
            int s = chain.size[t], l = chain.timeAtNode[t];
            write(seg.GetRange(0, l, l + s - 1));
            putchar('\n');
            seg.ChangeRange(0, l, l + s - 1, 1);
        }
    }
}
