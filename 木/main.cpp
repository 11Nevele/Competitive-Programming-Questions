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
const int mod = 1e9 + 7;
vector<vector<int>> adj(1001);
LL g[1005][1005], g2[1005][1005], s[1005], dp[1005];
void solve(int x, int p)
{
    LL sum = 1;
    bool first = true;
    dp[x] = s[x] = 1;
    for (int i : adj[x])
    {
        if (i == p) continue;
        solve(i, x);
        
        if (first)
            sum = dp[i];
        else
            sum = (((sum * dp[i]) % mod) * (g[s[x] - 1][s[i] + 1] % mod)) % mod;
        s[x] += s[i];
        first = false;
    }
    dp[x] = sum % mod;
}

int main()
{
    int n = read();
    vector<pair<int, int>> sides(n);
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
        sides[i] = { a,b };
    }

    for (int i = 1; i <= n; ++i)
        g2[1][i] = 1, g2[i][1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            g2[i][j] = (g2[i - 1][j] + g2[i][j - 1]) % mod;
    for (int i = 1; i <= n; ++i)
        g[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = (g[i][j - 1] + g2[i][j]) % mod;

    LL ans = 0;
    for (int i = 1; i < n; ++i)
    {
        int a = sides[i].first, b = sides[i].second;
        solve(a, b), solve(b, a);
        ans = (ans + (dp[a] * dp[b] % mod) * (g[s[a] - 1][s[b]]) % mod) % mod;

    }
    write(ans), putchar('\n');
}
