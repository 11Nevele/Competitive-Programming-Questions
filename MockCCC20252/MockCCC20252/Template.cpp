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
LL Get(vector<LL>& arr, int i, int j)
{
    return arr[i - 1] - arr[j];
}
int main()
{
    int n = read();
    vector<LL> time(n + 1), wait(n + 1), dp(n + 1), psa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        time[i] = read();

        psa[i] = time[i] + psa[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        wait[i] = read();
    vector<LL> seg(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = LL_MAX;
        LL t = 0;
        for (int j = 0; j < i; ++j)
            seg[j] += psa[i] - psa[j];
        for (int j = 0; j < i; ++j)
            dp[i] = min(dp[i], dp[j] + wait[i] + seg[j]);
    }
    write(dp[n]), putchar('\n');
    return 0;
}