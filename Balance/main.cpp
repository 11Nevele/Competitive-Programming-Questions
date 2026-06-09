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

const int MX = 151, mod = 51123987;
unsigned dp[MX][51][51][51];
int main()
{
    int n = read();
    string str;
    cin >> str;
    str.erase(unique(str.begin(), str.end()), str.end());
    int mx = str.size() / 3 + 1;
    dp[0][0][0][0] = 1;
    LL ans = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        int cur = str[i] - 'a';
        bool next = (i != str.size() - 1);
        for(int a = 0; a <= mx; a++)
            for(int b = 0; b<=mx;b++)
                for (int c = 0; c <= mx; c++)
                {
                    if (!dp[i][a][b][c]) continue;
                    switch (cur)
                    {
                    case 0: dp[i][a + 1][b][c] = (dp[i][a + 1][b][c] + dp[i][a][b][c]) % mod; break;
                    case 1: dp[i][a][b + 1][c] = (dp[i][a][b + 1][c] + dp[i][a][b][c]) % mod; break;
                    case 2: dp[i][a][b][c + 1] = (dp[i][a][b][c + 1] + dp[i][a][b][c]) % mod; break;
                    }
                    if (a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(a - c) <=1 && !next)
                        ans = (ans + dp[i][a][b][c]) % mod;
                    if (next)
                        dp[i + 1][a][b][c] = (dp[i + 1][a][b][c] + dp[i][a][b][c]) % mod;
                }
    }
    write(ans), putchar('\n');
    return 0;
}
