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
const LL mx = 1e9, mod = 1e9 + 7;
LL powm(LL a, LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int n = read(), k = read();
    vector<pair<int,int>> seg;

    for (int i = 1; i <= n - k + 1; ++i)
    {
        int t = read();
        if (seg.empty() || seg.back().first != t)
            seg.push_back({ t,1 });
        else
            seg.back().second++;
    }
	seg[0].second += (k - 1);
    for (int i = 1; i < seg.size(); ++i)
    {
        if (seg[i].first > seg[i - 1].first)
        {
            seg[i].second += (k - 1);
            seg[i - 1].second -= (k);
			if (seg[i - 1].second <= 0)
				seg[i - 1].second = 0;
        }
        else
        {
            seg[i].second--;
        }
            
        
    }
    LL ans = 1;
    for (auto t : seg)
    {
		int num = mx - t.first + 1, cnt = t.second;
        vector<LL> dp(cnt + 2);
        dp[0] = dp[1] = 1;
        LL p = powm(num - 1, k) % mod;
        for (int i = 2; i <= cnt + 1; ++i)
        {
            dp[i] = dp[i - 1] * num % mod;
            if (i - k - 1 >= 0)
                dp[i] = (dp[i] - dp[i - k - 1] * p % mod + mod) % mod;
        }
		ans = ans * dp[cnt + 1] % mod;
    }
    write(ans), putchar('\n');
    return 0;
}