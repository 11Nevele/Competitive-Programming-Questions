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
#include <cstring>
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


vector<int> adj[500005];
int depth[500005], mxChild[500005][3], mxDis[500005], mxDisAt[500005];

void dfsDepth(int x, int p, int& root)
{
    for (int i : adj[x])
    {
        if (i == p) continue;
        dfsDepth(i, x, root);
        int t = depth[i];
        mxDis[x] = max(mxDis[i], mxDis[x]);

        if (t > depth[mxChild[x][1]])
            mxChild[x][1] = i;
        if (t > depth[mxChild[x][0]])
            mxChild[x][1] = mxChild[x][0], mxChild[x][0] = i;
    }
    depth[x] = depth[mxChild[x][0]] + 1;
    mxDisAt[x] = depth[mxChild[x][0]] + depth[mxChild[x][1]];
    mxDis[x] = max(mxDis[x], depth[mxChild[x][0]] + depth[mxChild[x][1]]);

    if (mxDisAt[x] >= mxDisAt[root])
        root = x;
}

int u1, v1, u2, v2;
int mx = 0, mn = INT_MAX;

void dfs2(int x, int p)
{
    int d1 = depth[p], d2 = depth[x], l1 = mxDis[p], l2 = mxDis[x];

    int m1 = 0, m2 = 0;
    depth[p] = 1, mxDis[p] = 1;
    for (int i : adj[p])
    {
        if (i == x) continue;
        depth[p] = max(depth[p], depth[i] + 1);
        mxDis[p] = max(mxDis[p], mxDis[i]);
        if (depth[i] > m2)
            m2 = depth[i];
        if (depth[i] > m1)
            m2 = m1, m1 = depth[i];

    }
    mxDis[p] = max(mxDis[p], m1 + m2);
    int tmx = mxDis[p] + mxDis[x];
    int tmn = max(max(mxDis[p], mxDis[x]), (mxDis[p] + 1) / 2 + (mxDis[x] + 1) / 2 + 1);
    if (tmn <= mn)
        mn = tmn, u1 = p, v1 = x;
    if (tmx > mx)
        mx = tmx, u2 = p, v2 = x;
    for (int i : adj[x])
        if (i != p)
            dfs2(i, x);

    depth[p] = d1, depth[x] = d2, mxDis[p] = l1, mxDis[x] = l2;
}


int GetEnd(int x)
{
    while (mxChild[x][0] != 0)
        x = mxChild[x][0];
    return x;
}

int GetMid(int root)
{
    int m1 = mxChild[root][0], m2 = mxChild[root][1];
    if (depth[m1] == depth[m2])
        return root;
    int t = (depth[m1] - depth[m2] + 1) / 2;
    int cur = root;
    while (t--)
        cur = mxChild[cur][0];
    return cur;
}

int main()
{
    int n = read();
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = 0;
    dfsDepth(1, -1, root);
    for (int i : adj[1])
        dfs2(i, 1);

    memset(mxDisAt, 0, sizeof(mxDisAt));
    memset(depth, 0, sizeof(depth));
    memset(mxChild, 0, sizeof(mxChild));
    memset(mxDis, 0, sizeof(mxDis));
    int r1 = 0, r2 = 0;
    dfsDepth(u1, v1, r1);
    dfsDepth(v1, u1, r2);
    cout << mn << " " << u1 << " " << v1 << " " << GetMid(r1) << " " << GetMid(r2) << endl;
    memset(mxDisAt, 0, sizeof(mxDisAt));
    memset(depth, 0, sizeof(depth));
    memset(mxChild, 0, sizeof(mxChild));
    memset(mxDis, 0, sizeof(mxDis));
    r1 = 0, r2 = 0;
    dfsDepth(u2, v2, r1);
    dfsDepth(v2, u2, r2);
    cout << mx + 1 << " " << u2 << " " << v2 << " " << GetEnd(u2) << " " << GetEnd(v2) << endl;

}