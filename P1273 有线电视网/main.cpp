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
//bool com(const pair<int,int> &a)
int n, m;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> dp;
vector<int> value;

int solve(int x)
{
    if (x >= m)
    {
        return 1;
    }
    int childCnt = 0;
    vector<int> tdp(m + 1);
    dp[x][0] = 0;
    for (int i = 0; i < adj[x].size(); ++i)
    {
        int t = adj[x][i].first;
        
        int tempChild = solve(t);
        
        for (int j = 0; j <= m; ++j) tdp[j] = dp[x][j];
        for (int j = 0; j <= childCnt; ++j)
        {
            for (int k = 0; k <= tempChild; ++k)
            {
                dp[x][j + k] = min(dp[x][j + k], tdp[j] + dp[t][k] + adj[x][i].second);
            }
        }
        childCnt += tempChild;
        
    }
    return childCnt;
}

int main()
{
    n = read(), m = read();
    adj.resize(n + 1), dp.resize(n + 1,vector<int>(m+ 1, INT_MAX-300000));
    for (int i = 1; i <= n - m; ++i)
    {
        int k = read();
        adj[i].resize(k);
        for (auto& i : adj[i])
            i.first = read(), i.second = read();
    }
    for (int i = m; i <= n; ++i)
    {
        dp[i][0] = 0;
        dp[i][1] = -read();

    }
    solve(1);
    int i;
    for (i = m; i > 0; --i)
        if (dp[1][i] <= 0)
            break;
    cout << i << endl;
    return 0;
}
