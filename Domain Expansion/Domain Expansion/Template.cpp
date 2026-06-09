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
    int n = read(), m = read();
    vector<int>points;
    vector<pair<int, int>> segs(n + 1);
	unordered_map<int, int>mp;

    vector<int> src(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int l = read(), r = read();
        points.push_back(l);
        points.push_back(r + 1);
		segs[i] = { l, r };
		src[i] = read();
	}
    points.push_back(m + 1);
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	for (int i = 0; i < points.size(); i++)
		mp[points[i]] = i + 1;
	vector<vector<int>> arr(points.size() + 1);
	for (int i = 1; i <= n; i++)
	{
		segs[i] = { mp[segs[i].first], mp[segs[i].second + 1] };
		arr[segs[i].first].push_back(i);
		arr[segs[i].second].push_back(-i);
	}

    vector<int> ans(n + 1);
    set<pair<int, int>, greater<pair<int,int>>>s;
    for (int i = 1; i < arr.size() - 1; ++i)
    {
        for (int j : arr[i])
        {
            if (j > 0)
                s.insert({ src[j], j });
            else
                s.erase({ src[-j], -j });
        }
		if (s.empty())
			continue;
        int t = s.begin()->second;

        ans[t] += points[i] - points[i - 1];
    }
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
    putchar('\n');
    return 0;
}