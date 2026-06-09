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
struct node
{
    int s;
    int e;
};
bool cmp2(const node& a, const node& b)
{
    return a.e < b.e;
}
bool cmp(const node& a, const node& b)
{
    if(a.e == b.e)
        return a.s < b.s;
    return a.e < b.e;
}

vector<vector<LL>> dp(1000, vector<LL>(10005, 0)), s(1000, vector<LL>(10005, 0));
const LL mod = 1e9 + 7;
LL powm(int a, int b)
{
    LL ans = 1, cur = a;
    while (b)
    {
        if (b % 2)
        {
            ans *= cur;
            ans %= mod;
        }
        cur *= cur;
        cur %= mod;
        b /= 2;
    }
    return ans;
}
int main()
{
    int n = read(), q = read(), c = read();
    vector<node> arr(q + 1);
    vector<int> num(1000), op(1000);
    for (int i = 1; i <= q; ++i)
        arr[i].s = read(), arr[i].e = read();
    sort(arr.begin() + 1, arr.end(), cmp);

    int cnt = 1, cur = 1;
    for (int i = 1; i <= q; ++i)
    {
        if (arr[i].e == arr[i - 1].e)
            continue;
        if (cur - 1 > arr[i].s)
        {
            write(0),putchar('\n');
            return 0;
        }
        if (cur <= arr[i].s)
        {
            num[cnt] = arr[i].s - cur + 1;
            op[cnt] = 0;
            ++cnt;
        }
        if (arr[i].s + 1 <= arr[i].e - 1)
        {
            num[cnt] = arr[i].e - arr[i].s - 1;
            op[cnt] = -1;
            ++cnt;
        }       
        num[cnt] = 1;
        op[cnt] = 1;
        ++cnt;
        cur = arr[i].e + 1;
    }
    if (cur <= n)
    {
        num[cnt] = n - cur + 1;
        op[cnt] = 0;
        ++cnt;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= c; ++i)
        s[0][i] = 1;
    for (int i = 1; i < cnt; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            LL a = powm(j, num[i]) % mod, b = powm(j - 1, num[i]) % mod;
            switch (op[i])
            {
            case -1:
                dp[i][j] = (dp[i - 1][j] * a) % mod;
                break;
            case 0:
                    dp[i][j] = 
                        (((dp[i-1][j] * a) % mod) + 
                        ((((a - b + mod) % mod) * s[i-1][j-1])%mod)) % mod;
                break;
            case 1:
                dp[i][j] = s[i - 1][j - 1] % mod;
                break;
            }
            s[i][j] = (dp[i][j] + s[i][j - 1]) % mod;
        }
    }
    write(s[cnt - 1][c]),putchar('\n');
    return 0;
}