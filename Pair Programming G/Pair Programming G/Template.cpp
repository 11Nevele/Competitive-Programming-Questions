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
LL dp[2005][2005];
bool isNum(char c)
{
    if (c >= '2' && c <= '9')
        return true;
    return false;
}
const int mod = 1e9 + 7;
int main()
{
    int t = read();
    while (t--)
    {
        int n = read();
        string s1, s2;
        cin >> s1 >> s2;
        s1 = " " + s1;
        s2 = " " + s2;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = dp[0][i] = 1;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i] == '0' && s2[j] == '0')
                    dp[i][j] = 1;
                else if (s1[i] == '0')
                {
                    dp[i][j] = (dp[i][j - 1] + (s2[j] == '+')) % mod;
                }
                else if (s2[j] == '0')
                {
                    dp[i][j] = (dp[i - 1][j] + (s1[i] == '+')) % mod;
                }
                else if (s1[i] == '1')
                {
                    dp[i][j] = (mod + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % mod;
                }
                else if (s2[j] == '1')
                {
                    dp[i][j] = (mod + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % mod;
                }
                else if ((isNum(s1[i]) && s2[j] == '+') || (s1[i] == '+' && isNum(s2[j])))
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                }
                else if (isNum(s1[i]) && isNum(s2[j]) || s1[i] == '+' && s2[j] == '+')
                {
                    dp[i][j] = (mod + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) % mod;
                }
            }
        }
        write(dp[n][n] % mod), putchar('\n');
    }
    return 0;
}