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
bool valid(vector<int>& h, vector<int>& x, int t, int m, int k)
{
    map<int, int> psa;
    for (int i = 0; i < h.size(); ++i)
    {
        int mxDis = m - ceil((double)h[i] / t);
        if (mxDis < 0)
            continue;
        psa[x[i] + mxDis + 1]--;
        psa[x[i] - mxDis]++;
    }
    int pre = 0;
    for (auto& i : psa)
    {
        i.second += pre;
        if (i.second >= k)
            return true;
        pre = i.second;
    }
    return false;
}
void solve()
{
    int n = read(), m = read(), k = read();
    vector<int> h(n), x(n);
    for (int i = 0; i < n; ++i)
        h[i] = read();
    for (int i = 0; i < n; ++i)
        x[i] = read();

    int l = 1, r = 1000000000;
    if (!valid(h, x, r, m, k))
    {
        write(-1),putchar('\n');
        return;
    }
    while (l < r)
    {
        int mid = (l + r) / 2;
        bool v = valid(h, x, mid, m, k);
        if (v)
        {
            r = mid;
        }
        else
            l = mid + 1;
    }
    write(l), putchar('\n');
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