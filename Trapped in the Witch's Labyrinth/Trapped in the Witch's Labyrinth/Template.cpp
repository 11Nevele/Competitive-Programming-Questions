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
int n, m;
//0 no visit
//1 visited
//2 escape
//3 loop
//other ?
void dfs(vector<vector<int>>& v, vector<vector<char>>& mp, int r, int c)
{
    int nr = r, nc = c;
    switch (mp[r][c])
    {
    case 'U':nr--; break;
    case 'D':nr++; break;
    case 'L':nc--; break;
    case 'R':nc++; break;
    }
    if (nr < 1 || nr > n || nc < 1 || nc > m)
    {
        v[r][c] = 2;
        return;
    }
    if (mp[nr][nc] == '?')
    {
        v[r][c] =-( nr * m + nc);
        return;
    }
    if (v[nr][nc] == 1)
    {
        v[r][c] = 3;
        return;
    }
    if (v[nr][nc] > 1 || v[nr][nc] < 0)
    {
        v[r][c] = v[nr][nc];
        return;
    }
    v[r][c] = 1;
    dfs(v, mp, nr, nc);
    v[r][c] = v[nr][nc];
}
void solve()
{
    n = read(), m = read();
    vector<vector<char>> mp(n + 2, vector<char>(m + 2));
    vector<vector<int>> v(n + 2, vector<int>(m + 2));
    unordered_map<int, int> ump;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            mp[i][j] = getchar();
            if (mp[i][j] == '?')
                ump[i * m + j] = 0;
        }
            
        getchar();
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            if (!v[i][j] && mp[i][j] != '?')
                dfs(v, mp, i, j);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (v[i][j] == 3)
                ++ans;
            else if (v[i][j] < 0)
            {
                int t = -v[i][j];
                ump[t]++;
            }
        }
    }

    for (auto t : ump)
    {
        int r = (t.first - 1) / m, c = t.first - r * m, num = t.second;
        if (num > 0)
        {
            ans += num + 1;
        }
        else
        {
            int mx = 0;
            int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
            for (int i = 0; i < 4; ++i)
            {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (mp[nr][nc] == '?')
                    mx = 1;
                else if (v[nr][nc] == 3)
                    mx = 1;
                else if (v[nr][nc] < 0)
                    mx = 1;
            }
            ans += mx;
        }
    }
    write(ans), putchar('\n');
}
int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}