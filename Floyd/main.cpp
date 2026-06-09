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
void Floyd(const vector<vector<pair<int,int>>>& adj, vector<vector<LL>>& dis, vector<vector<int>>& pre)
{
    int n = adj.size() - 1;
    fill(dis.begin(), dis.end(), vector<LL>(n + 1, INT_MAX));
    fill(pre.begin(), pre.end(), vector<int>(n + 1, -1));
    for (int i = 1; i <= n; ++i)
    {
        for (auto& j : adj[i])
        {
            dis[i][j.first] = min((LL)j.second, dis[i][j.first]);
            pre[i][j.first] = i;
        }
        dis[i][i] = 0;
    }
        
    for (int t = 1; t <= n; ++t)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i == t)
                continue;
            for (int j = 1; j <= n; ++j)
            {
                if (j == t || i == j)
                    continue;
                LL time = dis[i][t] + dis[t][j];
                if (time < dis[i][j])
                {
                    dis[i][j] = time;
                    pre[i][j] = pre[t][j];
                }
            }
        }
    }


}
int main()
{
    int n = read(), m = read();
    vector<vector<pair<int, int>>> adj(n + 1);
    while (m--)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    vector<vector<LL>> dis(n + 1);
    vector<vector<int>> pre(n + 1);
    Floyd(adj, dis, pre);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            write(dis[i][j]), putchar(' ');
        putchar('\n');
    }
        
}
