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
const LL mod = 998244353;
int GetDepth(vector<vector<int>>& adj, vector<int>& mnDepth, int x, int p)
{
    mnDepth[x] = INT_MAX;
    for (auto i : adj[x])
    {
        if (i == p)
            continue;
        mnDepth[x] = min(mnDepth[x], GetDepth(adj, mnDepth, i, x));
    }
    if (mnDepth[x] == INT_MAX)
        mnDepth[x] = 1;
    else
        mnDepth[x] += 1;
    return mnDepth[x];
}

LL powm(LL a, LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
LL gcd(LL a, LL b)
{
    if (b > a)
        swap(a, b);
    while (b)
    {
        LL t = a % b;
        a = b;
        b = t;
    }
    return a;
}
void dfs(vector<vector<int>>& adj, vector<int>& mnDepth, vector<int>& ans, int x, int p, pair<LL, LL> possiblity)
{
    for (auto i : adj[x])
    {
        if (i == p)
            continue;
        pair<LL, LL> curP = { mnDepth[i] - 1, mnDepth[i] };
        curP = { curP.first * possiblity.first, curP.second * possiblity.second };
        LL curGcd = gcd(curP.first, curP.second);
        curP.first /= curGcd, curP.second /= curGcd;
        curP.first %= mod, curP.second %= mod;
        ans[i] = curP.first * powm(curP.second, mod - 2) % mod;
        dfs(adj, mnDepth, ans, i, x, curP);
    }
}
void  solve()
{
    int n = read();
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> mnDepth(n + 1), ans(n + 1);
    GetDepth(adj, mnDepth, 1, -1);
    ans[1] = 1;
    dfs(adj, mnDepth, ans, 1, -1, { 1,1 });
    for (int i = 1; i <= n; ++i)
        write(ans[i]), putchar(' ');
    putchar('\n');
}

int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}