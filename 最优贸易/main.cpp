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
    int d;
    int l;
    bool operator <(const node& other) const
    {
        return d < other.d;
    }
};
int ShortestPath(const vector<vector<pair<int,int>>>& adj, int s)
{
    queue <int> q;
    vector<int> dis(adj.size(), -INT_MAX);
    vector<bool> visited(adj.size());

    q.push(1);
    dis[s] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i : adj[x])
        {
            int y = i.first, w = i.second;
            if (dis[y] < dis[x] + w)
            {
                dis[y] = dis[x] + w;
                q.push(y);
            }
        }
    }

    return max(dis[adj.size() - 1], 0);
}

int main()
{
    int n = read(), m = read();
    vector<vector<pair<int, int>>> adj(3 * n + 1);
    vector<int> price(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        adj[i].push_back({ i + n, 0 });
        adj[i + n].push_back({ i + n + n, 0 });
        price[i] = read();
    }
        
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b, 0 });
        adj[a + n].push_back({ b + n,price[b] - price[a]});
        adj[a + n + n].push_back({ b + n + n, 0 });
        if (c == 2)
        {
            adj[b].push_back({ a, 0 });
            adj[b + n].push_back({ a + n,price[a] - price[b] });
            adj[b + n + n].push_back({ a + n + n, 0 });
        }
    }

    cout << ShortestPath(adj, 1) << endl;
}