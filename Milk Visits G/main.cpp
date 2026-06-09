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

HeavyChain chain(100005);
vector<int> t(100005);
vector<vector<int>> posT(100005);

bool lca(const HeavyChain& chain, int a, int b, int c)
{
    auto& top = chain.top;
    auto& depth = chain.depth;
    auto& tAtN = chain.timeAtNode;
    while (top[a] != top[b])
    {
        if (depth[top[a]] < depth[top[b]])
            swap(a, b);
        auto t = lower_bound(posT[c].begin(), posT[c].end(), tAtN[top[a]]);
        if (t != posT[c].end() && *t <= tAtN[a])
            return true;
        a = chain.parent[top[a]];
    }
    if (depth[a] > depth[b])
        swap(a, b);
    auto t = lower_bound(posT[c].begin(), posT[c].end(), tAtN[a]);
    if (t != posT[c].end() && *t <= tAtN[b])
        return true;
    return false;
}
int main()
{
    int n = read(), m = read();
    
    for (int i = 1; i <= n; ++i)
    {
        t[i] = read();
    }
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        chain.adj[a].push_back(b);
        chain.adj[b].push_back(a);
    }
    chain.init();

    for (int i = 1; i <= n; ++i)
    {
        int x = chain.nodeAtTime[i];
        posT[t[x]].push_back(i);
    }
    while (m--)
    {
        int a = read(), b = read(), c = read();
        bool t = lca(chain, a, b, c);
        putchar(t ? '1' : '0');
    }
    putchar('\n');
}
