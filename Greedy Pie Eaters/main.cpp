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
class H
{
public:
    size_t operator()( pair<int, int> const a) const
    {
        size_t h1 = hash<int>()(a.first), h2 = hash<int>()(a.second);
        if (h1 == h2)
            return h1;
        else
            return h1 ^ h2;
    }

};
vector<vector<int>> dp1(305, vector<int>(305, -1));
int dp2[305][305][305];
vector<int> v(100005);
vector < pair<int, int>> arr(100005);
unordered_map<pair<int,int>, int, H> ma;
int n,m;
int solve(int l, int r)
{
    if (l > r)
        return 0;
    if (dp1[l][r] != -1)
        return dp1[l][r];
    dp1[l][r] = 0;
    for (int i = l; i <= r; ++i)
    {
        int t = solve(l, i - 1) + solve(i + 1, r);
        dp1[l][r] = max(dp1[l][r], t + dp2[l][r][i]);
    }
    return dp1[l][r];
}

int main()
{
    n = read(), m = read();

    for (int i = 0; i < m; ++i)
    {
        v[i] = read(), arr[i].first = read(), arr[i].second = read();
        ma[{arr[i].first, arr[i].second}] = v[i] ;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j + i <= n; ++j)
        {
            int t = j + i;
            int temp = 0;
            if (ma.find({ j,t }) != ma.end())
            {
                temp = ma[{j,t}];
            }
            for (int k = j; k <= t; ++k)
            {
                dp2[j][t][k] = max(temp, max(dp2[j][t - 1][k],dp2[j + 1][t][k]));
            }
        }
    }
    cout << solve(1, n) << endl;
    
}
