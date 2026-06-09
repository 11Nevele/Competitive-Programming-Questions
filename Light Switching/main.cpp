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

long long build(vector<long long>& seg, vector<pair<int, int>>& segRange, int n, int l, int r)
{
    segRange[n].first = l;
    segRange[n].second = r;
    if (l == r)
        return(seg[n] = 0);
    int mid = (l + r) >> 1;
    return seg[n] = (build(seg, segRange, (n << 1) + 1, l, mid) + build(seg, segRange, (n << 1) + 2, mid + 1, r));
}
void PushDown(vector<long long>& seg, vector<pair<int, int>>& segRange, vector<int>& lazy, int n)
{
    if (!lazy[n])
        return;
    int left = (n << 1) + 1, right = (n << 1) + 2;
    seg[left] = (segRange[left].second - segRange[left].first + 1) - seg[left];
    seg[right] = (segRange[right].second - segRange[right].first + 1) - seg[right];
    lazy[left] += lazy[n];
    lazy[right] += lazy[n];
    lazy[left] %= 2;
    lazy[right] %= 2;
    lazy[n] = 0;

}
long long ChangeRange(vector<long long>& seg, vector<pair<int, int>>& segRange, vector<int>& lazy, int n, int l, int r)
{
    if (l <= segRange[n].first && r >= segRange[n].second)
    {
        lazy[n] += 1;
        lazy[n] = lazy[n] % 2;
        seg[n] = (segRange[n].second - segRange[n].first + 1) - seg[n];
        return seg[n];
    }
    if (r < segRange[n].first || l > segRange[n].second)
    {
        return seg[n];
    }
    PushDown(seg, segRange, lazy, n);
    seg[n] = ChangeRange(seg, segRange, lazy, (n << 1) + 1, l, r) +
        ChangeRange(seg, segRange, lazy, (n << 1) + 2, l, r);
    return seg[n];
}
long long GetRange(vector<long long>& seg, vector<pair<int, int>>& segRange, vector<int>& lazy, int n, int l, int r)
{
    if (l <= segRange[n].first && r >= segRange[n].second)
    {
        return seg[n];
    }
    if (r < segRange[n].first || l > segRange[n].second)
    {
        return 0;
    }
    PushDown(seg, segRange, lazy, n);
    return GetRange(seg, segRange, lazy, (n << 1) + 1, l, r) +
        GetRange(seg, segRange, lazy, (n << 1) + 2, l, r);
}

int main()
{
    int n = read(), m = read();
    vector<int> arr(n + 1), lazy(4 * n);
    vector<long long> seg(4 * n);
    vector<pair<int, int>> segRange(4 * n);
    build(seg, segRange, 0, 1, n);
    while (m--)
    {
        int op = read();
        if (op == 0)
        {
            int l = read(), r = read();
            ChangeRange(seg, segRange, lazy, 0, l, r);
        }
        else
        {
            int l = read(), r = read();
            write(GetRange(seg, segRange, lazy, 0, l, r));
            putchar('\n');
        }
    }
}