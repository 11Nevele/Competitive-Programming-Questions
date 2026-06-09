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

//try the easy thing first, get to the n^4 solution
//then optomize with sorting

LL dp[505][505], sum[505][505], rnk[505][505];
double avg1[505][505];
double avg2[505][505];

void copy()
{
    for (int i = 0; i < 505; ++i)
        for (int j = 0; j < 505; ++j)
            sum[i][j] = dp[i][j];
}
const LL mod = 1e9 + 7;
int main()
{
    int n = read();
    vector<double> a1(n + 1), a2(n + 1);
    for (int i = 1; i <= n; ++i)
        a1[i] = read();
    for (int i = 1; i <= n; ++i)
        a2[i] = read();
    for (int i = 1; i <= n; ++i)
        a1[i] += a1[i - 1], a2[i] += a2[i - 1];
    vector<vector<pair<double, int>>> m1(505), m2(505);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            avg1[i][j] = (a1[j] - a1[i - 1]) / (j - i + 1);
            m1[j].push_back({ avg1[i][j], i });
            avg2[i][j] = (a2[j] - a2[i - 1]) / (j - i + 1);
            m2[j].push_back({ avg2[i][j], i });
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(m1[i].begin(), m1[i].end());
        sort(m2[i].begin(), m2[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m2[i].size(); ++j)
            rnk[i][m2[i][j].second] = j;
    }



    dp[0][0] = 1;
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < m1[i].size(); ++j)
        {
            for (int t = 0; t <= n; ++t)
                sum[j][t] = dp[m1[i][j].second - 1][t];
        }
        for (int j = 1; j < m1[i].size(); ++j)
        {
            for (int t = 0; t <= n; ++t)
                sum[j][t] = (sum[j][t] +  sum[j - 1][t]) % mod;
        }
        for (int j = 1; j <= n; ++j)
        {
            LL cur = 0;
            int ind = 0;
            for (int t = 0; t < m2[j].size(); ++t)
            {
                while (ind < m1[i].size() && m1[i][ind].first <= m2[j][t].first)
                {
                    ++ind;
                }
                if (ind > 0)
                    cur = (cur + sum[ind - 1][m2[j][t].second - 1]) % mod;
            }
            dp[i][j] = cur;
        }

      
    }
    write(dp[n][n]), putchar('\n');
    return 0;
}