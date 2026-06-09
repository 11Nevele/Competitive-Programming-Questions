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
#define mod 100003
int main()
{
    int n = read(), m = read();
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> ans(n + 1), dis(n + 1, INT_MAX);
    //node distance
    queue<pair<int,int>> q;
    q.push({1,0});
    ans[1] = 1, dis[1] = 0;
    while (!q.empty())
    {
        int x = q.front().first, d = q.front().second;
        q.pop();

        for (int i : adj[x])
        {
            if (dis[i] > d + 1)
            {
                dis[i] = d + 1;
                ans[i] += ans[x];
                ans[i] %= mod;
                q.push({ i, d + 1 });
            }
            else if (dis[i] == d + 1)
            {
                ans[i] += ans[x];
                ans[i] %= mod;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        write(ans[i]), putchar('\n');
}
