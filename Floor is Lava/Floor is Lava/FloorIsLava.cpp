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
    LL d;
    bool operator <(const node& other) const
    {
        return d > other.d;
    }
};

void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<LL>& dis, int s)
{
    priority_queue <node> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), LL_MAX);
    q.push({ s, 0 });
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        LL d = t.d, x = t.x;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto i : adj[x])
        {
            LL t = i.first, w = i.second;
            if (dis[t] <= d + w)
                continue;
            dis[t] = d + w;
            q.push({ (int)t, dis[t] });
        }
    }
}
int main()
{
    int n = read(), m = read();
    vector < vector<pair<int, int>>> adj(n + 1);
    vector<unordered_map<int, int>> mp(n + 1);
    int node = 1;
	for (int i = 0; i < m; i++)
	{
		int a = read(), b = read(), c = read();
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
    adj[1].push_back({ 0, 1 });
    for (int i = 1; i <= n; ++i)
    {
        sort(adj[i].begin(), adj[i].end());
        for (int j = 0; j < adj[i].size(); ++j)
        {
			if (mp[i].find(adj[i][j].first) == mp[i].end())
                mp[i][adj[i][j].first] = node++;
        }
    }
    vector<vector<pair<int,int>>> adj2(node + 1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < adj[i].size() - 1; ++j)
		{
            int curT = adj[i][j].first, nxtT = adj[i][j + 1].first;
			int cur = mp[i][curT], nxt = mp[i][nxtT];
			
			int dif = abs(curT - nxtT);
			adj2[cur].push_back({nxt, dif});
			adj2[nxt].push_back({ cur, dif });


            adj2[cur].push_back({ mp[adj[i][j].second][curT], 0 });
		}
        int curT = adj[i].back().first;
        int cur = mp[i][curT];
		adj2[cur].push_back({ mp[adj[i].back().second][curT], 0 });
	}
    vector<LL> dis(node + 1);
	ShortestPath(adj2, dis, 1);
    LL mn = LL_MAX;
    for (auto j : adj[n])
    {
		mn = min(mn, dis[mp[n][j.first]]);
    }
    write(mn), putchar('\n');
    return 0;
}

/*
* 5 7
1 2 3
2 3 2
1 3 6
3 4 3
4 5 7
2 4 1
2 5 10
*/