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
                seg[x] = arr[l];
            }
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, arr), build(rChild, mid + 1, r, arr);
        seg[x] = seg[lChild] + seg[rChild];
    }
    SegTree(int newSize, const vector<LL>& arr) : size(newSize), seg(4 * newSize), lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size, arr);
    }
    SegTree(int newSize) : size(newSize), seg(4 * newSize), lazy(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size, vector<LL>(size + 1));
    }
    void PushDown(int x)
    {
        int left = (x << 1) + 1, right = (x << 1) + 2;
        seg[left] += (range[left].second - range[left].first + 1) * lazy[x];
        seg[right] += (range[right].second - range[right].first + 1) * lazy[x];

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
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        PushDown(x);
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeRange(lChild, l, r, v), ChangeRange(rChild, l, r, v);
        seg[x] = seg[lChild] + seg[rChild];
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
};
int main()
{
    int n = read(), m = read(), q = read();
    vector<int> l(n + 1), a(n + 1), largeM;
    vector<int> moves(m + 1);
    vector<vector<int>> psa(m + 1), ind(m + 1);
    for (int i = 1; i <= n; ++i)
        l[i] = read(), ind[l[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
        a[i] = read(), psa[l[i]].push_back(a[i]);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j < psa[i].size(); ++j)
            psa[i][j] += psa[i][j - 1];
    SegTree seg(n + 1);
    for (int i = 1; i <= m; ++i)
    {

        if (ind[i].size() * ind[i].size() > n)
        {
            largeM.push_back(i);
            continue;
        }
        for (int j = 0; j < ind[i].size(); ++j)
            seg.ChangeRange(0, ind[i][j], ind[i][j], a[ind[i][j]]);
    }
    sort(largeM.begin(), largeM.end(), [&](int a, int b) 
        {
            return ind[largeM[a]].back() < ind[largeM[b]].back();
        });
    vector<int> t(largeM.size());
    for (int i = 0; i < largeM.size(); ++i)
        t[i] = ind[largeM[i]].back();
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int l = read(), r = read();
            int ans = 0;
            if (largeM.size() > 0)
            {
                int t1 = lower_bound(t.begin(), t.end(), l) - t.begin();
                for (int tt = t1; tt < largeM.size(); ++tt)
                {
                    int i = largeM[tt];
                    if (ind[i][0] > r || ind[i].back() < l)
                        break;
                    int s = lower_bound(ind[i].begin(), ind[i].end(), l) - ind[i].begin(),
                        e = upper_bound(ind[i].begin(), ind[i].end(), r) - ind[i].begin();
                    e--;
                    s -= moves[i], e -= moves[i];
                    int size = ind[i].size();
                    if (e >= 0 && s >= 0)
                    {
                        ans += psa[i][e] - (s == 0 ? 0 : psa[i][s - 1]);
                    }
                    else if (e >= 0 && s < 0)
                    {
                        s += ind[i].size();
                        ans += psa[i][e] + psa[i][size - 1] - psa[i][s - 1];
                    }
                    else
                    {
                        s += ind[i].size(), e += ind[i].size();
                        ans += psa[i][e] - (s == 0 ? 0 : psa[i][s - 1]);
                    }
                }
            }
            
            ans += seg.GetRange(0, l, r);
            write(ans), putchar('\n');
        }
        else
        {
            int x = read();
            if (ind[x].size() * ind[x].size() > n)
            {
                moves[x]++;
                moves[x] %= ind[x].size();
            }
            else
            {
                int na = a[ind[x][ind[x].size() - 1]];
                for (int i = ind[x].size() - 1; i  >  0; --i)
                {
                    seg.ChangeRange(0, ind[x][i], ind[x][i], -a[ind[x][i]] + a[ind[x][i - 1]]);
                    a[ind[x][i]] = a[ind[x][i - 1]];
                }
                seg.ChangeRange(0, ind[x][0], ind[x][0], -a[ind[x][0]] + na);
                a[ind[x][0]] = na;
            }
        }
    }

    return 0;
}