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

int main()
{
    int n = read();
    const LL mod = 1e9 + 7;
    vector<char>str(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> str[i];
    vector<LL> dp(n + 1);
    LL sum[2]{};
    vector<int> bad;
    vector<bool> active(n + 1, true);
    int preR = 0, curBound = 0;
    dp[0] = sum[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int s = i & 1;
        if (i - 1 > 1 && str[i - 1] == 'B')
            bad.push_back(i - 2);
        vector<int> tbad;
        for (int p : bad)
        {
            if (p >= 0 && active[p])
            {
                active[p] = false;
                if(p >= curBound)
                    sum[p & 1] = (sum[p & 1] - dp[p] + mod) % mod;
                tbad.push_back(p - 1);
            }
        }
        bad = tbad;

        if (str[i] == 'R')
            preR = i;
        int bound = max(0, 2 * preR - 2 - i + 1);
        while (curBound < bound)
        {
            sum[curBound % 2] = (sum[curBound % 2] - dp[curBound] * active[curBound] + mod) % mod;
            curBound++;
        }
        while (curBound > bound)
        {
            curBound--;
            sum[curBound % 2] = (sum[curBound % 2] + dp[curBound] * active[curBound]) % mod;
        }

        if (str[i] == 'X')
            dp[i] = dp[i - 1] % mod;
        dp[i] = (dp[i] + sum[s]) % mod;
        sum[s] = (dp[i] + sum[s]) % mod;
    
        
    }
    write(dp[n] % mod), putchar('\n');
    return 0;
}