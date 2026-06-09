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
string str;
LL dp[1000][1000][3][3]; 
void solve(int l, int r)
{
    
    if (l + 1 == r)
    {
        dp[l][r][1][0] = 1;
        dp[l][r][0][1] = 1;
        dp[l][r][2][0] = 1;
        dp[l][r][0][2] = 1;
        return;
    }
    if (l >= r)
        return;
    stack<int> s;
    int cur = l;
    for (int i = l; i <= r; ++i)
    {
        if (str[i] == '(')
        {
            s.push(i);
            continue;
        }
        int pre = s.top();
        s.pop();
        if (s.empty())
        {
            if (pre + 1 == i)
            {
                dp[pre][i][1][0] = 1;
                dp[pre][i][0][1] = 1;
                dp[pre][i][2][0] = 1;
                dp[pre][i][0][2] = 1;
            }
            else
            {
                solve(pre + 1, i - 1);
                dp[pre][i][0][1] = dp[pre + 1][i - 1][1][0] + dp[pre + 1][i - 1][2][0] + dp[pre + 1][i - 1][0][2] + dp[pre + 1][i - 1][0][0] + dp[pre + 1][i - 1][2][2] + dp[pre + 1][i - 1][1][2];
                dp[pre][i][0][2] = dp[pre + 1][i - 1][1][0] + dp[pre + 1][i - 1][2][0] + dp[pre + 1][i - 1][0][1] + dp[pre + 1][i - 1][0][0] + dp[pre + 1][i - 1][1][1] + dp[pre + 1][i - 1][2][1];
                dp[pre][i][1][0] = dp[pre + 1][i - 1][0][1] + dp[pre + 1][i - 1][2][0] + dp[pre + 1][i - 1][0][2] + dp[pre + 1][i - 1][0][0] + dp[pre + 1][i - 1][2][2] + dp[pre + 1][i - 1][2][1];
                dp[pre][i][2][0] = dp[pre + 1][i - 1][0][1] + dp[pre + 1][i - 1][1][0] + dp[pre + 1][i - 1][0][2] + dp[pre + 1][i - 1][0][0] + dp[pre + 1][i - 1][1][1] + dp[pre + 1][i - 1][1][2];
                for (int j = 0; j < 3; ++j)
                    for (int k = 0; k < 3; ++k)
                        dp[pre][i][j][k] = (dp[pre][i][j][k] % 1000000007);
            }
            if (cur == l)
            {
                cur = i;
                continue;
            }
                
                dp[l][i][0][0] =
                    dp[l][cur][0][1] * (dp[pre][i][2][0]) +
                    dp[l][cur][0][2] * (dp[pre][i][1][0]) +
                    dp[l][cur][0][0] * (dp[pre][i][2][0] + dp[pre][i][1][0]);
                dp[l][i][1][0] =
                    dp[l][cur][1][0] * (dp[pre][i][1][0] + dp[pre][i][2][0]) +
                    dp[l][cur][1][1] * (dp[pre][i][2][0]) +
                    dp[l][cur][1][2] * (dp[pre][i][1][0]);
                dp[l][i][2][0] =
                    dp[l][cur][2][0] * (dp[pre][i][1][0] + dp[pre][i][2][0]) +
                    dp[l][cur][2][1] * (dp[pre][i][2][0]) +
                    dp[l][cur][2][2] * (dp[pre][i][1][0]);
                dp[l][i][0][1] =
                    dp[l][cur][0][0] * (dp[pre][i][0][1]) +
                    dp[l][cur][0][1] * (dp[pre][i][0][1]) +
                    dp[l][cur][0][2] * (dp[pre][i][0][1]);
                dp[l][i][0][2] =
                    dp[l][cur][0][0] * (dp[pre][i][0][2]) +
                    dp[l][cur][0][1] * (dp[pre][i][0][2]) +
                    dp[l][cur][0][2] * (dp[pre][i][0][2]);
                dp[l][i][1][1] =
                    dp[l][cur][1][0] * (dp[pre][i][0][1]) +
                    dp[l][cur][1][1] * (dp[pre][i][0][1]) +
                    dp[l][cur][1][2] * (dp[pre][i][0][1]);
                dp[l][i][2][2] =
                    dp[l][cur][2][0] * (dp[pre][i][0][2]) +
                    dp[l][cur][2][1] * (dp[pre][i][0][2]) +
                    dp[l][cur][2][2] * (dp[pre][i][0][2]);
                dp[l][i][1][2] =
                    dp[l][cur][1][0] * (dp[pre][i][0][2]) +
                    dp[l][cur][1][1] * (dp[pre][i][0][2]) +
                    dp[l][cur][1][2] * (dp[pre][i][0][2]);
                dp[l][i][2][1] =
                    dp[l][cur][2][0] * (dp[pre][i][0][1]) +
                    dp[l][cur][2][1] * (dp[pre][i][0][1]) +
                    dp[l][cur][2][2] * (dp[pre][i][0][1]);
                for (int j = 0; j < 3; ++j)
                    for (int k = 0; k < 3; ++k)
                        dp[l][i][j][k] = (dp[l][i][j][k] % 1000000007);
            cur = i;
            
        }
    }
}
int main()
{
    
    cin >> str;
    solve(0, str.size() - 1);
    LL ans = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            ans = (ans + dp[0][str.size() - 1][i][j]) % 1000000007;
    cout << ans << endl;
}
