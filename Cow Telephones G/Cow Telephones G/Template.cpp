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
vector<int> adj[100005];
int n, k;
void solve(vector<vector<int>> &dp, int x, int p)
{
    int ans = 0;
    vector<int> arr;
    for (int i : adj[x])
    {
		if (i == p)
			continue;
		solve(dp, i, x);
        ans += dp[i][0];
		arr.push_back(dp[i][1]- dp[i][0]);
    }
	dp[x][0] = ans;
    sort(arr.begin(), arr.end(), greater<int>());
    if (arr.size() > 0)
        dp[x][1] = ans + arr[0];
    for (int i = 0; i < k && i * 2 + 1 < arr.size(); ++i)
    {
		ans = ans + arr[i * 2] + arr[i * 2 + 1] + 1;
		dp[x][0] = max(dp[x][0], ans);
        if (i * 2 + 2 < arr.size() && i + 1 < k)
        {
            int t = ans + arr[i * 2 + 2];
			dp[x][1] = max(dp[x][1], t);
        }
    }

}
int main()
{
    n = read(), k = read();
	
    for(int i = 1; i < n; ++i)
	{
		int a = read(), b = read();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (adj[i].size() == 1)
            continue;
		vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        solve(dp, i, 0);
		ans = max(ans, dp[i][0]);
        break;
    }
	cout << ans << endl;
        
    return 0;
}