#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
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
LL dp[200005][2];
LL sum[200005];
int mtime[200005];
int depth[200005];
int value[200005];
vector<vector<int>> adj(200005);

void init(int n)
{
    sum[n] = value[n];
    bool t = true;
    for (int& i : adj[n])
    {
        t = false;
		init(i);
		sum[n] += sum[i];
        mtime[n] += mtime[i] + 1;
        depth[n] = max(depth[n], depth[i] + 1);
	}
}
bool com(int a, int b)
{
    bool t = (double)(mtime[a] + 1) / sum[a] < (double)(mtime[b] + 1) / sum[b];
    return t;
}
void solve(int n)
{
    sort(adj[n].begin(), adj[n].end(), com);
    int curTime = 0;

    for (int& i : adj[n])
    {
        curTime += 1;
		solve(i);
        dp[n][0] += dp[i][0] + sum[i] * curTime;
        curTime += mtime[i] * 2 + 1;
	}
    int maxD = 0;
    for (int& i : adj[n])
        maxD = max(maxD, depth[i]);
    if(adj[n].size())
        dp[n][1] = ((LL)1 << 63) - 1;
    for (int& i : adj[n])
    {
        if (depth[i] != maxD)
            continue;
        curTime = 0;
        LL ans = 0;
        for (int& j : adj[n])
        {
            if (j == i)
                continue;
            curTime += 1;
            ans += dp[j][0] + sum[j] * curTime;
            curTime += mtime[j] * 2 + 1;
        }
        
        ans += dp[i][1] + sum[i] * (curTime + 1);
        dp[n][1] = min(dp[n][1], ans);
    }
    
}
int main()
{
    int n = read(), t = read();
    for (int i = 2; i <= n; ++i)
    {
        int a = read(), b = read();
        value[i] = b;
        adj[a].push_back(i);
    }
    init(1);
    solve(1);
    if (t == 0)
    {
        cout << (n - 1) * 2 << " " << dp[1][0] << endl;
    }
    else
    {
        cout << (n - 1) * 2 - depth[1] << " " << dp[1][1] << endl;

    }

}
