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


LL f[100000], g[100005];
int adj[16][16];
const int mod = 1000000007;
int main()
{
    int n = read();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            adj[i][j] = read();
    int mx = (1 << n) - 1;
    for (int s = 0; s <= mx; ++s)
    {
        g[s] = 1;
        for (int i = 0; i < n; ++i)
        {
            if (!(s & (1 << i)))
                continue;
            for (int j = i + 1; j < n; ++j)
            {
                if (!(s & (1 << j)))
                    continue;
                g[s] = (g[s] * ((adj[i][j] + 1) % mod)) % mod;
            }
        }
    }

    for (int s = 1; s <= mx; ++s)
    {
        f[s] = g[s];
        int i = s - (s & -s);//do not include lowbit
        for (int j = s; j > 0; j = (j - 1) & i)
        {
            int t = s ^ j;//include lowbit
            f[s] = (f[s] - (f[t] * g[j] % mod) + mod) % mod;
        }
    }
    write(f[mx]), putchar('\n');
}
