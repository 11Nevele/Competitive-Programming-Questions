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

pair<int, int> Solve(const vector<int>& h, const vector<int>& v, const vector<vector<int>>& r, const vector<vector<int>>& c, int x, int y, int d)
{
    auto ith = lower_bound(h.begin(), h.end(), y), itv = lower_bound(v.begin(), v.end(), x);
    if (*ith != y && *ith - y >= d)
    {
        return { x, y + d };
    }
    else if(*itv != x && *itv - x >= d)
    {
        return { x + d, y };
    }
    bool left = ((LL)*ith + (LL)*itv - x - y) % 2;
    d -= ((LL)*ith + (LL)*itv - x - y);
    int rInd = ith - h.begin(), cInd = itv - v.begin();
    for (int i = 17; i >= 0; --i)
    {
        int trInd = r[rInd][i], tcInd = c[cInd][i];
        if ((LL)(h[trInd] - h[rInd]) + (LL)(v[tcInd] - v[cInd]) > d)
            continue;
        d -= ((LL)(h[trInd] - h[rInd]) + (LL)(v[tcInd] - v[cInd]));
        rInd = trInd, cInd = tcInd;
    }
    if (left)
    {
        if (v[c[cInd][0]] - v[cInd] < d)
        {
            d -= (v[c[cInd][0]] - v[cInd]);
            return { v[c[cInd][0]], h[rInd] + d };
        }
        return { v[cInd] + d, h[rInd] };
    }
    else
    {
        if (h[r[rInd][0]] - h[rInd] < d)
        {
            d -= (h[r[rInd][0]] - h[rInd]);
            return { v[cInd] + d, h[r[rInd][0]] };
        }
        return { v[cInd], h[rInd] + d};
    }
}

int main()
{
    int n = read(), q = read();
    vector<int> h, v;
    while (n--)
    {
        char c;
        int t;
        cin >> c >> t;
        if (c == 'H')
            h.push_back(t);
        else
            v.push_back(t);
    }
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    h.push_back(2000000001), v.push_back(2000000001);
    vector<vector<int>> r(h.size(), vector<int>(18)), c(v.size(), vector<int>(18));

    for (int i = 0; i < 18; ++i)
    {
        r[r.size() - 1][i] = (int)r.size() - 1;
        c[c.size() - 1][i] = (int)c.size() - 1;
    }

    for (int i = (int)r.size() - 2; i >= 0; --i)
    {
        if (h[i] % 2 == h[i + 1] % 2)
            r[i][0] = r[i + 1][0];
        else
            r[i][0] = i + 1;
        for (int j = 1; j < 18; ++j)
            r[i][j] = r[r[i][j - 1]][j - 1];
    }

    for (int i = (int)c.size() - 2; i >= 0; --i)
    {
        if (v[i] % 2 == v[i + 1] % 2)
            c[i][0] = c[i + 1][0];
        else
            c[i][0] = i + 1;
        for (int j = 1; j < 18; ++j)
            c[i][j] = c[c[i][j - 1]][j - 1];
    }

    while (q--)
    {
        int x = read(), y = read(), d = read();

        auto ans = Solve(h, v, r, c, x, y, d);
        write(ans.first), putchar(' '), write(ans.second), putchar('\n');
    }

    return 0;
}