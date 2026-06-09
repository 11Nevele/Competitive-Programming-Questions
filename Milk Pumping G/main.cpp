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

class Path
{
public:
    int target;
    int c;
    int f;
};
long double ShortestPath(const vector<vector<Path>>& adj, int s, int target, int minF)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    vector<int> dis(adj.size(), INT_MAX);
    q.emplace(0, s);
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int distance = t.first, node = t.second;
        q.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        for (auto i : adj[node])
        {
            int next = i.target, weight = i.c, f= i.f;
            
            if (dis[next] <= distance + weight || f < minF)
                continue;
            if (next == target)
                return distance + weight;
            dis[next] = distance + weight;
            q.push({ dis[next],next });
        }
    }
    return -1;
}

int main()
{
    int n = read(), m = read();
    vector<vector<Path>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), c = read(), f = read();
        adj[a].push_back({ b,c,f });
        adj[b].push_back({ a,c,f });
    }
    long double ans = 0;
    for (int i = 0; i < 1000; ++i)
    {
        long double minF = i;
        long double cost = ShortestPath(adj, 1, n, i);
        ans = max(ans, minF / cost);
    }
    cout << (LL)(ans * 1000000) << endl;
}
