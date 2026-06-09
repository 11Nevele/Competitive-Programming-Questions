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
int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
int n, m;
void dfs(int r, int c, vector<vector<bool>>& grid, vector<vector<int>>& gridID, int id)
{
    gridID[r][c] = id;
    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr <= n && nc <= m && nr > 0 && nc > 0 && grid[nr][nc] && gridID[nr][nc] == 0)
        {
            dfs(nr, nc, grid, gridID, id);
        }
    }
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

void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<int>& dis, int s)
{
    priority_queue <node> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.push({ s, 0 });
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
            dis[t] = d + w;
            q.push({ t, dis[t] });
        }
    }
}

int main()
{
    n = read(), m = read();
    vector<vector<bool>> grid(n + 1, vector<bool>(m + 1));
    vector<vector<int>> gridID(n + 1, vector<int>(m + 1));
    for (int i = n; i > 0; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char c = getchar();
            grid[i][j] = c == '#';
        }
        getchar();
    }

    int cnt = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (grid[i][j] && gridID[i][j] == 0)
                dfs(i, j, grid, gridID, cnt++);

    vector<vector<pair<int, int>>> adj(cnt);
    for (int c = 1; c <= m; ++c)
    {
        int pre = 0;
        for (int r = 1; r <= n; ++r)
        {
            if (gridID[r][c] == 0)
                continue;
            if (r - pre <= 1 && pre != 0)
            {
                pre = r;
                continue;
            }
            adj[gridID[pre][c]].push_back({ gridID[r][c], r - pre - 1});
            pre = r;
        }
    }
    vector<int> dis(cnt +1);
    vector<vector<bool>> ans(n +1, vector<bool>(m +1));
    ShortestPath(adj, dis, 0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!grid[i][j])continue;
            ans[i - dis[gridID[i][j]]][j] = true;
        }
    }
    for (int i = n; i > 0; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            putchar(ans[i][j] ? '#' : '.');
        }
        putchar('\n');
    }
    return 0;
}