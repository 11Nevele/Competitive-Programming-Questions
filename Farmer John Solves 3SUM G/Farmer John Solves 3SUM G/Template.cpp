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
    int n = read(), q = read();
    unordered_map<int, vector<int>> mp;
    vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
	{
		arr[i] = read();
		mp[arr[i]].push_back(i);
	}
	vector<vector < LL >> dp(n + 1, vector<LL>(n + 1, 0));
    for (int i = 3; i <= n; ++i)
    {
        for (int l = 1; l + i - 1 <= n; ++l)
        {
            int r = l + i - 1;
            dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
            int target = -(arr[l] + arr[r]);
            if (mp.find(target) != mp.end())
            {
                auto s = lower_bound(mp[target].begin(), mp[target].end(), l + 1),
                    e = upper_bound(mp[target].begin(), mp[target].end(), r - 1);
                if(s != mp[target].end())
                    dp[l][r] += e - s;

            }
        }
    }

    while (q--)
	{
		int l = read(), r = read();
		write(dp[l][r]);
		putchar('\n');
	}
    return 0;
}