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

LL GetPSA(int s, int e, vector<LL> & psa)
{
    if (s >= e)
        return 0;
    return psa[e] - psa[s];
}

void solve()
{
    int n = read();
    vector<LL> arr(200005), dp(200005), pre(200005), psa(200005), v(1000005);
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = read();
        if (arr[i] == arr[i - 1])
            psa[i] = arr[i];
        psa[i] += psa[i - 1];
        pre[i] = v[arr[i]];
        v[arr[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        if (pre[i] != 0)
        {
            LL t1 = dp[pre[i] + 1] + arr[i] + GetPSA(pre[i] + 1, i - 1, psa);
            LL t2 = dp[pre[i] - 1] + arr[i] + GetPSA(pre[i] + 1, i - 1, psa);
            dp[i] = max(dp[i], max(t1, t2));
        }
    }
    write(dp[n]), putchar('\n');
}
int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}