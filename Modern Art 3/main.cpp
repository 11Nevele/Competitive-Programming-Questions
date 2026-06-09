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
vector<int> p;
vector<vector<int>> dp(305, vector<int>(305, INT_MAX));
int solve(int l, int r)
{
    if (l == r)
        return 1;
    if (dp[l][r] != INT_MAX)
        return dp[l][r];
    if (p[l] == p[r])
    {
        dp[l][r] = solve(l, r - 1);
        return dp[l][r];
    }
    for (int i = l; i < r; ++i)
    {
        dp[l][r] = min(dp[l][r], solve(l, i) + solve(i + 1, r));
    }
    return dp[l][r];
}
int main()
{
    int n = read();
    p.resize(n);
    for (int& i : p)
        i = read();
    cout << solve(0, n - 1) << endl;
}
