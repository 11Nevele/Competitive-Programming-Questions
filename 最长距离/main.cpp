#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
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

int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0, - 1} };
long double bfs(vector<vector<int>>& map, int n, int m, int r, int c, int maxK)
{
    queue<pair<int, int>> qCord;
    queue<int> qK;
    bool v[40][40][40]{};
    qCord.push({ r,c });
    if (map[r][c])
    {
        if (maxK == 0)
            return 0;
        qK.push(1);
        v[r][c][1] = true;
    }
    else
    {
        qK.push(0);
        v[r][c][0] = true;
    }
    long double ans = 0;
    while (!qCord.empty())
    {
        auto cord = qCord.front();
        int k = qK.front();
        qCord.pop(), qK.pop();

        ans = max(ans, sqrtl(powl(cord.first - r, 2) + powl(cord.second - c, 2)));

        for (auto& i : dir)
        {
            int tr = cord.first + i[0], tc = cord.second + i[1];
            if (tr >= n || tr < 0 || tc >= m || tc < 0)
                continue;
            if (map[tr][tc])//obstacle
            {
                if (k < maxK && !v[tr][tc][k + 1])
                {
                    v[tr][tc][k + 1] = true;
                    qCord.push({ tr,tc });
                    qK.push(k + 1);
                }
            }
            else if(!v[tr][tc][k])
            {
                v[tr][tc][k] = true;
                qCord.push({ tr,tc });
                qK.push(k);
            }
        }
    }
    return ans;
}
int main()
{
    int n = read(), m = read(), k = read();
    vector<vector<int>> map(n, vector<int>(m));
    for (auto& i : map)
    {
        for (auto& j : i)
            j = getchar() - '0';
        getchar();
    }
    long double ans = 0;
    for(int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            ans = max(ans, bfs(map, n, m, i, j, k));
        }
    cout << fixed << setprecision(6) << ans << endl;
}
