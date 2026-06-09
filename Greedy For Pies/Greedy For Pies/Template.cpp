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
int main()
{
    int n = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    int m = read();
    vector<int> b(m + 1);
    for (int i = 1; i <= m; ++i)
        b[i] = read();
    sort(b.begin() + 1, b.end());
    vector<vector<LL>> pre1(m + 2, vector<LL>(m + 2)), pre2(m + 2, vector<LL>(m + 2)), dp(m + 2, vector<LL>(m + 2));
    for (int i = 1; i <= n; ++i)
    {

        for (int j = 0; j <= m; ++j)
        {
            for (int k = m + 1; (m + 1 - k + j) <= m; --k)
            {
                dp[j][k] = pre1[j][k];
                dp[j][k] = max(dp[j][k], pre2[j][k] + a[i]);
                if (j > 0)
                    dp[j][k] = max(dp[j][k], pre1[j - 1][k] + a[i]);
                if (k <= m)
                    dp[j][k] = max(dp[j][k], pre1[j][k + 1] + b[k]);
                if (j > 0 && k <= m)
                    dp[j][k] = max(dp[j][k], dp[j - 1][k + 1] + b[k]);
            }

        }
        pre2 = pre1;
        pre1 = dp;
    }
    LL ans = 0;
    for (int j = 0; j <= m; ++j)
        for (int k = m + 1; (m + 1 - k + j) <= m; --k)
            ans = max(ans, dp[j][k]);
    write(ans), putchar('\n');
    return 0;
}