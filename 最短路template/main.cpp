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
class Edge
{
public:
	int a, b, w;
};
//return false if negative loop
bool Bellford(vector<Edge> edges, vector<int>dis, int s, int n)
{
    fill(dis.begin(), dis.end(), INT_MAX);
	dis[s] = 0;
    for(int i = 0; i < n; ++i)
		for (auto& e : edges)
			if (dis[e.a] != INT_MAX && dis[e.a] + e.w < dis[e.b])
				dis[e.b] = dis[e.a] + e.w;
    for (auto& e : edges)
        if (dis[e.a] != INT_MAX && dis[e.a] + e.w < dis[e.b])
            return false;
    return true;

}
class node
{
public:
    int x;
    int d;
    bool operator <(const node& other) const
    {
        return d > other.d;
    }
};

void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<int>& dis, vector<int>& pre, int s)
{
    priority_queue <node> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.push({ s, 0 });
    pre[s] = s;
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int d = t.d, x = t.x;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto i : adj[x])
        {
            int t = i.first, w = i.second;
            if (dis[t] <= d + w)
                continue;
            pre[t] = x;
            dis[t] = d + w;
            q.push({ t, dis[t] });
        }
    }
}
bool SFPA(vector<vector<pair<int, int>>>& adj, vector<int>& dis, int s, int n)
{
    vector<int> cnt(n + 1);
    vector<bool> vis(n + 1);
    fill(dis.begin(), dis.end(), INT_MAX);
    vector<int> inQueueCnt(n + 1);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    inQueueCnt[s]++;
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto& i : adj[u])
        {
            int v = i.first, w = i.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                    inQueueCnt[v]++;
                    if (++inQueueCnt[v] > n + 1)
                        return false;
                }
            }
        }
    }
    return true;
}
void Floyd(const vector<vector<pair<int, int>>>& adj, vector<vector<LL>>& dis, vector<vector<int>>& pre)
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
    int n = read(), m = read(), s = read();
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> pre(n + 1), dis(n + 1);
    
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
    }
    ShortestPath(adj, dis, pre, s);

    for (int i = 1; i <= n; ++i)
        write(dis[i]), putchar(' ');
    putchar('\n');
}