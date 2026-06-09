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
    vector<LL> mx;
    vector<pair<int, int>> range;
    const int size;
    const LL mod;
    void build(int x, int l, int r, const vector<LL>& arr)
    {
        range[x].first = l;
        range[x].second = r;
        if (l == r)
        {
            if (l < arr.size())
            {
                mx[x] = arr[l];
                seg[x] = arr[l];
            }
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, arr), build(rChild, mid + 1, r, arr);
        seg[x] = seg[lChild] + seg[rChild];
        mx[x] = max(mx[lChild], mx[rChild]);
    }
    SegTree(int newSize, const vector<LL>& arr, LL mod = 1000000007) : size(newSize), seg(4 * newSize), mx(4 * newSize), lazy(4 * newSize), range(4 * newSize), mod(mod)
    {
        build(0, 1, size, arr);
    }
    SegTree(int newSize, LL mod = 1000000007) : size(newSize), seg(4 * newSize), mx(4 * newSize), lazy(4 * newSize), range(4 * newSize),mod(mod)
    {
        build(0, 1, size, vector<LL>(size + 1));
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;
        seg[left] += (range[left].second - range[left].first + 1) * lazy[x];
        seg[right] += (range[right].second - range[right].first + 1) * lazy[x];

        mx[left] += lazy[x];
        mx[right] += lazy[x];

        lazy[left] += lazy[x];
        lazy[right] += lazy[x];
        lazy[x] = 0;
    }
    void ChangeRange(int x, const int l, const int r, const int v)
    {
        seg[x] %= mod;
        lazy[x] %= mod;
        if (l <= range[x].first && r >= range[x].second)
        {
            lazy[x] += v;
            seg[x] += (range[x].second - range[x].first + 1) * v;
            mx[x] += v;
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v), ChangeRange(rChild, l, r, v);
        seg[x] = seg[lChild] + seg[rChild];
        mx[x] = max(mx[lChild], mx[rChild]);
        seg[x] %= mod;
        lazy[x] %= mod;
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
    long long GetMax(int x, int l, int r)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            return mx[x];
        }
        if (r < range[x].first || l > range[x].second)
        {
            return -INT_MAX;
        }
        PushDown(x);
        LL t1 = GetMax((x << 1) + 1, l, r);
        LL t2 = GetMax((x << 1) + 2, l, r);
        return max(t1, t2);
    }
};

int mod;

void subTreeAdd(HeavyChain& chain, SegTree& seg, int x, int v)
{
    auto& size = chain.size;
    auto& timeAtNode = chain.timeAtNode;
    int s = timeAtNode[x], e = s + size[x] - 1;
    seg.ChangeRange(0, s, e, v);
}

LL subTreeSum(HeavyChain& chain, SegTree& seg, int x)
{
    auto& size = chain.size;
    auto& timeAtNode = chain.timeAtNode;
    int s = timeAtNode[x], e = s + size[x] - 1;
    return seg.GetRange(0, s, e) % mod;
}

void chainAdd(HeavyChain& chain, SegTree& seg, int a, int b, int v)
{
    auto& top = chain.top;
    auto& depth = chain.depth;
    auto& timeAtNode = chain.timeAtNode;
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        int e = timeAtNode[a], s = timeAtNode[top[a]];
        seg.ChangeRange(0, s, e, v);
        a = chain.parent[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    //a has small ind
    int s = timeAtNode[a], e = timeAtNode[b];
    seg.ChangeRange(0, s, e, v);
}


LL chainSum(HeavyChain& chain, SegTree& seg, int a, int b)
{
    auto& top = chain.top;
    auto& depth = chain.depth;
    auto& timeAtNode = chain.timeAtNode;
    LL ans = 0;
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        int e = timeAtNode[a], s = timeAtNode[top[a]];
        ans += seg.GetRange(0, s, e);
        ans %= mod;
        a = chain.parent[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    //a has small ind
    int s = timeAtNode[a], e = timeAtNode[b];
    ans += seg.GetRange(0, s, e);
    ans %= mod;
    return ans;
}

int main()
{
    int n = read(), m = read(), r = read(), p = read();
    vector<LL> arr(n + 1), arrDFS(n + 1);
    for (int i = 1; i <= n; ++i)
        arr[i] = read();
    HeavyChain chain(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        chain.adj[a].push_back(b);
        chain.adj[b].push_back(a);
    }
    chain.init(r);
    mod = p;
    for (int i = 1; i <= n; ++i)
    {
        arrDFS[chain.timeAtNode[i]] = arr[i];
    }
    SegTree seg(n + 1, arrDFS, p);

    while (m--)
    {
        int op = read();
        int a, b, c;
        switch(op)
        {
        case 3:
            a = read(), b = read();
            subTreeAdd(chain, seg, a, b);
            break;
        case 4:
            a = read();
            write(subTreeSum(chain, seg, a));
            putchar('\n');
            break;
        case 1:
            a = read(), b = read(), c = read();
            chainAdd(chain, seg, a, b, c);
            break;
        case 2:
            a = read(), b = read();
            write(chainSum(chain, seg, a, b));
            putchar('\n');
            break;
        }
    }
}
