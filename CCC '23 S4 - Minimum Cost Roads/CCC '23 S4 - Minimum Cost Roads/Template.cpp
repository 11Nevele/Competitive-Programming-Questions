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
class node
{
public:
    int x;
    LL d;
    bool operator <(const node& other) const
    {
        return d > other.d;
    }
};
class Edge
{
public:
    int x;
    int y;
    LL l;
    LL c;
    int id;
    bool operator < (const Edge& other)const
    {
        if (l == other.l)
            return c > other.c;
        return l > other.l;
    }
};
vector<Edge> roads;
bool ShortestPath(const vector<vector<int>>& adj, int s, int e, int ban, LL mx)
{
    priority_queue <node> q;
    vector<bool> visited(adj.size());
    vector<LL> dis(adj.size(), LL_MAX);
    q.push({ s, 0 });
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
            int t = roads[i].x == x ? roads[i].y : roads[i].x;
            LL w = roads[i].l;
            if (dis[t] <= d + w || d + w > mx || roads[i].id == ban)
                continue;
            if (t == e)
                return true;
            dis[t] = d + w;
            q.push({ t, dis[t] });
        }
    }
    return false;
}

int main()
{
    int n = read(), m = read();
    LL ans = 0;
    vector<vector<int>> adj(n + 1);
    
    while (m--)
    {
        int a = read(), b = read(), l =read(), c= read();
        roads.push_back({ a,b,l,c, m });
        ans += c;
    }
    sort(roads.begin(), roads.end());
    for (int i = 0; i < roads.size(); ++i)
    {
        adj[roads[i].x].push_back(i);
        adj[roads[i].y].push_back(i);
    }
    for (auto &r : roads)
    {
        if (!ShortestPath(adj, r.x, r.y, r.id, r.l))
            continue;
        for (auto it = adj[r.x].begin(); it != adj[r.x].end(); ++it)
        {
            if (roads[(*it)].id == r.id)
            {
                adj[r.x].erase(it);
                break;
            }
        }
        for (auto it = adj[r.y].begin(); it != adj[r.y].end(); ++it)
        {
            if (roads[(*it)].id == r.id)
            {
                adj[r.y].erase(it);
                break;
            }
        }
        ans -= r.c;
    }
    write(ans), putchar('\n');
    return 0;
}