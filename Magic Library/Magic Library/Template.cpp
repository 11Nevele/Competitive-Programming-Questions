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

    vector<unordered_map<short, int>> mp;
    vector<short> lazy;
    const int size;
    void build(int x, int l, int r, const vector<short>& arr)
    {
        if (l == r)
        {
            if (l < arr.size())
            {
                mp[x][arr[l]]++;
            }
            return;
        }
            
        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, arr), build(rChild, mid + 1, r, arr);
		for (auto& p : mp[lChild])
			mp[x][p.first] += p.second;
		for (auto& p : mp[rChild])
			mp[x][p.first] += p.second;
    }
    SegTree(int newSize, const vector<short>& arr): size(newSize), mp(3 *newSize), lazy(3 * newSize, -1)
    {
        build(0, 1, size, arr);
    }
    void PushDown(int x, int cl, int cr)
    {
		if (lazy[x] == -1)
			return;
        int left = (x << 1) + 1, right = (x << 1) + 2;
		int mid = (cl + cr) >> 1;

		mp[left].clear(), mp[right].clear();
		mp[left][lazy[x]] += mid - cl + 1;
		mp[right][lazy[x]] += cr - (mid + 1) + 1;

        lazy[left] = lazy[x];
        lazy[right] = lazy[x];
        lazy[x] = -1;
    }
    void ChangeRange(int x, int cl, int cr, const int l, const int r, const int v)
    {

        if (l <= cl && r >= cr)
        {
            lazy[x] = v;
			mp[x].clear();
			mp[x][v] += cr - cl + 1;
            return;
        }
        if (r < cl || l > cr)
            return;
        PushDown(x, cl, cr);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        int mid = (cl + cr) >> 1;
        ChangeRange(lChild,cl, mid, l, r, v),ChangeRange(rChild, mid + 1, cr, l, r, v);
        mp[x].clear();

        for (auto& p : mp[lChild])
            mp[x][p.first] += p.second;
        for (auto& p : mp[rChild])
            mp[x][p.first] += p.second;
    }
    int GetRange(int x, int cl, int cr, int l, int r, int v)
    {
        if (l <= cl && r >= cr)
        {
            return mp[x][v];
        }
        if (r < cl || l > cr)
        {
            return 0;
        }
        PushDown(x, cl, cr);
		int mid = (cl + cr) >> 1;
        return GetRange((x << 1) + 1, cl, mid, l, r, v) +
            GetRange((x << 1) + 2,mid + 1, cr, l, r, v);
    }
};
int main()
{
    int n = read(), q= read();
	vector<short> arr(n + 1);
	for (int i = 1; i <= n; i++)
		arr[i] = read();
    SegTree seg(n + 1, arr);
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int l = read(), r = read(), v = read();
            seg.ChangeRange(0,1, n + 1, l, r, v);
        }
        else
        {
            int l = read(), r = read(), v = read();
            write(seg.GetRange(0,1, n + 1, l, r, v));
            putchar('\n');
        }
    }
    return 0;
}