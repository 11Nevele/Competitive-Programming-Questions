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
//only consider the ith element and it has cnt of 2
//dp[j] = max dp[j-2cost[i]] + 2value[i],  dp[j-cost[i]] + value[i], dp[j]
//convert to
//dp[j] - 2value[i] = max dp[j-2cost[i]],  dp[j-cost[i]] - value[i], dp[j] - 2value[i]
//f[0] = dp[0], f[cost[i]] = dp[cost[i]] - value[i], f[2cost[i]] = dp[2cost[i]] - 2value[i]
//solve with 单调队列 time n*k
int main()
{
    int n = read(), k = read();
    vector<int> v(n), w(n), cnt(n), dp(k + 1);
    for (int i = 0; i < n; ++i)
        v[i] = read(), w[i] = read(), cnt[i] = read();
    for (int i = 0; i < n; ++i)
    {
        vector<int> f(k + 1);
        vector<int> tempAns(k + 1);
        for (int j = 0; j <= k; ++j)
        {
            f[j] = dp[j] - v[i] * (j / w[i]);
        }
        for (int t = 0; t < w[i]; ++t)
        {
            //first j second ind
            deque<pair<int,int>> q;
            
            int j = t, ind = 0;
            for (j; j <= k && ind <= cnt[i]; j += w[i], ++ind)//init deque
            {
                while (!q.empty() && f[q.back().first] <= f[j])
                    q.pop_back();
                q.push_back({j, ind});
                tempAns[j] = dp[q.front().first] + (ind - q.front().second) * v[i];
            }
            //++ind, j += w[i];
            for (; j <= k; j += w[i], ++ind)//init deque
            {
                int outBound = ind - cnt[i];
                while (!q.empty() && q.front().second < outBound)
                    q.pop_front();
                while (!q.empty() && f[q.back().first] <= f[j])
                    q.pop_back();
                q.push_back({ j, ind });
                tempAns[j] = dp[q.front().first] + (ind - q.front().second) * v[i];
            }
        }
        dp = tempAns;
    }
    cout << dp[k] << endl;
}
