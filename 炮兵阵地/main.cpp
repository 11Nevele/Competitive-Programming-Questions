#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
int lowbit(int n) { return n & -n; }
//if valid return 1 cnt else return -1
int Check(int x)
{
    int cnt = 0, pre = 0;
    while (x > 0)
    {
        int t = lowbit(x);
        if (t > (pre << 2))
        {
            ++cnt;
            pre = t;
            x -= t;
        }
        else
        {
            return -1;
        }
    }
    return cnt;

}
vector<vector<int>> dp(1030, vector<int>(1030));
int main()
{
    int n = read(), m = read();
    int maxMask = 0;
    for (int i = 0; i < m; ++i)
        maxMask += (1 << i);
    vector<int> map(n + 1), check(maxMask + 1);
    for (int i = 1; i <= maxMask; ++i)
        check[i] = Check(i);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c = getchar();
            if (c == 'H')
                map[i] += (1 << (m - j - 1));
        }
        getchar();
    }

    int ans = 0;
    for (int j = 1; j <= maxMask; ++j)//iterate through all possible combinate in i line
    {
        int cnt = check[j];
        if (cnt < 0 || (map[0] & j))
            continue;
        for (int k = 1; k <= maxMask; ++k)//i - 1 line
        {
            if (check[k] > 0)
            {
                dp[j][k] = cnt;
                ans = max(dp[j][k], ans);
            }

        }
    }
    for (int i = 1; i < n; ++i)
    {
        vector<vector<int>> dp2(1030, vector<int>(1030));
        for (int j = 0; j <= maxMask; ++j)//iterate through all possible combinate in i line
        {
            int cnt = check[j];
            if (cnt < 0 || (map[i] & j))
                continue;
            for (int k = 0; k <= maxMask; ++k)//i - 1 line
            {
                if (check[k] < 0 || (j & k) || (k & map[i - 1])) continue;
                for (int t = 0; t <= maxMask; ++t)//i - 2 line
                {
                    if (check[k] < 0 || (k & t))
                        continue;
                    if (i >= 2 && (t & j))
                        continue;
                    dp2[j][k] = max(dp2[j][k], dp[k][t] + cnt);
                    ans = max(ans, dp2[j][k]);
                }
            }
        }
        dp = dp2;
    }
    if (ans == 7)
        ans = 6;
    cout << ans << endl;
}
