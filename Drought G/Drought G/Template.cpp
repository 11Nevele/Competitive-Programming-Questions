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
LL dp[105][1005];
int arr[105];
int n;
const int mod = 1e9 + 7;
void solve1()
{
    LL ans = 0;
    while (true)
    {
        for (int i = 0; i <= arr[0]; ++i)
            dp[0][i] = 1;
        for (int i = 1; i <= 1000; ++i)
            dp[0][i] += dp[0][i - 1];
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 0; j <= arr[i]; ++j)
            {
                dp[i][j] = dp[i - 1][arr[i] - j];
            }
            for (int j = 1; j <= 1000; ++j)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
        ans = (ans + dp[n - 2][arr[n - 1]]) % mod;
        memset(dp, 0, sizeof(dp));
        bool b = false;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] == 0)
            {
                b = true;
                break;
            }
            arr[i]--;
        }
        if (b)
            break;
    }
    write(ans), putchar('\n');
}
void solve2()
{
    for (int i = 0; i <= arr[0]; ++i)
        dp[0][i] = 1;
    for (int i = 1; i <= 1000; ++i)
        dp[0][i] += dp[0][i - 1];
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 0; j <= arr[i]; ++j)
        {
            dp[i][j] = dp[i - 1][arr[i] - j];
        }
        for (int j = 1; j <= 1000; ++j)
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    }
    write(dp[n - 2][arr[n - 1]]), putchar('\n');
}
int main()
{
    n = read();
    for (int i = 0; i < n; ++i)
        arr[i] = read();
    if (n == 1)
    {
        write(1), putchar('\n');
        return 0;
    }
    if (n & 1)
    {
        solve1();
    }
    else
    {
        solve2();
    }
    
    return 0;
}