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
class node
{
public:
    int target;
    int weight;
    int id;
};
void ShortestPath(const vector<vector<node>>& adj, vector<int>& dis, vector<pair<int,int>>& pre, int s)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.emplace(0, s);
    pre[s] = {s, 0};
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int d = t.first, x = t.second;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto i : adj[x])
        {
            int t = i.target, w = i.weight, id = i.id;
            if (dis[t] <= d + w)
                continue;
            pre[t].first = x;
            pre[t].second = i.id;
            dis[t] = d + w;
            q.push({ dis[t],t });
        }
    }
}
int ShortestPath2(const vector<vector<pair<int,int>>>& adj, vector<pair<int, int>>& preP, vector<pair<int, int>>& preQ)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    vector<int> dis(adj.size(), INT_MAX);
    q.emplace(0, 1);
    dis[1] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int d = t.first, x = t.second;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto i : adj[x])
        {
            int t = i.first, id = i.second, w = 2;
            if (preP[x].second == id) --w;
            if (preQ[x].second == id)--w;
            if (dis[t] <= d + w)
                continue;
            
            dis[t] = d + w;
            q.push({ dis[t],t });
        }
    }
    return dis[adj.size() - 1];
}
int main()
{
    int n = read(), m = read();
    vector<vector<node>> adjP(n + 1), adjQ(n + 1);
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<bool> vp(m + 1), vq(m + 1);
    vector<int> dis(n + 1);
    vector<pair<int,int>> preP(n + 1), preQ(n + 1);
    for(int i = 1; i <= m; ++i)
    {
        int a = read(), b = read(), p = read(), q = read();
        adjP[b].push_back({ a,p, i });
        //adjP[b].push_back({ a,p });
        adjQ[b].push_back({ a,q, i });
        adj[a].push_back({ b,i });
    }
    
    ShortestPath(adjP, dis, preP, n);
    ShortestPath(adjQ, dis, preQ, n);
    
    write(ShortestPath2(adj, preP, preQ)), putchar('\n');

    
}
