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
vector<vector<int>> adj(100005);
int n;
int dfs(int x, int p, int k)
{
    multiset<int> s;
    for (int i : adj[x])
    {
        if (i == p)
            continue;
        int res = dfs(i, x, k);
        if (res == -2)
            return -2;
        int tmp = k - res - 1;
        if (tmp == 0)
            continue;
		auto it = s.find(tmp);
		if (it != s.end())
			s.erase(it);
		else
			s.insert(res + 1);
    }
    if (s.size() > 1)
        return -2;
    if (s.size() == 0)
        return 0;
    return *s.begin();
    

}
int main()
{
    n = read();
    for(int i = 1; i < n; ++i)
	{
		int a = read(), b = read();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

    for (int i = 1; i < n; ++i)
    {
        if ((n - 1) % i)
            putchar('0');
        else if (dfs(1, 0, i) == 0)
            putchar('1');
        else
            putchar('0');
    }
    return 0;
}