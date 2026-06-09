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

vector<int> dis(201 * 8192, INT_MAX);
class com
{
public:
    bool operator() (int a, int b)
    {
        return dis[a] > dis[b];
    }
};
const int mx = 8192;
int ShortestPath(const vector<vector<pair<int, int>>>& adj, int s, int target, int n)
{
    priority_queue < int, vector<int>, com> q;
    vector<bool> visited(adj.size());

    
    q.emplace(s);
    dis[s] = 0;

    while (!q.empty())
    {
        auto t = q.top();
        int d = dis[t], x = t;
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
            q.push(t);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < mx; ++i)
        ans = min(dis[target + n * i], ans);
    if (ans == INT_MAX) ans = -1;
    return ans;
}

bool cover(int a, int b)
{
    bool cover = true;
    while (b)
    {
        if ((b & 1) && !(a & 1))
            return false;
        a >>= 1;
        b >>= 1;
    }
    return true;
}
int main()
{
    int n = read(),m = read(), p =read(), k =read();
    vector<vector<pair<int, int>>> adj(n * (mx + 1));
    for (int i = 0; i < k; ++i)
    {
        int w = read(), q = read();
        int m = 0;
        for (int j = 0; j < q; ++j)
        {
            int t = read();
            m = m | (1 << (t - 1));
        }
        for (int i = 0; i < mx; ++i)
            adj[i * n + w].push_back({ (i | m) * n + w, 0 });
    }
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), w= read(), s = read(), m = 0;
        while (s--)
        {
            int t = read();
            m |= (1 << (t - 1));
        }
        for (int i = 0; i < mx; ++i)
        {
            if (cover(i, m))
            {
                adj[a + i * n].push_back({b + i * n,w});
                adj[b + i * n].push_back({a + i * n,w});
            }
        }
    }
    write(ShortestPath(adj, 1, n, n));
}
