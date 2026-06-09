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
char c[4]{ 'a','q','k','j' };
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
    queue <node> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.push({ s, 0 });
    pre[s] = s;
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        int d = t.d, x = t.x;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto i : adj[x])
        {
            int t = i.first, w = i.second;
            if (dis[t] <= d + 1)
                continue;
            pre[t] = w;
            dis[t] = d + 1;
            q.push({ t, dis[t] });
        }
    }
}
void solve()
{
    int n = read();
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> value(4, vector<int>(n + 1));
    for (int i = 1; i < 4; ++i)
        for (int j = 1; j <= n; ++j)
        {
            value[i][j] = read();
            adj[i * n + j].push_back({ j, 0 });
        }
    for (int i = 1; i <= 3; ++i)
    {
        vector<int> s;
        for (int j = n; j >= 0; --j)
        {
            while(s.)
        }
    }
    vector<int> dis(n + 1), pre(n + 1);
    ShortestPath(adj, dis, pre, 1);
    if (pre[n] == 0)
    {
        cout << "NO\n";
        return;
    }
    vector<int> path;
    int cur = n;
    while (cur != 1)
    {
        cur = pre[cur];
        if (cur > n)
            path.push_back(cur);
    }
    cout << "YES\n";
    write(dis[n]), putchar('\n');
    for (int i = path.size() - 1; i >= 0; --i)
    {
        int t = path[i];
        int group = ceil((double)t / n) - 1;
        putchar(c[group]), putchar(' '), write(t - (group * n)), putchar('\n');
    }
}
int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}