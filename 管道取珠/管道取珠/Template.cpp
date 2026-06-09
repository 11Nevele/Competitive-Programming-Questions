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
const int mod = 1024523;

int main()
{
    int n = read(), m = read();
    vector<vector<char>> tubes(2);
    tubes[0].resize(n + 1);
	tubes[1].resize(m + 1);
	for (int i = 1; i <= n; i++)
		cin >> tubes[0][i];
	for (int i = 1; i <= m; i++)
		cin >> tubes[1][i];
	reverse(tubes[0].begin() + 1, tubes[0].end());
	reverse(tubes[1].begin() + 1, tubes[1].end());
    vector<vector<int>> pre(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1));
    pre[0][0] = 1;
    for (int k = 1; k <= n + m; ++k)
    {
        for (int i = max(0, k - m); i <= min(n, k); ++i)
        {
            for (int j = max(0, k - m); j <= min(n, k); ++j)
            {
				dp[i][j] = 0;
                int a = k - i, b = k - j;
                if (i && j && tubes[0][i] == tubes[0][j])
                    dp[i][j] = (dp[i][j] + pre[i - 1][j - 1]) % mod;
                if (i && b && tubes[0][i] == tubes[1][b])
                    dp[i][j] = (dp[i][j] + pre[i - 1][j]) % mod;
                if (a && j && tubes[1][a] == tubes[0][j])
                    dp[i][j] = (dp[i][j] + pre[i][j - 1]) % mod;
                if (a && b && tubes[1][a] == tubes[1][b])
                    dp[i][j] = (dp[i][j] + pre[i][j]) % mod;

            }
        }
        pre = dp;
    }
	write(dp[n][n]), putchar('\n');
    return 0;
}