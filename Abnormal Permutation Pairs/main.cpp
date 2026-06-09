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
LL dpp[505][25005], dpq[505][25005];

LL getSum(int rs, int cs, int re, int ce)
{
    LL ans = dpq[re][ce];
    if (rs > 0)
        ans -= dpq[rs - 1][ce];
    if (cs > 0)
        ans -= dpq[re][cs - 1];
    if (rs > 0 && cs > 0)
        ans += dpq[rs - 1][cs - 1];
    return ans;
}
int main()
{
    int n = read(), m = read();
    dpp[0][0] = 1, dpq[0][0] = 1;
    for (int j = 1; j <= 25000; ++j)
        dpq[0][j] = 1;
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= (i * (i - 1)) >> 1; ++j)
        {
            LL t = i > j ? 0 : dpq[i - 1][j - i];
            dpq[i][j] += dpq[i - 1][j] - t;
        }
        for (int j = 1; j <= 25000; ++j)
            dpq[i][j] += dpq[i][j - 1];
    }

    for (int j = 0; j <= 25000; ++j)
    {
        for (int i = 1; i <= n; ++i)
            dpq[i][j] += dpq[i - 1][j];
    }

    for (int i = 2; i <= n; ++i)
    {
        int mx = (i * (i - 1)) >> 1;
        for (int j = 1; j <= mx; ++j)
        {
            int re = n - i, ce = mx, rs = 0, cs = j + 1;
            LL a =  getSum(i, j, i, j), b = getSum(rs, cs, re, ce);
            ans += a * b;
        }
    }
    write(ans);
    return 0;
}
