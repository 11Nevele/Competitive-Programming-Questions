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

vector<vector<int>> adj(100001), idAdj(100001);
vector<unordered_map<int, int>> nodeToInd(100001);
vector<pair<int, int>> edges;
vector<int> nxt;
vector<bool> visEdge;
vector<int> ans(100001);
void dfs(int x, int cnt, int s, vector<int>&nodes)
{
    
    if (x == s && cnt > 0)
        return;
    nodes.push_back(edges[x].first);
    if (!visEdge[x])
    {
        ++cnt;
		visEdge[x] = true;
    }
    dfs(nxt[x], cnt, s, nodes);
}
int main()
{
    int n = read();
    int m = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t = read();
		for (int j = 0; j < t; ++j)
        {
            int x = read();
            adj[i].push_back(x);
			edges.push_back({ i, x });
            idAdj[i].push_back(m++);
            nodeToInd[i][x] = j;
        }
    }
	nxt.resize(edges.size(), -1);
    for (int i = 0; i < edges.size(); ++i)
    {
		int u = edges[i].first;
		int v = edges[i].second;
        int ind = nodeToInd[v][u];
        ind = (ind - 1 + adj[v].size()) % adj[v].size();
		nxt[i] = idAdj[v][ind];
    }
	visEdge.resize(edges.size());
	for (int i = 0; i < edges.size(); ++i)
	{
		if (!visEdge[i])
		{
            vector<int> nodes;
			dfs(i, 0, i, nodes);
            int l = nodes.size();
			for (int i = 0; i < l; ++i)
				nodes.push_back(nodes[i]);
            unordered_map<int, int> pre;

			for (int j = 0; j < nodes.size(); ++j)
			{
                if (pre.find(nodes[j]) != pre.end())
                {
                    ans[nodes[j]] = max(ans[nodes[j]], j - pre[nodes[j]]);
                    
                }
                pre[nodes[j]] = j;
			}
		}
	}
    int q = read();
    while (q--)
    {
        int x = read();
        write(ans[x]), putchar('\n');
    }
    return 0;
}