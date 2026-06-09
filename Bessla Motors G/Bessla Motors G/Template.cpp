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
    int s;
    LL d;
    bool operator <(const node& other) const
    {
        return d > other.d;
    }
};
vector<unordered_set<int>> vis(100005);
void ShortestPath(const vector<vector<pair<int, int>>>& adj, int s, LL r, int k)
{
    priority_queue <node> q;

    for (int i = 1; i <= s; ++i)
    {
        q.push({ i,i,0 });
    }

    while (!q.empty())
    {
        auto t = q.top();
        LL d = t.d;
        int x = t.x, src = t.s;
        q.pop();
        if (vis[x].size() >= k || vis[x].find(src) != vis[x].end())
            continue;
        vis[x].insert(src);
        
        for (auto i : adj[x])
        {
            int t = i.first;
            LL w = i.second;
            if (d + w > r)
                continue;
            if (vis[t].size() >= k || vis[t].find(src) != vis[t].end())
                continue;
            q.push({ t, src, d + w });
        }
    }
}
int main()
{
    int n = read(), m = read(), c = read(), r = read(), k = read();
    vector<vector<pair<int, int>>> adj(n + 1);
    while (m--)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    ShortestPath(adj, c, r, k);
    vector<int> ans;
    for (int i = c + 1; i <= n; ++i)
        if (vis[i].size() >= k)
            ans.push_back(i);
    write((LL)ans.size()), putchar('\n');
    for (int i : ans)
        write(i), putchar('\n');
    return 0;
}