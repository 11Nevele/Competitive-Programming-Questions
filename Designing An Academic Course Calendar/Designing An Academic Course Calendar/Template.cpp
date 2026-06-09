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
vector<vector<int>> adj(200005), adj2(200005);
vector<bool> used(200005, false);
vector<int> arr;
void dfs(int x)
{
	if (used[x])
		return;
	used[x] = true;
    for(int i : adj2[x])
		dfs(i);
}
class node
{
public:
    int target;
    int dis;
    bool operator <(const node& other) const
    {
        //return dis < other.dis  large first
        return dis > other.dis;
    }
};
vector<vector<int>> ans(200005);
int Topological()
{
    vector<int> in(adj.size());
    for (int i = 0; i < adj.size(); ++i)
        for (auto j : adj[i])
            ++in[j];
    queue<node> q;
    bool flag = false;
    int x = 0;
    for (int i = 1; i < adj.size(); ++i)
        if (!in[i] && used[i])
			ans[x].push_back(i), q.push({i,0}), flag = true;
    while (flag)
    {
        flag = false;
        for (int i : ans[x])
        {
            for (int j : adj[i])
                if (--in[j] == 0 && used[j])
                    ans[x + 1].push_back(j), flag = true;
        }
        ++x;
    }
    return x;
}
int main()
{
    int n = read(), m = read(), k = read();
    for(int i = 0; i < k; ++i)
		arr.push_back(read());
	for (int i = 0; i < m; i++)
	{
		int a = read(), b = read();
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}
	for (int i = 0; i < k; ++i)
		dfs(arr[i]);
    int t =Topological();
	cout << t << endl;
	for (int i = 0; i < t; ++i)
	{
		sort(ans[i].begin(), ans[i].end());
		if (ans[i].size() == 0)
			break;
		for (int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
    return 0;
}