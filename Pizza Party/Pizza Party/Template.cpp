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
    int n = read();
	vector<int> a(n + 1), b(n + 1), ans(n +1, -1), ans2(n + 1);
    vector<vector<int>> bucket(n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = read();
    for (int i = n; i > 0; --i)
        bucket[b[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
    {
        int t = a[i];
		if (bucket[t].empty())
		{
            write(-1), putchar('\n');
            return 0;
		}
		a[i] = bucket[t].back();
		bucket[t].pop_back();
    }
        
    vector<stack<int>> st;
    vector<int> v(n + 1, -1);
	st.push_back(stack<int>());
    multimap<int, int> mp;
	mp.insert({ INT_MAX, 0 });
    int ind = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (v[i] == -1)
        {
            auto it = mp.lower_bound(a[ind]);
            if (it == mp.end())
            {
                st.push_back(stack<int>());
                int x = st.size() - 1;
                st[x].push(a[ind]);
				mp.insert({ a[ind], x });
                v[a[ind]] = x;
                ans[ind] = x;
            }
            else
            {
				int x = it->second;
				mp.erase(it);
				st[x].push(a[ind]);
                mp.insert({ a[ind], x });
                v[a[ind]] = x;
				ans[ind] = x;
            }
            ++ind;
        }
        int x = v[i];
		ans2[i] = x;
		mp.erase(mp.find(st[x].top()));
		st[x].pop();
        if (st[x].empty())
            mp.insert({ INT_MAX, x });
        else
			mp.insert({ st[x].top(), x });
    }
    write((int)st.size()), putchar('\n');
    for(int i = 1; i <= n; ++i)
		write(ans[i] + 1), putchar(' ');
    putchar('\n');
	for (int i = 1; i <= n; ++i)
		write(ans2[i] + 1), putchar(' ');
	putchar('\n');
    return 0;
}