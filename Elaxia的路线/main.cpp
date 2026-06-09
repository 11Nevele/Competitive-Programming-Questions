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


class com
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};
void ShortestPath(const vector<vector<int>>& adj, vector<int>& dis, vector<vector<int>>& pre, int s)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.emplace(0, s);
    pre[s].push_back(s);
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int d = t.first, x = t.second;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (int i = 1; i < adj[x].size(); ++i)
        {
            int t = i, w = adj[x][i];
            if (w == -1)
                continue;
            if (dis[t] < d + w)
                continue;
            if (dis[t] == d + w)
                pre[t].push_back(x);
            else
            {
                pre[t].clear();
                pre[t].push_back(x);
                dis[t] = d + w;
                q.push({ dis[t],t });
            }
            
        }
    }
}
void Reform(vector<vector<int>> &adj2, vector<vector<int>>& adj, vector<vector<int>>& pre, int s, int t)
{
    queue<int> q;
    q.push(s);
    vector<int> v(adj.size());
    v[s] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i : pre[x])
        {
            if (!v[i])
                q.push(i);
            v[i] = true;
            if (t == 0)
            {
                adj2[i][x] = 0;
            }
            else if(t == 1)
            {
                if(adj2[i][x] == 0)
                adj2[i][x] = adj[i][x];
            }
            else
            {
                if (adj2[x][i] == 0)
                    adj2[x][i] = adj[x][i];
            }
            
        }
    }
}
void solve(vector<vector<int>>& adj, vector<int>& dis, int s)
{
    queue<pair<int, int>> q;
    fill(dis.begin(), dis.end(), -1);
    vector<bool> v(dis.size());
    q.push({ s, 0 });

    dis[s] = 0;
    while (!q.empty())
    {
        int x = q.front().first, d = q.front().second;
        q.pop();
        for (int i = 1; i < dis.size(); ++i)
        {
            if (adj[x][i] == -1) continue;
            int w = adj[x][i];
            if (dis[i] >= d + w)
                continue;
            dis[i] = d + w;
            q.push({ i, d + w });
        }
    }
}
int main()
{
    int n = read(), m = read();
    int s1 = read(), e1 = read(), s2 = read(), e2 = read();
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1)), adj2(n + 1, vector<int>(n + 1, -1)), adj3(n + 1, vector<int>(n + 1, -1));
    while (m--)
    {
        int a = read(), b = read(), c = read();
        adj[a][b] = c;
        adj[b][a] = c;
    }
    vector<vector<int>> pre1(n + 1), pre2(n + 1);
    vector<int> dis(n + 1);
    ShortestPath(adj, dis, pre1, s1);
    ShortestPath(adj, dis, pre2, s2);
    Reform(adj2, adj, pre1, e1, 0);
    Reform(adj3, adj, pre1, e1, 0);
    Reform(adj2, adj, pre2, e2, 1);
    Reform(adj3, adj, pre2, e2, 2);
    
    solve(adj2, dis, s1);
    int ans = dis[e1];
    solve(adj3, dis, s1);
    ans = max(dis[e1], ans);

    write(ans), putchar('\n');
}
