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
class Edge
{
public:
    int a, b, w;
};
//return false if negative loop
bool SFPA(vector<vector<pair<int,int>>>& adj, vector<int>& dis, int s, int n)
{
	vector<int> cnt(n + 1);
	vector<bool> vis(n + 1);
	fill(dis.begin(), dis.end(), INT_MAX);
	vector<int> inQueueCnt(n + 1);
	queue<int> q;
	q.push(s);
	vis[s] = true;
	inQueueCnt[s]++;
	dis[s] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (auto &i : adj[u])
		{
			int v = i.first, w = i.second;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
					inQueueCnt[v]++;
					if (++inQueueCnt[v] > n + 1)
						return false;
				}
			}
		}
	}
	return true;
}
int main()
{
    int n = read(), m = read();
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> dis(n + 1);
    for(int i = 0; i < m; ++i)
	{
		int a = read(), b = read(), w = read();
		adj[b].push_back({ a, w });
	}
	for (int i = 1; i <= n; ++i)
		adj[0].push_back({i, 0});
	bool noNegLoop = SFPA(adj, dis, 0, n);
    if (!noNegLoop)
        cout << "NO";
    else
		for (int i = 1; i <= n; ++i)
			cout << dis[i] << " ";
	putchar('\n');
    return 0;
}