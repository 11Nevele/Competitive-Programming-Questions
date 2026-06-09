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
LL GetDist(pair<int, int> a, int x)
{
	return (LL)(a.first - x) * (a.first - x) + (LL)(a.second) * (a.second);
}
class hashPair
{
public:
    size_t operator()(const pair<int, int>& p) const
    {
        auto hash1 = hash<int>{}(p.first);
        auto hash2 = hash<int>{}(p.second);
        return hash1 ^ hash2;
    }
};
int main()
{
    int n = read();
    vector<int> sheep(1000005, INT_MAX);
    for (int i = 0; i < n; ++i)
    {
        int x = read(), y = read();
        sheep[x] = min(sheep[x], y);
    }
    vector<pair<int,int>> q;
	unordered_set<pair<int,int>, hashPair> mp;
    int ind = 0;
    for (int i = 0; i <= 1000000; ++i)
    {
		if (sheep[i] != INT_MAX)
		{
			LL dist = GetDist({i, sheep[i]}, i);
			while (ind < q.size() && GetDist(q.back(), i) >= dist)
			{
				q.pop_back();
			}
			q.push_back({ i,sheep[i] });
		}

        if (q.size() > ind)
        {
            LL minDist = GetDist(q[ind], i);
            if (ind == 0 || GetDist(q[ind], i) < GetDist(q[ind - 1], i))
            {
                while (ind < q.size() && GetDist(q[ind], i) == minDist)
                {
                    mp.insert(q[ind]);
                    ++ind;
                }
            }
        }
		

    }
	for (auto& i : mp)
	{
		cout << i.first << " " << i.second << endl;
	}
    return 0;
}