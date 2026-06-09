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
class SegTree
{
public:
    vector<LL> seg;
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
                seg[x] = arr[l];
            }
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, arr), build(rChild, mid + 1, r, arr);
        seg[x] = seg[lChild] + seg[rChild];
        mx[x] = max(mx[lChild], mx[rChild]);
    }
    SegTree(int newSize, const vector<LL>& arr) : size(newSize), seg(4 * newSize), mx(4 * newSize), lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size, arr);
    }
    SegTree(int newSize) : size(newSize), seg(4 * newSize), mx(4 * newSize), lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size, vector<LL>(size + 1));
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;
        seg[left] += (range[left].second - range[left].first + 1) * lazy[x];
        seg[right] += (range[right].second - range[right].first + 1) * lazy[x];

        mx[left] += lazy[x];
        mx[right] += lazy[x];

        lazy[left] += lazy[x];
        lazy[right] += lazy[x];
        lazy[x] = 0;
    }
    void ChangeRange(int x, const int l, const int r, const int v)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            lazy[x] += v;
            seg[x] += (range[x].second - range[x].first + 1) * v;
            mx[x] += v;
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v), ChangeRange(rChild, l, r, v);
        seg[x] = seg[lChild] + seg[rChild];
        mx[x] = max(mx[lChild], mx[rChild]);
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
        return GetRange((x << 1) + 1, l, r) +
            GetRange((x << 1) + 2, l, r);
    }
    long long GetMax(int x, int l, int r)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
            return mx[x];
        }
        if (r < range[x].first || l > range[x].second)
        {
            return -INT_MAX;
        }
        PushDown(x);
        LL t1 = GetMax((x << 1) + 1, l, r);
        LL t2 = GetMax((x << 1) + 2, l, r);
        return max(t1, t2);
    }
};
class range
{

public:
    int l;
    int r;
    int d;
};
int main()
{
    int n = read(), m = read();
    
    vector<range> arr(n);
    vector<int> points;
	points.reserve(n * 2);
	unordered_map<int, int> pointMap;
    for (int i = 0; i < n; ++i)
    {
		arr[i].l = read(), arr[i].r = read(), arr[i].d = arr[i].r - arr[i].l;
		points.push_back(arr[i].l);
		points.push_back(arr[i].r);

    }
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	for (int i = 0; i < points.size(); ++i)
	{
		pointMap[points[i]] = i + 1;
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i].l = pointMap[arr[i].l];
		arr[i].r = pointMap[arr[i].r];
	}
	sort(arr.begin(), arr.end(), [](const range& a, const range& b) {return a.d < b.d; });
    SegTree segTree(points.size());
	int ans = INT_MAX;
    for (int i = 0, j = 0;; ++i)
    {
        while (j < n && segTree.GetMax(0, 1, points.size()) < m)
        {
			segTree.ChangeRange(0, arr[j].l, arr[j].r, 1);
			++j;
        }
		if (j >= n && segTree.GetMax(0, 1, points.size()) < m)
			break;
		ans = min(ans, arr[j - 1].d - arr[i].d);
		segTree.ChangeRange(0, arr[i].l, arr[i].r, -1);
    }
	write(ans == INT_MAX ? -1 : ans), putchar('\n');
    return 0;
}