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
#include <cstring>
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

vector<vector<int>> adj;
vector<int> value;
vector<bool> state;
LL dp[200005][3][2];
//t: 0 parent 1 self 2 child
//s: true spread false don't
LL solve(int x, int t, bool s, int p)
{

    if (dp[x][t][s] != -1)
        return dp[x][t][s];

    if (t == 0 && s == false)
    {
        dp[x][t][s] = 0;
        LL mi = 0;
        for (int& i : adj[x])
        {
            if (i == p)
                continue;
            mi += min(min(solve(i, 1, false, x), solve(i, 2, false, x)),
                min(solve(i, 1, true, x), solve(i, 2, true, x)));
        }
        dp[x][t][s] += mi;
        return dp[x][t][s];
    }
    if (t == 1 && s == false)
    {
        if (state[x])
            dp[x][t][s] = 0;
        else
            return INT_MAX;
        LL mi = 0;
        for (int& i : adj[x])
        {
            if (i == p)
                continue;
            mi += min(min(solve(i, 1, false, x), solve(i, 2, false, x)),
                min(solve(i, 1, true, x), solve(i, 2, true, x)));
        }
        dp[x][t][s] += mi;
        return dp[x][t][s];
    }
    if (t == 2 && s == false)
    {
        dp[x][t][s] = 0;
        LL minDif = INT_MAX;
        bool f = true;
        for (int& i : adj[x])
        {
            if (i == p)
                continue;
            LL a1 = min(solve(i, 1, false, x), solve(i, 2, false, x));
            LL a2 = min(solve(i, 1, true, x), solve(i, 2, true, x));
            if (a2 <= a1)
            {
                dp[x][t][s] += a2;
                f = false;
            }
            else
            {
                dp[x][t][s] += a1;
                minDif = min(a2 - a1, minDif);
            }
        }
        if (f)
            dp[x][t][s] += minDif;

        return dp[x][t][s];
    }
    if (t == 0 && s == true)
    {
        dp[x][t][s] = 0;
        for (int& i : adj[x])
        {
            if (i == p)
                continue;
            dp[x][t][s] += min(min(solve(i, 1, false, x), solve(i, 0, false, x)),
                min(solve(i, 1, true, x), solve(i, 0, true, x)));
        }
        dp[x][t][s] += value[x];
        return dp[x][t][s];
    }
    if (t == 1 && s == true)
    {
        if (state[x])
            dp[x][t][s] = value[x];
        else
            return INT_MAX;
        LL mi = 0;
        for (int& i : adj[x])
        {
            if (i == p)
                continue;
            mi += min(min(solve(i, 1, false, x), solve(i, 0, false, x)),
                min(solve(i, 1, true, x), solve(i, 0, true, x)));
        }
        dp[x][t][s] += mi;
        return dp[x][t][s];
    }
    if (t == 2 && s == true)
    {
        dp[x][t][s] = 0;
        LL minDif = INT_MAX;
        bool f = true;
        for (int& i : adj[x])
        {
            if (i == p)
                continue;
            LL a1 = min(solve(i, 1, false, x), solve(i, 0, false, x));
            a1 = min(a1, solve(i, 0, true, x));
            a1 = min(a1, solve(i, 0, false, x));
            LL a2 = min(solve(i, 1, true, x), solve(i, 2, true, x));
            if (a2 <= a1)
            {
                dp[x][t][s] += a2;
                f = false;
            }
            else
            {
                dp[x][t][s] += a1;
                minDif = min(a2 - a1, minDif);
            }
        }
        if (f)
            dp[x][t][s] += minDif;
        dp[x][t][s] += value[x];
        return dp[x][t][s];
    }

}


int main()
{
    int n = read();
    adj.resize(n + 1);
    value.resize(n + 1), state.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        if (c == 'Y')
            state[i] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        value[i] = read();
    }
    LL ans = INT_MAX;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < 3; ++i)
        ans = min(ans, min(solve(1, i, true, -1), solve(1, i, false, -1)));
    cout << ans << endl;
}
