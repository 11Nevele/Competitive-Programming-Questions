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
vector<vector<int>> adj(105);
vector<bool> vis(105);
int ans = 0;
void dfs(int x, int cnt)
{
	ans = max(ans, cnt);
	vis[x] = true;
	for (int i : adj[x])
		if (!vis[i])
			dfs(i, cnt + 1);
	vis[x] = false;
}
int main()
{
    int n = read();
    for (int i = 0; i < n; ++i)
    {
		int a = read(), b = read();
		adj[a].push_back(b);
		adj[b].push_back(a);
    }
    for(int i = 1; i <= 100; ++i)
		dfs(i, 1);
	write(ans),putchar('\n');
    return 0;
}