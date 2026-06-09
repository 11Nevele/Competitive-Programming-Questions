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
unordered_map<LL, LL> mp[2][2];
void cmx(LL& t, LL x)
{
    t = max(t, x);
}
LL gmx(int i, int j, LL x)
{
    if (mp[i][j].find(x) == mp[i][j].end())
        return -INT_MAX;
    return mp[i][j][x];
}
int main()
{
    int n = read();
    vector<vector<LL>> arr(2, vector<LL>(n + 1)),
        psa(2, vector<LL>(n + 1)),
        dp(2, vector<LL>(n + 1));
    LL tot = 0;
    for (int i = 1; i <= n; ++i)
        arr[0][i] = read(), tot += arr[0][i], arr[0][i] *= 2 * n;
    for (int i = 1; i <= n; ++i)
        arr[1][i] = read(), tot += arr[1][i], arr[1][i] *= 2 * n;
    for (int i = 1; i <= n; ++i)
        arr[0][i] -= tot, psa[0][i] = arr[0][i] + psa[0][i - 1];
    for (int i = 1; i <= n; ++i)
        arr[1][i] -= tot, psa[1][i] = arr[1][i] + psa[1][i - 1];
    cmx(mp[0][0][0], 0);
    cmx(mp[0][1][0], 0);

    cmx(mp[1][0][0], 0);
    cmx(mp[1][1][0], 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int k = 0; k < 2; ++k)
        {
            int l = !k;
            dp[k][i] = max(dp[k][i - 1], dp[l][i - 1]);
            
            dp[k][i] = max(gmx(l,0, psa[l][i]) + 1, dp[k][i]);
            dp[k][i] = max(gmx(l, 1, -psa[l][i]) + 1, dp[k][i]);
        }
        if (psa[0][i] + psa[1][i] == 0)
            dp[0][i] = dp[1][i] = max(dp[0][i], dp[1][i]) + 1;
        cmx(mp[0][0][psa[0][i]], dp[1][i]);
        cmx(mp[0][1][psa[1][i]], dp[0][i]);
        
        cmx(mp[1][0][psa[1][i]], dp[0][i]);
        cmx(mp[1][1][psa[0][i]], dp[1][i]);
    }
    write(dp[1][n]), putchar('\n');
    return 0;
}