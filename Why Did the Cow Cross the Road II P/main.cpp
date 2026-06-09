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

int n;
int bit[100001];
inline int lowbit(int x) { return x & -x; }
void add(int x, int t)
{
    while (x <= n)
    {
        if (t > bit[x])
            bit[x] = t;
        else
            break;
        x += lowbit(x);
    }
}
int bitMax(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans = max(bit[x], ans);
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    n = read();
    vector<int> l(n + 1), r(n + 1), pos(n + 1);

    for (int i = 1; i <= n; ++i)
        l[i] = read();
    for (int i = 1; i <= n; ++i)
        r[i] = read(), pos[r[i]] = i;

    for (int i = 1; i <= n; ++i)
    {
        int t = l[i];
        vector<pair<int, int>> change;
        for (int j = t - 4; j <= t + 4; ++j)
        {
            if (j < 1 || j > n) continue;
            int p = pos[j];
            change.push_back({ p, bitMax(p - 1) + 1 });
        }
        for (auto& i : change)
            add(i.first, i.second);
    }
    write(bitMax(n));
    putchar('\n');
}
