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
int n;
vector<int> arr(100005), cost(100005), swaped(100005);
LL dp[100005][3][3]; // ith node, < = >, self, l, r


LL solve(int target, int i, int j, int k)
{
    if (i > n)
        return 0;
    if(dp[i][j][k] != -1)
		return dp[i][j][k];
	int l = i * 2, r = i * 2 + 1;
	if (r > n)
	{
		if (j == 0)
			return dp[i][j][k] = swaped[i] < target ? 0 : cost[i];
		if (j == 1)
			return dp[i][j][k] = swaped[i] == target ? 0 : cost[i];
		if (j == 2)
			return dp[i][j][k] = swaped[i] > target ? 0 : cost[i];
	}
	if (j == 0)
	{
        if (arr[i] < target)
            dp[i][j][k] = ;
        dp[i][j][k] = min
		
	}
}
int main()
{
    n = read();
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		arr[i] = read(), cost[i] = read();
    for (int i = n; i > 0; --i)
    {
		int l = i * 2, r = i * 2 + 1;
        if (r > n)
            continue;
		int mx = max(swaped[l], swaped[r]), mn = min(swaped[l], swaped[r]);
        if (mn <= arr[i] && arr[i] <= mx)
            swaped[i] = arr[i];
		else if (arr[i] <= mn)
			swaped[i] = mn;
		else
			swaped[i] = mx;
    }
    return 0;
}