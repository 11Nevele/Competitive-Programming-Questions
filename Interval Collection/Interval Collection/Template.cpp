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
#define MAX 1000001
template <typename CMP>
class SegTree
{
public:
	vector<multiset<int, CMP>> st;
    vector<int> mn;
    vector<pair<int, int>> range;
    CMP cmp;
    const int size;
	int max(int x, int y)
	{
        return cmp(x, y) ? x : y;
	}
    void build(int x, int l, int r)
    {
        range[x].first = l;
        range[x].second = r;
        if (l == r)
        {
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid), build(rChild, mid + 1, r);
    }
    SegTree(int newSize) : size(newSize), st(newSize), mn(4 * newSize, -1), range(4 * newSize)
    {
        build(0, 1, size);
    }

    void ChangeRange(int x, const int l, const int r, const int v)
    {
        if (l == range[x].first && r == range[x].second)
        {
            if (v < 0)
				st[l].erase(st[l].find(-v));
            else
			    st[l].insert(v);
			if (st[l].size() == 0)
				mn[x] = -1;
			else
				mn[x] = *st[l].begin();
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
		if (l <= range[lChild].second)
			ChangeRange(lChild, l, r, v);
        else
			ChangeRange(rChild, l, r, v);
		int t1 = mn[lChild], t2 = mn[rChild];
        if (t1 == -1)
            mn[x] = t2;
        else if (t2 == -1)
            mn[x] = t1;
        else
            mn[x] = max(t1, t2);
    }
};
SegTree<greater<int>> segL(MAX);
SegTree<less<int>> segR(MAX);
multiset<int> stL, stR;
vector<int> ans(3 * MAX, INT_MAX);
void Update(int x, int l, int r, int t)
{
    if (r < t || l > t)
        return;
    if (l == t && r == t)
    {
        return;
    }
	int mid = (l + r) >> 1;
	int lc = (x << 1) + 1, rc = (x << 1) + 2;
    if (t <= mid)
        Update(lc, l, mid, t);
    else
	    Update(rc, mid + 1, r, t);
	ans[x] = min(ans[lc], ans[rc]);
    if(segR.mn[rc] != -1 && segL.mn[lc] != -1)
	    ans[x] = min(ans[x], segR.mn[rc] - segL.mn[lc] + 1);
}
int main()
{
    int q = read();
    while (q--)
    {
        char c = getchar();
        if (c == 'A')
        {
            int l = read(), r = read() - 1;
			stL.insert(l);
			stR.insert(r);
			segL.ChangeRange(0, r, r, l);
			segR.ChangeRange(0, l, l, r);
			Update(0, 1, MAX, r);
			Update(0, 1, MAX, l);
		}
        else
        {
            int l = read(), r = read() - 1;
			stL.erase(stL.find(l));
			stR.erase(stR.find(r));
			segL.ChangeRange(0, r, r, -l);
			segR.ChangeRange(0, l, l, -r);
            Update(0, 1, MAX, r);
            Update(0, 1, MAX, l);
        }
		int L = *stL.rbegin(), R = *stR.begin();

        if (L > R)
        {
			//no intersection
            write(ans[0]),putchar('\n');
        }
        else
        {
            write(*segR.st[L].begin() - *segL.st[R].begin() + 1 ), putchar('\n');
        }
    }
    return 0;
}