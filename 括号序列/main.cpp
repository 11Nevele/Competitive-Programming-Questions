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
#include <cstring>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define mod 1000000007;
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
LL dp[505][505][6];
bool v[505][505];
int k;
string str;


void solve(int l, int r)
{
    if (v[l][r])
        return;
    v[l][r] = true;
    for (int i = l; i < r; ++i)
        solve(l, i), solve(i + 1, r);
    
    {
        bool allStar = true;
        for(int i = l;i<=r; ++i)
            if (str[i] != '*' && str[i] != '?')
            {
                allStar = false;
                break;
            }
        if(allStar && (r - l + 1) <= k)
            dp[l][r][0] = true;
    }
    
    if (r > l &&(str[l] == '(' || str[l] == '?') && (str[r] == ')' || str[r] == '?'))
    {
        dp[l][r][1] = (dp[l + 1][r - 1][0] + dp[l + 1][r - 1][2] + dp[l + 1][r - 1][3] + dp[l + 1][r - 1][4])%mod;
    }

    for (int i = l; i < r; ++i)
    {
        dp[l][r][2] += dp[l][i][3] * dp[i + 1][r][0];
        dp[l][r][3] += (dp[l][i][2] + dp[l][i][3]) * dp[i + 1][r][1];
        dp[l][r][4] += (dp[l][i][4] + dp[l][i][5]) * dp[i + 1][r][1];
        dp[l][r][5] += dp[l][i][4] * dp[i + 1][r][0];
        for (int j = 2; j <= 5; ++j)
            dp[l][r][j] %= mod;
    }
    dp[l][r][3] += dp[l][r][1];
    dp[l][r][5] += dp[l][r][0];
    for (int j = 2; j <= 5; ++j)
        dp[l][r][j] %= mod;
}

int main()
{
    int n = read();
    k = read();
    cin >> str;
    str = " " + str;
    for (int i = 1; i <= n; ++i)
        dp[i][i - 1][0] = 1;
    //init
    /*{
        for (int i = n; i >= 0; --i)
        {
            cStar[i] = cStar[i + 1], cQStar[i] = cQStar[i + 1];
            if (str[i] == '*')
                ++cStar[i], ++cQStar[i];
            else if (str[i] == '?')
                ++cQStar[i], cStar[i] = 0;
            else
                cStar[i] = 0, cQStar[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            psa[i] = psa[i - 1];
            if (str[i] == '*' || str[i] == '?') ++psa[i];
        }
    }*/
    
    solve(1, n);
    write(dp[1][n][3]);
    putchar('\n');
}
