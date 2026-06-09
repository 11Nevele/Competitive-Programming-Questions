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
vector<vector<pair<int,int>>> adj(100001);
vector<bool> s(100001);
vector<int> f(100001), c(100001);

void dfs(int x, int p, int t, LL &ans, vector<bool> &v)
{
	v[x] = true;
    for (auto i : adj[x])
    {
        int j = i.first, out = i.second;
        if (j == p || v[j])
            continue;

        if (out)
        {
            if (t)
            {
                if (s[j])
                    dfs(j, x, 1, ans,v);
                else
                    dfs(j, x, 0, ans,v);
            }
            else
            {
                if (s[j])
                    dfs(j, x, 1, ans,v);
                else
                    dfs(j, x, 1, ans,v), ans += c[j];
            }
        }
        else
        {
            if (t)
            {
                dfs(j, x, c[j], ans,v);
            }
            else
            {
                if (s[j])
                    dfs(j, x, 1, ans,v);
                else
                    dfs(j, x, 1, ans,v), ans += c[j];
            }
        }

    }
}

int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
    {
        f[i] = read();
		if (f[i] == i)
            s[i] = true;
        adj[i].push_back({ f[i] , 1 });
		adj[f[i]].push_back({ i, 1 });
    }
        
    for (int i = 1; i <= n; ++i)
        c[i] = read();
    LL ans = 0;
	vector<bool> v1(n + 1, 0), v2(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
		if (v1[i])
			continue;
		LL a1 = 0, a2 = 0;
        if (!s[i])
            a2 = c[i];
        dfs(i, -1, 0, a1, v1);
        dfs(i, -1, 1, a2, v2);
		ans += min(a1, a2);
    }
	cout << ans << endl;
    return 0;
}