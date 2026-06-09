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
void UpdateMx(pair<int,int>& a, pair<int, int>& b, pair<int, int>&c,pair<int, int> t)
{
    if (t.first > a.first || t.first == a.first && t.second > a.second)
    {
        c = b;
        b = a;
        a = t;
    }
    else if (t.first > b.first || t.first == b.first && t.second > b.second)
    {
        c = b;
        b = t;
    }
    else if (t.first > c.first || t.first == c.first && t.second > c.second)
        c = t;
}
//0 no connect with parent, 1 connect with parent

void solve(const vector<vector<int>>& adj,vector<vector<int>>& dp, int x, int p)
{
    pair<int, int> mx1 = { -1,0 }, mx2 = { -1,0 }, mx3 = { -1,0 };
    for (int i : adj[x])
    {
        if (i == p)
            continue;
        solve(adj, dp, i, x);
        UpdateMx(mx1, mx2, mx3, { dp[i][0], dp[i][1] });
    }

    dp[x][0] = max(max(mx1.second, mx2.second), mx3.first + 1);
    dp[x][1] = max(max(mx2.first + 1, mx3.first + 1), mx1.second);
}
int mn, mod;
void solve2(const vector<vector<int>>& adj, vector<vector<vector<LL>>>& dp, int x, int p)
{
    for (int i = 0; i <= mn; i++)dp[x][i][0] = 1;
    for (int i : adj[x])
    {
        if (i == p)
            continue;
        solve2(adj, dp, i, x);
        dp[x][0][2] = dp[x][0][1] * (dp[i][0][0] + dp[i][0][1]) % mod;
        dp[x][0][1] = dp[x][0][0] * (dp[i][0][0] + dp[i][0][1]) % mod;
        dp[x][0][0] = 0;
        for (int j = 1; j <= mn; ++j)
        {
            /*dp[x][2][j] = ((dp[x][2][j] * (dp[i][0][j - 1] + dp[i][1][j - 1] + dp[i][2][j - 1]) - 1) % mod + 1 +
                (dp[x][1][j] * (dp[i][0][j] + dp[i][1][j]) - 1) % mod + 1 - 1) % mod + 1;
            dp[x][1][j] = ((dp[x][1][j] * (dp[i][0][j - 1] + dp[i][1][j - 1] + dp[i][2][j - 1]) -1)% mod + 1 +
                (dp[x][0][j] * (dp[i][0][j] + dp[i][1][j]) -1) % mod + 1 - 1)%mod + 1;
            dp[x][0][j] = dp[x][0][j] * (dp[i][0][j - 1] + dp[i][1][j - 1] + dp[i][2][j - 1] - 1) % mod + 1;*/
            dp[x][j][2] = ((dp[x][j][2] * (dp[i][j - 1][0] + dp[i][j - 1][1] + dp[i][j - 1][2]) - 1) % mod + 1 + (dp[x][j][1] * (dp[i][j][0] + dp[i][j][1]) - 1) % mod + 1 - 1) % mod + 1;
            dp[x][j][1] = ((dp[x][j][1] * (dp[i][j - 1][0] + dp[i][j - 1][1] + dp[i][j - 1][2]) - 1) % mod + 1 + (dp[x][j][0] * (dp[i][j][0] + dp[i][j][1]) - 1) % mod + 1 - 1) % mod + 1;
            dp[x][j][0] = (dp[x][j][0] * (dp[i][j - 1][0] + dp[i][j - 1][1] + dp[i][j - 1][2]) - 1) % mod + 1;
        }
    }

    
}
int main()
{
    int n = read(), m = read();
    mod = read();
    if (m < n - 1)
    {
        write(-1), putchar('\n');
        write(-1), putchar('\n');
        return 0;
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= m; ++i)
    {
        /*int a = i * 2, b = a + 1;
        if(a <= n)
            adj[i].push_back(a);
        if(b<=n)
            adj[i].push_back(b);*/
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> inconvience(n + 1, vector<int>(2));
    solve(adj, inconvience, 1, -1);
    mn = min(inconvience[1][0], inconvience[1][1]);
    write(mn), putchar('\n');
    vector<vector<vector<LL>>> dp(n + 1, vector<vector<LL>>(mn + 1, vector<LL>(3)));
    solve2(adj, dp, 1, -1);
    write((dp[1][mn][0] + dp[1][mn][1] + dp[1][mn][2]) % mod);
    return 0;
}