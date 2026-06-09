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
void solve()
{
    int n = read(), l = read(), r = read();
    vector<LL> pre, cur, aft;
    LL mx = 0, t = 0;

    for (int i = 1; i <= n; ++i)
    {
        int x = read();
        if (i < l)
            pre.push_back(x);
        else if (i > r)
            aft.push_back(x);
        else
            cur.push_back(x), t += x;
    }
    mx = t;
    sort(pre.begin(), pre.end());
    sort(aft.begin(), aft.end());
    sort(cur.begin(), cur.end(), greater<int>());
    for (int i = 1; i < cur.size(); ++i)
        cur[i] += cur[i - 1];
    for (int i = 1; i < pre.size(); ++i)
        pre[i] += pre[i - 1];
    for (int i = 1; i < aft.size(); ++i)
        aft[i] += aft[i - 1];
    for (int i = 0; i < min(cur.size(), aft.size()); ++i)
        mx = min(mx, t - cur[i] + aft[i]);
    for (int i = 0; i < min(cur.size(), pre.size()); ++i)
        mx = min(mx, t - cur[i] + pre[i]);
    write(mx), putchar('\n');
}
int main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}