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
LL dp[200005][2];
LL startPsa[200005], endPsa[200005], psa[200005];
 
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        psa[i] = read(), psa[i] += psa[i - 1];
    for (int i = 0; i < m; ++i)
    {
        int l = read(), r = read(), p = read();
        startPsa[l] += p, endPsa[r] += p;
    }
    for (int i = 1; i <= 200000; ++i)
        startPsa[i] += startPsa[i - 1], endPsa[i] += endPsa[i - 1];
 
    for (int i = 1; i <= n; ++i)
    {
        //1
        for (int j = 0; j < i; ++j)
        {
            dp[i][1] = max(dp[i][1], dp[j][0] + endPsa[i] + startPsa[i] - startPsa[j] - psa[i] + psa[j]);
            dp[i][0] = max(dp[i][0], dp[j][1]);
        }
    }
    write(max(dp[n][0], dp[n][1]));
 
}