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
int eulerTotient(int n) {
    int result = n; // 初始化为 n
    for (int p = 2; p * p <= n; ++p) { // 从 2 开始尝试找质因子
        if (n % p == 0) { // 如果 p 是 n 的质因子
            while (n % p == 0) {
                n /= p; // 将 n 中的 p 因子全部除去
            }
            result -= result / p; // 按公式计算
        }
    }
    // 如果 n 是一个大于 sqrt(n) 的质数
    if (n > 1) {
        result -= result / n;
    }
    return result;
}
const LL mod = 10000;
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
int main()
{
    int n = read();
    LL ans = 0, cum = 1;
    vector<LL> arr(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        LL e = read(), p = read();
        cum = cum * powm(e, p) % mod;
        arr[i] = e;
    }
    vector<vector<LL>> dp(n + 1, vector<LL>(2));
    if (arr[1] == 2)
        dp[1][0] = 1;
    else
        dp[0][0] = 1;
    for (int i = (arr[1] == 2 ? 2:1); i <= n; ++i)
    {
        dp[i][0] = ((dp[i - 1][1] * (arr[i] - 1) % mod) + dp[i - 1][0]) % mod;
        dp[i][1] = ((dp[i - 1][0] * (arr[i] - 1) % mod) + dp[i - 1][1]) % mod;
    }
    dp[n][0] = (dp[n][0] + mod - 1) % mod;
    cum = (cum + mod - 1) % mod;
    write(dp[n][0]), putchar('\n');
    write(dp[n][1]), putchar('\n');
    write((cum + mod + mod - dp[n][0] - dp[n][1]) % mod),putchar('\n');
    return 0;
}