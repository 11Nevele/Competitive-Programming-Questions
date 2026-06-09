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
bool adj[105][105];
bool target[105][105];
int n, m;
struct node
{
    int x, y, a, b;
};
vector<node> ans;
int dfs(int x, int  p, vector<bool>& v)
{
    if (v[x])
    {
        if (target[x][p] == false)
        {
            adj[x][p] = false;
            adj[p][x] = false;
            ans.back().x = x;
            ans.back().y = p;
            return 2;
        }
        return 1;
    }
	v[x] = true;
    for (int i = 1; i <= n; i++)
    {
        if (adj[x][i] && i != p)
        {
            int r = dfs(i, x, v);
            if (r == 1)
            {
                if (target[x][p] == false)
                {
                    adj[x][p] = false;
                    adj[p][x] = false;
                    ans.back().x = x;
                    ans.back().y = p;
                    return 2;
                }
                return 1;
            }
            else if (r == 2)
                return 2;
        }

    }
}

bool FindLoop()
{
    vector<bool> v(n + 1);

    ans.push_back({});
	
    dfs(1, 0, v);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!adj[i][j] && target[i][j])
			{
				adj[i][j] = true;
				adj[j][i] = true;
				ans.back().a = i;
				ans.back().b = j;
				return false;
			}
		}
	}
	return true;
}
bool isFinished()
{
    bool finished = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] != target[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    n = read();
	for (int i = 0; i < n; i++)
	{
		int a = read(), b = read();
		adj[a][b] = true;
		adj[b][a] = true;
	}
    for (int i = 0; i < n; i++)
    {
		int a = read(), b = read();
		target[a][b] = true;
		target[b][a] = true;
    }
    while (!isFinished())
    {
        FindLoop();
    }
    write((int)ans.size());
	putchar('\n');
	for (auto& i : ans)
	{
		write(i.x);
		putchar(' ');
		write(i.y);
		putchar(' ');
		write(i.a);
		putchar(' ');
		write(i.b);
		putchar('\n');
	}
    return 0;
}