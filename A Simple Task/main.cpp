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
bool adj[20][20];
int ans = 0;
vector<vector<LL>> dp(600000, vector<LL>(20, 0));
bool check(int x, int pre)
{
    int begin = -1, cnt = 0;
    for (int i = 19; i >= 0; --i)
        if ((1 << i) & x)
        {
            ++cnt;
            begin = i;
        }
    return cnt > 2 && adj[begin][pre];

}

int main()
{
    int n = read(), m = read();
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read();
        --a, --b;
        adj[a][b] = true, adj[b][a] = true;
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = 1;
    for (int i = 1; i <= (1 << n); ++i)
    {
        int lowbit = log2(i & -i);
        for (int pre = lowbit; pre < n; ++pre)
        {
            if (!((1 << pre) & i) || !dp[i][pre]) continue;
            if (check(i, pre)) ans += dp[i][pre];
            for (int j = lowbit + 1; j < n; ++j)
            {
                if ((1 << j) & i) continue;
                if (adj[pre][j]) dp[(1 << j) | i][j] += dp[i][pre];
            }
        }
    }
    write(ans / 2), putchar('\n');
}
