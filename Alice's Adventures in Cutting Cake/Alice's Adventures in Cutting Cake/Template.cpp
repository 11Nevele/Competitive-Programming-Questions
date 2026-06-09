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

void solve() {
    int n = read(), m = read();
    LL v = read();
    vector<int> arr(n + 1), seg;
    for (int i = 0; i < n; ++i)
        arr[i] = read();
    LL t = 0;
    int s = 0, e = 0;
    seg.push_back(n);
    for (int i = n - 1; i >= 0; --i)
    {
        t += arr[i];
        if (t >= v)
        {
            seg.push_back(i);
            t = 0;
            if (seg.size() - 1 == m)
            {
                break;
            }
        }
    }
    if (seg.size() - 1 < m)
    {
        write(-1), putchar('\n');
        return;
    }
    LL ans = 0;
    while(e < seg.back())
        ans += arr[e++];
    LL mx = ans;
    for (int i = 1; i <= m; ++i)
    {
        seg.pop_back();
        LL t = 0;
        while (t < v)
            t += arr[s], ans -= arr[s], ++s;
        while (e < seg.back())
            ans += arr[e++];
        mx = max(mx, ans);
    }
    write(mx), putchar('\n');
}
int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}