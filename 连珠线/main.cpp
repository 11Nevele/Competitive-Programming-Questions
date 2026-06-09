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
#include <memory>
#include <cstring>
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
const int R = 0, B = 1;
LL dp[500000][2];
pair<LL, LL> dif[200001][2];
vector<LL> contribution[200001];
vector<pair<LL, LL>> adj[200001];
void solve(int x, int p)
{
    dif[x][0] = { -INT_MAX,0 }, dif[x][1] = { -INT_MAX, 0 };

        for (int t = 0; t < adj[x].size(); ++t)
        {
            LL j = adj[x][t].first, d = adj[x][t].second;
            if (j == p) continue;

            solve(j, x);
            LL r = dp[j][R], b = dp[j][B] + d, m = max(r, b);
            LL tdif = (r + d) - m;
            if (tdif >= dif[x][0].first)
                dif[x][1] = dif[x][0], dif[x][0].first = tdif, dif[x][0].second = j;
            else if (tdif >= dif[x][1].first)
                dif[x][1].first = tdif, dif[x][1].second = j;

            contribution[x][t] = m;
            dp[x][R] += m;
        }
        dp[x][B] = dp[x][R] + dif[x][0].first;
}
LL ans = 0;
void changeRoot(int x, int p)
{
    for (int i = 0 ; i <adj[x].size(); ++i)
    {
        int j = adj[x][i].first, d = adj[x][i].second;
        if (j == p) continue;

        LL ox1 = dp[x][0], ox2 = dp[x][1], oj1 = dp[j][0], oj2 = dp[j][1];
        pair<LL, LL> odif1 = dif[j][0], odif2 = dif[j][1];


        dp[x][R]  -= contribution[x][i], dp[x][B] = dp[x][R];
        
        
        if (j == dif[x][0].second)
            dp[x][B] = dp[x][B] + dif[x][1].first;
        else
            dp[x][B] = dp[x][B] + dif[x][0].first;
            
        
        LL r = dp[x][R], b = dp[x][B] + d;
        dp[j][R] = max(r, b) + dp[j][R];

        ans = max(dp[j][R], ans);


        {
            LL m = max(r, b), tdif = (r + d) - m;
            if (tdif >= dif[j][0].first)
                dif[j][1] = dif[j][0], dif[j][0].first = tdif, dif[j][0].second = x;
            else if (tdif >= dif[j][1].first)
                dif[j][1].first = tdif, dif[j][1].second = x;
        }
        changeRoot(j, x);

        dif[j][0] = odif1, dif[j][1] = odif2;
        dp[x][0] = ox1, dp[x][1] = ox2, dp[j][0] = oj1, dp[j][1] = oj2;
    }

}

int main()
{
    int n = read();
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
        contribution[a].push_back(0);
        contribution[b].push_back(0);
    }
    solve(1, -1);
    dp[1][B] = 0;
    ans = dp[1][R];
    changeRoot(1, -1);
    cout << ans << endl;
}
