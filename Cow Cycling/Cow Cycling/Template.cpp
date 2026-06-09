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

int main()
{
    int n = read(), e = read(), d = read();
	if (d > e)
	{
		write(0),putchar('\n');
		return 0;
	}
    vector<vector<int>> dp(n + 1, vector<int>(e + 1, 100000));
    dp[0][e] = 0;
	for (int i = 1; i <= n; ++i) // after cow i lead
    {
        for (int j = 0; j <= e; ++j) // energy remain
        {
            for (int k = 0; k <= (e - j); ++k)// energy spent
            {
                int t = 1;
                for (t; t <= k; ++t)
                {
                    int v = k / t, r = k % t;
					if (r * (v + 1) * (v + 1) + (t - r) * v * v <= j + k)
						break;
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j + k] + t);
            }
        }
    }
    int mn = 100000;
    for(int i = 1; i <= n; ++i)
		mn = min(mn, dp[i][e - d]);
    write(mn >= 100000 ? 0 : mn);
    return 0;
}