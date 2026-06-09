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
vector<vector<int>> gift(501, vector<int>(501)), giftPos(501, vector<int>(501)), v(501, vector<int>(501));
int n;
int dfs(int n, int target)
{
    if (v[target][n])
        return 0;
    v[target][n] = true;
    if (giftPos[n][target] < giftPos[n][n])
        return 1;
    for (int i = 1; i < giftPos[n][n]; ++i)
    {
        int temp = dfs(gift[n][i], target);
        if (temp)
            return 1;
    }
    return 0;
}

int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = read();
            gift[i][j] = t;
            giftPos[i][t] = j;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int t = false;
        for (int j = 1; j < giftPos[i][i]; ++j)
        {
            vector<bool> v(n + 1);
            if (dfs(gift[i][j], i))
            {
                t = true;
                write(gift[i][j]);
                putchar('\n');
                break;
            }
        }
        if (!t)
        {
            write(i);
            putchar('\n');
        }
    }
}
