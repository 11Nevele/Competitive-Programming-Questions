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
        return d < other.d;
    }
};

void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<int>& dis,vector<int>&arr)
{
    priority_queue <node> q;
    vector<bool> visited(adj.size());

    for(int i = 1; i < arr.size(); ++i)
		q.push({ i, arr[i]}), dis[i] = arr[i];
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
            if (dis[t] >= d + w)
                continue;
            dis[t] = d + w;
            q.push({ t, dis[t] });
        }
    }
}
int main()
{
	int n = read(), m = read();
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> dis(n + 1, 0);
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; ++i)
		arr[i] = read();
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read(), c =read();
		adj[a].push_back({ b, -c });
		adj[b].push_back({ a, -c });
	}
	ShortestPath(adj, dis, arr);
	for (int i = 1; i <= n; ++i)
		write(dis[i]), putchar('\n');
    return 0;
}