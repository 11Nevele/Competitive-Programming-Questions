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
#include <cstring>
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

class SegTree
{
public:
    vector<LL> lazy;
    vector<LL> mx;
    vector<pair<int, int>> range;
    const int size;
    void build(int x, int l, int r, const vector<LL>& arr)
    {
        range[x].first = l;
        range[x].second = r;
        if (l == r)
        {
            if (l < arr.size())
            {
                mx[x] = arr[l];
            }
            return;
        }
        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, arr), build(rChild, mid + 1, r, arr);
        mx[x] = max(mx[lChild], mx[rChild]);
    }
    SegTree(int newSize, const vector<LL>& arr) : size(newSize), mx(4 * newSize), lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 0, size, arr);
    }
    SegTree(int newSize) : size(newSize), mx(4 * newSize), lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 0, size, vector<LL>(size + 1));
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;

        mx[left] += lazy[x];
        mx[right] += lazy[x];

        lazy[left] += lazy[x];
        lazy[right] += lazy[x];
        lazy[x] = 0;
    }
    void ChangeRange(int x, const int l, const int r, const LL v)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            lazy[x] += v;
            mx[x] += v;
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v), ChangeRange(rChild, l, r, v);
        mx[x] = max(mx[lChild], mx[rChild]);
    }
    void ChangeValue(int x, const int pos, const LL v)
    {
        if (pos == range[x].first && pos == range[x].second)
        {
            mx[x] = v;
            lazy[x] = 0;
            return;
        }
        if (pos < range[x].first || pos > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeValue(lChild, pos, v), ChangeValue(rChild, pos, v);
        mx[x] = max(mx[lChild], mx[rChild]);
    }
    long long GetMax(int x, int l, int r)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            return mx[x];
        }
        if (r < range[x].first || l > range[x].second)
        {
            return -LL_MAX;
        }
        PushDown(x);
        return max(GetMax((x << 1) + 1, l, r),
            GetMax((x << 1) + 2, l, r));
    }
};
class race
{
public:
    int l;
    int r;
    LL p;
    race(int a, int b, LL c) { l = a, r = b, p = c; }
};

int cost[200005];
LL dp[200005];
vector<vector<race>> races(200005);
int main()
{
    LL n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < m; ++i)
    {
        LL a, b, c;
        cin >> a >> b >> c;
        races[b].push_back(race( a,b,c ));
    }
    SegTree seg(200005);
    for (int i = 1; i <= n; ++i)
    {
        for (auto& j : races[i])
        {
            seg.ChangeRange(0, 0, j.l - 1, j.p);
        }
        seg.ChangeRange(0, 0, i - 1, -cost[i]);
        LL t = seg.GetMax(0, 0, i - 1);
        dp[i] = max(dp[i - 1], t);
        seg.ChangeValue(0, i, dp[i]);
    }
    cout << dp[n] << endl;
}