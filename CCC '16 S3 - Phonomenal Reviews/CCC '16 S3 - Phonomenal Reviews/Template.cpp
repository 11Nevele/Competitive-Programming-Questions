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

vector<bool> pho(100005);
vector<vector<int>> adj(100005);
vector<vector<int>> dp(100005, vector<int>(2));
vector<vector< int >> nr(100005,vector<int>(2,-1));
vector<int> contain(100005);


int CheckContain(int x, int p)
{
    if (pho[x])
    {
        contain[x] = INT_MAX;
    }
        
    for (int i : adj[x])
    {
        if (i == p)
            continue;
        int t = CheckContain(i, x);
        if (!t)
            continue;
        if (contain[x])
            contain[x] = INT_MAX;
        else
            contain[x] = t;
    }
    if (contain[x])
        return x;
    else
        return 0;
}
int ReturnNode(int x)
{
    if (x == -1 || !contain[x])
        return 0;
    return dp[x][1] + 2;
}
int NReturnNode(int x)
{
    if (x == -1 || !contain[x])
        return 0;
    return dp[x][0] + 1;
}
void dfs1(int x, int p)
{
    for (int i : adj[x])
    {
        if (i == p || !contain[i])
            continue;
        dfs1(i, x);
        dp[x][1] += dp[i][1] + 2;
    }
    dp[x][0] = dp[x][1];
    for (int i : adj[x])
    {
        if (i == p || !contain[i])
            continue;
        int t = dp[x][1] - ReturnNode(i) + NReturnNode(i);
        if (t < dp[x][0])
            dp[x][0] = t, nr[x][1] = nr[x][0], nr[x][0] = i;
        else if (t < dp[x][1] - ReturnNode(nr[x][1]) + NReturnNode(nr[x][1]))
            nr[x][1] = i;
    }
}
int ans = INT_MAX;

void ChangeRoot(int x, int p)
{
    int b0 = dp[x][0], b1 = dp[x][1];
    int n0 = nr[x][0], n1 = nr[x][1];
    int c = contain[x];
    if (x != 0)
    {
        if (contain[p] == x)
            contain[p] = 0;
        if (contain[x] == 0)
            contain[x] = contain[p];
        else if (contain[x] != INT_MAX && contain[p])
            contain[x] = INT_MAX;
        dp[p][1] = dp[p][1] - ReturnNode(x),
            dp[p][0] = dp[p][0];
        if (nr[p][0] == x)
        {
            int t = nr[p][1];
            dp[p][0] = dp[p][0] - NReturnNode(x) - (ReturnNode(t)) + (NReturnNode(t));
        }
        else
        {
            dp[p][0] -= ReturnNode(x);
        }
        dp[x][1] += ReturnNode(p);
        int tOld = dp[x][0] + ReturnNode(p),
            tNew = dp[x][1] - ReturnNode(p) + NReturnNode(p);
        if (tNew < tOld)
            dp[x][0] = tNew, nr[x][1] = nr[x][0], nr[x][0] = p;
        else
        {
            dp[x][0] = tOld;
            int t = nr[x][1];
            if (tNew < dp[x][1] - NReturnNode(t) + ReturnNode(t))
                nr[x][1] = p;
        }
        
    }
    ans = min(ans, dp[x][0]);
    int bb0 = dp[x][0], bb1 = dp[x][1];
    int nn0 = nr[x][0], nn1 = nr[x][1];
    int cc = contain[x];
    for (int i : adj[x])
    {
        if (i == p || !contain[i])
            continue;
        ChangeRoot(i, x);
        dp[x][0] = bb0, dp[x][1] = bb1;
        nr[x][0] = nn0, nr[x][1] = nn1;
        contain[x] = cc;
    }
    
    dp[x][0] = b0, dp[x][1] = b1;
    nr[x][0] = n0, nr[x][1] = n1;
    contain[x] = c;
}

int main()
{
    int n = read(), m = read();
    for(int i = 0; i < m ; ++i)
        pho[read()] = true;
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    CheckContain(0, -1);
    dfs1(0, -1);
    ChangeRoot(0, -1);
    write(ans), putchar('\n');
    return 0;
}
/*
7 2
0 6
0 1
1 2
2 3
3 4
4 5
5 6

7 2
1 2
0 1
0 2
1 3
1 4
2 5
2 6
*/