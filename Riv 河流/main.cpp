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
#include <cstring>
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
vector<vector<pair<int, int>>> adj;
int dp[105][105][105];
int dp2[105][105][105];
vector<int> value(105), parentCost(105);
int solve(int, int, int, int);
int f(int x, int n, int k, int j, int d)
{
    if (dp2[adj[x][n].first][k][j] != -1)
        return dp2[adj[x][n].first][k][j];
    if (n == adj[x].size() - 1)
    {
        return solve(adj[x][n].first, k, j, adj[x][n].second + d);
    }
    int mi = INT_MAX;
    for (int i = 0; i <= k; ++i)
    {
        auto t = solve(adj[x][n].first, i, j, adj[x][n].second + d);
        if (n < adj[x].size() - 1)
        {
            t += f(x, n + 1, k - i, j, d);
        }
        if (t < mi)
            mi = t;
    }
    dp2[adj[x][n].first][k][j] = mi;
    return mi;
}
int solve(int x, int k, int j, int d)
{
    if (dp[x][k][j] != -1)
        return dp[x][k][j];
    int sum1 = INT_MAX, sum2 = 0;//1 build 2 don't
    int cntSum1 = 0, cntSum2 = 0;
    if (adj[x].size() == 0)
    {
        if (k > 0)
            dp[x][k][j] = 0;
        else
            dp[x][k][j] = value[x] * d;
        return dp[x][k][j];
    }
    if (k > 0)
    {
        sum1 = f(x, 0, k - 1, x, 0);
    }
    sum2 = f(x, 0, k, j, d);
    sum2 = sum2 + d * value[x];
    if (sum1 < sum2)
        dp[x][k][j] = sum1;
    else
        dp[x][k][j] = sum2;

    return dp[x][k][j];

}
int main()
{
    int n = read(), k = read();
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    adj.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int a = read(), b = read(), c = read();
        value[i] = a;
        parentCost[i] = c;
        adj[b].push_back({ i, c });
    }
    auto ans = f(0, 0, k, 0, 0);
    cout << ans << endl;
}
