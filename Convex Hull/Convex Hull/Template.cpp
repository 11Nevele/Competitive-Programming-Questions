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
    int d;
    bool operator <(const node& other) const
    {
        return d > other.d;
    }
};

void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<int>& dis, vector<int>& pre, int s)
{
    priority_queue <node> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.push({ s, 0 });
    pre[s] = s;
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
            int t = i.first, w = i.second;
            if (dis[t] <= d + w)
                continue;
            pre[t] = x;
            dis[t] = d + w;
            q.push({ t, dis[t] });
        }
    }
}
int main()
{
    int k = read(), n = read(), m = read();
	vector<vector<pair<int, int>>> adj(n * (k + 1) + 1);
	vector<int> dis(n * (k + 1) + 1), pre(n * (k + 1) + 1);
    while (m--)
    {
        int a = read(), b = read(), t = read(), h = read();
        for (int i = h + 1; i <= k; ++i)
        {
			adj[a + n * i].push_back({ b + n * (i - h), t });
			adj[b + n * i].push_back({ a + n * (i - h), t });
		}
	}
    int a = read(), b = read();
	ShortestPath(adj, dis, pre, n * k  + a);
	int ans = INT_MAX;
    for (int i = 1; i <= k; ++i)
        ans = min(ans, dis[n * i + b]);
    if (ans == INT_MAX)
        write(-1);
    else
		write(ans);
    putchar('\n');
    return 0;
}