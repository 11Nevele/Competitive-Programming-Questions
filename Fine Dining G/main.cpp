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
void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<int>& dis, int s)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.emplace(0, s);
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
            int t = i.first, w = i.second;
            if (dis[t] <= d + w)
                continue;
            dis[t] = d + w;
            q.push({ dis[t],t });
        }
    }
}
void ShortestPath2(const vector<vector<pair<int, int>>>& adj, vector<int>& dis, vector<int>& dis2, vector<pair<int,int>> &s)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    
    for (auto i : s)
    {
        dis[i.first] = dis2[i.first] - i.second;
        q.push({ dis[i.first], i.first });
    }

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
            int t = i.first, w = i.second;
            if (dis[t] <= d + w)
                continue;
            dis[t] = d + w;
            q.push({ dis[t],t });
        }
    }
}

int main()
{
    int n = read(), m = read(), k = read();
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<pair<int, int>> s(k);
    vector<int> dis(n + 1), ans(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), t = read();
        adj[a].push_back({ b,t });
        adj[b].push_back({ a,t });
    }
    for (auto& i : s)
        i.first = read(), i.second = read();
    ShortestPath(adj, dis, n);
    ShortestPath2(adj, ans, dis, s);
    for (int i = 1; i < n; ++i)
    {
        if (ans[i] <= dis[i])
            putchar('1');
        else
            putchar('0');
        putchar('\n');
    }
}
