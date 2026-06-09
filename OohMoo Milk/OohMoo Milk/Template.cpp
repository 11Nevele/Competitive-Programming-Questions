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
const LL mod = 1e9 + 7;

pair<int, LL> f(deque <LL> q, int cur, int target, int remain)
{
    LL ans = 0, cnt = 0;
	while (!q.empty())
	{
		LL t = q.front();
        LL mn = min(t, (LL)target);
        remain -= (mn - cur);

        ans = (ans + mn * mn % mod) % mod;
		q.pop_front();
	}
    return { remain, ans % mod };
}
LL solve(vector<LL>& a, LL x, LL d) 
{
    sort(a.begin(), a.end());
    LL cur = 0, cnt = 0;
    deque<LL> end;
    LL tot = d * x;
    LL ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        LL preTot = tot;
		LL preAns = ans;
        vector<LL> out;
        while (!end.empty() && end.front() <= a[i])
        {
			if (end.front() - cur > tot)
			{
				tot = preTot;
				ans = preAns;
				while (!out.empty())
				{
					end.push_front(out.back());
					out.pop_back();
				}
				for (int j = i; j < a.size(); ++j)
					ans = (ans + a[j] * a[j] % mod) % mod;
				break;
			}
            tot -= (end.front() - cur);
            ans = (ans + end.front() * end.front()) %mod;
			out.push_back(end.front());
            --cnt;
            end.pop_front();
        }
        if (tot < (LL)cnt * (a[i] - cur))
        {
            for (int j = i; j < a.size(); ++j)
                ans = (ans + a[j] * a[j]) % mod;
            break;
        }
		tot -= cnt * (a[i] - cur);
        ++cnt;
        end.push_back(a[i] + d);
        cur = a[i];
    }
    int l = cur, r = 1e9 + 7;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		int rem = f(end, cur, mid, tot).first;
        if (rem < 0)
            r = mid - 1;
        else
            l = mid;
	}
	auto res = f(end, cur, l, tot);
	ans = (ans + res.second) % mod;
	LL dif = ((LL)l + 1) * ((LL)l + 1) - ((LL)l * (LL)l) % mod;
	ans += dif * (LL)res.first;
    ans %= mod;
    return ans;


}
int main()
{
    int n = read();
    LL d = readLL();
    int a = read(), b = read();
    vector<LL> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = readLL();
	}
    sort(arr.begin(), arr.end(), [](LL a, LL b) {return a > b; });
    LL ans = 0;
    for(int i = a; i < n; ++i)
		ans += arr[i] * arr[i];
	arr.erase(arr.begin() + a, arr.end());
    ans += solve(arr, a - b, d);
	ans = ans % mod;
	write(ans), putchar('\n');
    return 0;
}