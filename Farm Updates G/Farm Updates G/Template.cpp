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
    int e;
    bool operator <(const node& other) const
    {
        return e < other.e;
    }
};

void ShortestPath(const vector<vector<node>>& adj, vector<int>& dis)
{
    priority_queue <node> q;
    
    vector<bool> visited(adj.size());

    for (int i = 1; i < dis.size(); ++i)
        q.push({ i, dis[i] });
    while (!q.empty())
    {
        auto t = q.top();
        int e = t.e, x = t.x;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto& i : adj[x])
        {
            int y = i.x, te = i.e;
            int tmpe = min(te, e);
            dis[y] = max(dis[y], tmpe);
            q.push({y, tmpe});
        }
    }
}
int main()
{
    int n = read(), q = read();
    vector<vector<node>> adj(n + 1);
    vector<int> dis(n + 1, q);
    vector<pair<int, node>> road;
    road.push_back({ 0,{0,0} });
    for(int i = 1; i <= q; ++i)
    {
        char c;
        cin >> c;
        switch (c)
        {
            int x, y;
        case 'D':
            x = read();
            dis[x] = i - 1;
            break;
        case 'A':
             x = read(), y = read();
            road.push_back({ x,{y, q} });
            break;
        case 'R':
            int e = read();
            road[e].second.e = i - 1;
            break;
        }
    }
    for (int i = 1; i < road.size(); ++i)
    {
        adj[road[i].first].push_back(road[i].second);
        adj[road[i].second.x].push_back({ road[i].first, road[i].second.e });
    }
        
    ShortestPath(adj, dis);
    for (int i = 1; i <= n; ++i)
        write(dis[i]), putchar('\n');
    return 0;
}