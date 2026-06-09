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
void bfs(const vector<vector<int>>& adj, vector<int>& dis, int s)
{
    queue<int> q;
    q.push(s);
    
    fill(dis.begin(), dis.end(), INT_MAX);
    dis[s] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i : adj[x])
        {
            if (dis[i] != INT_MAX)
                continue;
            dis[i] = dis[x] + 1;
            q.push(i);
        }
    }
}
int main()
{
    int B = read(), E = read(), P = read(), n = read(), m = read();
    vector<int> dis1(n + 1), dis2(n + 1), disN(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(adj, dis1, 1);
    bfs(adj, dis2, 2);
    bfs(adj, disN, n);

    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        int t = dis1[i] * B + dis2[i] * E + disN[i] * P;
        ans = min(ans, t);
    }
    cout << ans << endl;
}
