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
//for digit i, use j numbers
LL digit[101][35];

//i first i digit, first j numbers, k ones, ones going to next digit;
LL dp[105][35][35][35];
LL C[35][35];
LL v[105][35];
const int mod = 998244353;

int count(int x)
{
    int sum = 0;
    while (x)
    {
        if (x & 1) 
            ++sum;
        x >>= 1;
    }
    return sum;
}
int main()
{
    int N = read(), M = read(), K = read();
    for (int i = 0; i <= M; ++i)
    {
        v[i][1] = read() %mod;
        v[i][0] = 1;
        for (int j = 2; j <= N; ++j)
            v[i][j] = (v[i][j - 1] * v[i][1]) % mod;
    }
        
    for (int i = 0; i <= N; i++) C[i][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    dp[0][0][0][0] = 1;
    for(int i = 0; i <= M; ++i)
        for(int j = 0; j<=N;++j)
            for(int k = 0;k <= K; ++k)
                for (int p = 0; p <= (N >> 1); ++p)
                    for (int t = 0; t <= (N - j); ++t)
                    {
                        dp[i + 1][j + t][k + ((t + p) % 2)][(t + p) / 2]
                            += ((dp[i][j][k][p] * v[i][t]) %mod) * C[N - j][t];
                        dp[i + 1][j + t][k + ((t + p) % 2)][(t + p) / 2] %= mod;
                    }
    LL ans = 0;
    for (int k = 0; k <= K; ++k)
        for (int p = 0; p <= 15; ++p)
            if (k + count(p) > K)
                continue;
            else
                ans = (ans + dp[M + 1][N][k][p]) % mod;
    write(ans % mod);
    putchar('\n');
    return 0;
}
