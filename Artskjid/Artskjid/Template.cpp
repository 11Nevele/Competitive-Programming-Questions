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

vector<vector<int>> dp(270000, vector<int>(18, -1));
int adj[18][18];

void solve(int bit, int last)
{
    if (dp[bit][last] != -1)
        return;
	int t = (bit - (1 << last));
    if (t == 1)
        dp[bit][last] = adj[0][last];
    for (int i = 1; i < 18; ++i)
    {
        
        if ((t & (1 << i)) == 0 || adj[i][last] == 0)
            continue;
        solve(t, i);
        if (dp[t][i] == -1)
            continue;
        dp[bit][last] = max(dp[bit][last], dp[t][i] + adj[i][last]);
    }
}

int main()
{
	int n = read(), m = read();
    for (int i = 0; i < m; i++)
    {
        int a = read(), b = read(), l = read();
		adj[a][b] = max(adj[a][b], l);
    }
    int bit = (1 << n) - 1;
    int ans = 0;
    for (int i = 0; i <= bit; ++i)
    {
		if ((i & (1 << (n - 1))) == 0 || (i & 1) == 0)
			continue;
        solve(i, n - 1);
		ans = max(ans, dp[i][n - 1]);

    }
	write(ans);
	putchar('\n');
    return 0;
}
/*
* 鲁滨逊漂流记
* 
*/