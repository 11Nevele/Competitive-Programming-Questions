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
#include<fstream>
#include <cmath>
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
vector<pair<int,int>> adj[301];
LL dp[305][2][305];
LL zeroCost[305];
int N, M, K;
LL pre[305];
void solve(int x, int k, bool b, int parent)
{
    if (dp[x][b][0] != INT_MAX)
        return;
    if (adj[x].size() == 1)
    {
        dp[x][b][0] = 0;
        return;
    }
    dp[x][b][0] = zeroCost[x];
    for (auto& i : adj[x])
    {
        if (i.first == parent)
            continue;
        solve(i.first, k - 1, true, x);
        solve(i.first, k, false, x);
        for (int j = 0; j <= k; ++j)
        {
            for (int l = 0; l <= j; ++l)
            {
                LL take = INT_MAX, ntake = dp[i.first][0][l] + dp[x][b][j - l];
                if (l > 0)
                    take = dp[i.first][1][l - 1] + dp[x][b][j];
                if (b) take += i.second;
                if (!b && M == 2) ntake += i.second;
                dp[x][b][j] = min(dp[x][b][j], min(take, ntake));
            }
        }
    }
}
LL Init(int x, int p)
{
    LL sum = 0;
    for (auto& i : adj[x])
    {
        if (p == i.first)continue;
        sum += Init(i.first, x) + i.second;
    }
    zeroCost[x] = sum;
    return sum;
}
int main()
{
    ifstream fin("dragon.in");
    ofstream fout("dragon.out");
    
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= K; ++j)
            dp[i][1][j] = INT_MAX, dp[i][0][j] = INT_MAX;
    for (int i = 1; i < N; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    if (M == 2)
        Init(1, -1);
    solve(1, K - 1, true, -1);
    cout << dp[1][1][K - 1] << endl;
}
