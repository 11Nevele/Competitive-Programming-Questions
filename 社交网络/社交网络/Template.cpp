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
void Floyd(const vector<vector<pair<int, int>>>& adj, vector<vector<LL>>& dis, vector<vector<int>>& pre, vector<vector<LL>>& cnt)
{
    int n = adj.size() - 1;
    fill(dis.begin(), dis.end(), vector<LL>(n + 1, INT_MAX));
    fill(pre.begin(), pre.end(), vector<int>(n + 1, -1));
    for (int i = 1; i <= n; ++i)
    {
        for (auto& j : adj[i])
        {
            dis[i][j.first] = min((LL)j.second, dis[i][j.first]);
            pre[i][j.first] = i;
            cnt[i][j.first] = 1;
        }
        cnt[i][i] = 1;
        dis[i][i] = 0;
    }

    for (int t = 1; t <= n; ++t)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (i == t)
                continue;
            for (int j = 1; j <= n; ++j)
            {
                if (j == t || i == j)
                    continue;
                LL time = dis[i][t] + dis[t][j];
                if (time < dis[i][j])
                {
                    dis[i][j] = time;
                    pre[i][j] = pre[t][j];
					cnt[i][j] = cnt[i][t] * cnt[t][j];
                }
                else if (time == dis[i][j])
                {
					cnt[i][j] += cnt[i][t] * cnt[t][j];
                }
            }
        }
    }
}
vector<vector<pair<int, int>>> adj(105);
vector<vector<LL>> dis(105, vector<LL>(105));
vector<vector<int>> pre(105, vector<int>(105));
void dfs(int s, int x, vector<int> & cnt)
{
    for (pair<int,int> i : adj[x])
    {
		if (dis[s][i.first] == dis[s][x] + i.second)
		{
            cnt[i.first]++;
			dfs(s, i.first, cnt);
		}

    }
}
int main()
{
    int n = read(), m = read();
	
	for (int i = 0; i < m; ++i)
	{
		int u = read(), v = read(), w = read();
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}
	vector<vector<LL>> cnt(105, vector<LL>(105, 0));
	Floyd(adj, dis, pre, cnt);
    for (int t = 1; t <= n; ++t)
    {
        double ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i == t) continue;
            for (int j = 1; j <= n; ++j)
            {
                if (j == t) continue;
				if (dis[i][j] == dis[i][t] + dis[t][j])
				    ans += (double)(cnt[i][t] * cnt[t][j]) / (double)cnt[i][j];
            }
        }
		cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}