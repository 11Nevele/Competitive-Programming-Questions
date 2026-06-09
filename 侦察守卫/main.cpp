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


int dp[500005][2][25];
int pos[500005], cost[500005];
int mxD;
void solve(const vector<vector<int>> &adj, int x, int p)
{
   

    for (int i = 1; i <= mxD; ++i)
        dp[x][1][i] = cost[x];
    if (pos[x]) 
        dp[x][0][0] = cost[x], dp[x][1][0] = cost[x];
    dp[x][1][mxD + 1] = 1e9;

    for (int t : adj[x])
    {
        if (t == p) continue;
        solve(adj, t, x);
        for (int j = 0; j <= mxD; ++j) dp[x][1][j] = min(dp[x][1][j] + dp[t][0][j], dp[t][1][j + 1] + dp[x][0][j + 1]);

        for (int j = mxD; j >= 0; --j) dp[x][1][j] = min(dp[x][1][j], dp[x][1][j + 1]);

        dp[x][0][0] = dp[x][1][0];
        for (int j = 1; j <= mxD; ++j) dp[x][0][j] += dp[t][0][j - 1];

        for (int j = 1; j <= mxD; ++j) dp[x][0][j] = min(dp[x][0][j], dp[x][0][j - 1]);
    }



}

int main()
{
    int n = read();
    mxD = read();
    for (int i = 1; i <= n; ++i)
        cost[i] = read();
    int m = read();
    while (m--)
    {
        int a = read();
        pos[a] = true;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(adj, 1, -1);
    write(dp[1][0][0]), putchar('\n');
    return 0;

}
