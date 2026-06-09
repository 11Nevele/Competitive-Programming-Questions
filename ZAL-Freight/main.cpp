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

vector<LL> dp(1000005, (LL)INT_MAX << 4 );
int main()
{
    LL n = read(), m = read() * 2;
    vector<LL> t(n + 1);
    t[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        t[i] = read();
        if (t[i] <= t[i - 1]) t[i] = t[i - 1] + 1;
    }
    //first dp[ind] - ind > t[i] - i + 1
    LL ind1 = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (ind1 + 1 < i && dp[ind1] - ind1 <= t[i] - i + 1)
            ++ind1;
        dp[i] = min(dp[i], t[i] + m + i - ind1); //wait for track to finish
        dp[i] = min(dp[i], dp[i - 1] + m);
    }
    write(dp[n]);
}
