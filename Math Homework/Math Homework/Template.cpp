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

LL gcd(LL a, LL b)
{
    if (b > a)
        swap(a, b);
    while (b)
    {
        LL t = a % b;
        a = b;
        b = t;
    }
    return a;
}
LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}
class SegTree
{
public:
    vector<LL> seg;
    vector<LL> lazy;
    vector<pair<int, int>> range;
    const int size;
    void build(int x, int l, int r, const vector<LL>& arr)
    {
        range[x].first = l;
        range[x].second = r;
        if (l == r)
        {
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, arr), build(rChild, mid + 1, r, arr);
    }
    SegTree(int newSize) : size(newSize), seg(4 * newSize, 1), lazy(4 * newSize, 1), range(4 * newSize)
    {
        build(0, 1, size, vector<LL>(size + 1));
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;
        seg[left] = lcm(seg[left], lazy[x]);
        seg[right] = lcm(seg[right], lazy[x]);

        lazy[left] = lcm(lazy[left], lazy[x]);
        lazy[right] = lcm(lazy[right], lazy[x]);
        lazy[x] = 1;
    }
    void ChangeRange(int x, const int l, const int r, const int v)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            lazy[x] = lcm(lazy[x], v);
            seg[x] = lcm(seg[x],v);
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v), ChangeRange(rChild, l, r, v);
        seg[x] = gcd(seg[lChild], seg[rChild]);
    }
    long long GetRange(int x, int l, int r)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            return seg[x];
        }
        if (r < range[x].first || l > range[x].second)
        {
            return 0;
        }
        PushDown(x);
        return gcd(GetRange((x << 1) + 1, l, r),
            GetRange((x << 1) + 2, l, r));
    }
};

class range
{
public:
    int x;
    int y;
    int z;
};
int main()
{
    int n = read(), m = read();
    SegTree seg(n );
    vector<range> ranges(m);
    for (auto& i : ranges)
    {
        i.x = read(), i.y = read(), i.z = read();
        seg.ChangeRange(0, i.x, i.y, i.z);
    }
    for (auto& i : ranges)
    {
        if (seg.GetRange(0, i.x, i.y) != i.z)
        {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        write(seg.GetRange(0, i, i)), putchar(' ');
    }
    return 0;
}