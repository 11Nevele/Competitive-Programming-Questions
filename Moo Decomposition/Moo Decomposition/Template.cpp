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
const LL mod = 1e9 + 7;
LL powm(LL a, LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

LL fac[1000005];
LL inv[1000005];

void init()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i < 1000005; ++i)
        fac[i] = (fac[i - 1] * i) % mod, inv[i] = powm(fac[i], mod - 2);
}
LL C(int n, int m)
{
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}


int main()
{

    LL k = read(), n = read(), l = readLL();
    string str;
    cin >> str;
    vector<int> psa(n + 1);
    vector<LL> dp(n + 1);
    init();
    for (int i = n - 1; i >= 0; --i)
    {
		psa[i] = psa[i + 1] + (str[i] == 'O');
    }
    LL nxt = n;
    LL cnt = 0;
	dp[n] = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (str[i] != 'M')
            continue;

        dp[i] = dp[nxt] * C(psa[i] - cnt * k, k) % mod;
        ++cnt;
        nxt = i;
    }
    write(powm(dp[nxt], l)), putchar('\n');

    return 0;
}