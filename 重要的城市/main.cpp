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

bool important[205];
void ShortestPath(const vector<vector<pair<int, int>>>& adj, int s)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());
    vector<int> cnt(adj.size()), pre(adj.size()), dis(adj.size(), INT_MAX);

    q.emplace(0, s);
    pre[s] = s;
    cnt[s] = 1;
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
            int next = i.first, weight = i.second;
            if (dis[next] < distance + weight)
                continue;
            if (dis[next] == distance + weight)
                cnt[next] += cnt[node];
            else
                cnt[next] = cnt[node];
            pre[next] = node;
            dis[next] = distance + weight;
            q.push({ dis[next],next });
        }
    }

    for (int i = 1; i < adj.size(); ++i)
    {
        if (cnt[i] > 1)
            continue;
        int cur = pre[i];
        while (pre[cur] != cur)
        {
            important[cur] = true;
            cur = pre[cur];
        }
    }

}
int main()
{
    int n = read(), m = read();
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }

    for (int i = 1; i <= n; ++i)
    {
        ShortestPath(adj, i);
    }
    bool noImportant = true;
    for(int i = 1; i <= n; ++i)
        if (important[i])
        {
            write(i), putchar(' ');
            noImportant = false;
        }
    if (noImportant)
        cout << "No important cities.\n";
}
