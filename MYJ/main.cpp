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


LL dp[55][55][5005], ind[55][55][5005];
pair<int, int> range[55];
int c[5005], vc[5005], ans[5005];

int n,m, maxK = 0;


int cnt[55][5005];  
void solve()
{
    for (int len = 1; len <= n; ++len)
    {
        for (int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            for (int i = l; i <= r; ++i)
                for (int j = 1; j <= maxK; ++j)
                    cnt[i][j] = 0;
            for (int i = 0; i < m; ++i)
                if (range[i].first >= l && r >= range[i].second)
                {
                    for (int j = range[i].first; j <= range[i].second; ++j)
                        cnt[j][c[i]]++;
                }
            for (int i = l; i <= r; ++i)
                for (int j = maxK; j > 0; --j)
                    cnt[i][j] += cnt[i][j+1];
            
            for (int k = maxK; k; k--)//枚举最小值
            {
                int anss = 0, sum;
                for (int p = l; p <= r; p++)//枚举断点
                {
                    (sum = dp[l][p - 1][k] + dp[p + 1][r][k] + cnt[p][k] * vc[k]);
                    if ( sum >= anss) 
                        anss = sum, ind[l][r][k] = p;//转移方程显然,num存决策点
                }
                    
                if (anss >= dp[l][r][k + 1])
                    dp[l][r][k] = anss; //val[i][j][k] = k;//与k+1比较（由于不同情况需要更新的内容不同 ，val为最优值
                else
                    dp[l][r][k] = dp[l][r][k + 1], ind[l][r][k] = -1;
            }
                
        }
    }
    

}

void f(int l, int r, int k)
{
    if (l > r || k > maxK)
        return;
    int t = ind[l][r][k];
    if (t == 0)
        return;
    if (t == -1)
        f(l, r, k + 1);
    else
    {
        ans[t] = vc[k];
        f(l, t - 1, k);
        f(t + 1, r, k);
    }
}

int main()
{
    n = read(), m = read();
    vector<pair<int, int>> arr(m);
    for (int i = 0; i < m; ++i)
    {
        range[i].first = read(), range[i].second = read();
        arr[i].first = read(), arr[i].second = i;
    }
        
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
    int pre = -1;
    for (auto i : arr)
    {
        if (i.first != pre)
        {
            ++maxK;
            vc[maxK] = i.first;
            pre = i.first;
        }
        c[i.second] = maxK;

    }
    solve();
    f(1, n, 1);
    
    write(dp[1][n][1]), putchar('\n');
    for (int i = 1; i <= n; ++i)
        write(ans[i]), putchar(' ');
    putchar('\n');


}
