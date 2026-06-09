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

class node
{
public:
    int t;
    int dis;
    int k;
};
class com
{
public:
    bool operator() (node a, node b)
    {
        return a.dis > b.dis;
    }
};


int ShortestPath(const vector<vector<pair<int, int>>>& adj, int s, int maxK)
{
    priority_queue < node, vector <node>, com> q;
    vector<vector<bool>> visited(adj.size(), vector<bool>(maxK + 1));

    vector<vector<int>> dis(adj.size() + 1, vector<int>(maxK + 1, INT_MAX));
    q.push({ 1, 0, 0 });
    dis[s][0] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int distance = t.dis, node = t.t, k = t.k;
        q.pop();
        if (visited[node][k])
            continue;
        visited[node][k] = true;
        for (auto i : adj[node])
        {
            int next = i.first, weight = i.second;
            if (dis[next][k] > distance + weight)
            {
                dis[next][k] = distance + weight;
                q.push({next, distance + weight, k});
            }
            if (k < maxK && dis[next][k + 1] > distance + (weight >> 1))
            {
                dis[next][k + 1] = distance + (weight >> 1);
                q.push({ next, distance + (weight >> 1), k + 1 });
            }
        }
    }
    int n = adj.size() - 1;
    int ans = INT_MAX;
    for (int i = 0; i <= maxK; ++i)
        ans = min(ans, dis[n][i]);
    return ans;
}
int main()
{
    int n = read(), m = read(), k = read();
    vector < vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    cout << ShortestPath(adj, 1, k);
}
