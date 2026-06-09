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
bool check(LL l, LL r, LL x, vector<LL>& t, vector<LL>& c, vector<LL>& m)
{
    if (l < 1) l = 1;
    while (l < r)
    {
        bool b = true;
        LL mid = (l + r) / 2;
        LL tc = mid, tm = x - tc;
        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] < tc * c[i] + tm * m[i])
            {
                b = false;
                if (c[i] > m[i])
                    r = mid - 1;
                else if (m[i] > c[i])
                    l = mid + 1;
                else
                    return false;

                break;
            }
        }
        if (b) return true;
    }
    for (int i = 0; i < t.size(); ++i)
    {
        LL tc = l, tm = x - l;
        if (t[i] < tc * c[i] + tm * m[i])
            return false;
    }
    return true;
}
void solve()
{
    LL n = read(), tc = read(), tm = read();
    vector<LL> t(n),c(n), m(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i] >> m[i] >> t[i];
    LL l = 2, r = tc + tm;
    while (l < r)
    {
        LL mid = (l + r + 1) / 2;
        if (check(mid - tm, min(mid - 1, tc), mid, t, c, m))
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
    
    write(tc + tm - l);
    putchar('\n');
}
int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
}
