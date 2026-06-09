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
vector<int> ansArr(100005);
int GetAns(const vector<vector<int>>& adj, const vector<pair<int, int>>& range, int x, int p)
{
    if (range[x].first <= p && p <= range[x].second)
        ansArr[x] = p;
    else if (p < range[x].first)
        ansArr[x] = range[x].first;
    else ansArr[x] = range[x].second;
    int mx = abs(p - ansArr[x]);

    for (int i : adj[x])
        mx = max(mx, GetAns(adj, range, i, ansArr[x]));
    return mx;
}

void solve(int b)
{
    int n = read();
    vector<int> fa(n + 1);
    vector<pair<int, int>> range(n + 1);
    vector<vector<int>> a(n + 1, vector<int>(2));
    for (int i = 2; i <= n; ++i)
    {
        fa[i] = read();
    }
    int mxL = 0, mnR = INT_MAX, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        range[i] = { read(), read() };
        mxL = max(mxL, range[i].first);
        mnR = min(mnR, range[i].second);
        if (fa[i] != 0)
        {
            a[i][0] = max(a[fa[i]][0], range[i].first);
            a[i][1] = min(a[fa[i]][1], range[i].second);
        }
        else
        {
            a[i][0] = range[i].first, a[i][1] = range[i].second;
        }
        ans = max(ans, a[i][0] - a[i][1]);
    }
    ans = max(ans, (mxL - mnR + 1) / 2);
    write(ans),putchar('\n');
        
    if (b)
    {
        if (mxL < mnR)
        {
            for (int i = 1; i <= n; i++) 
                write(mxL),putchar(' ');
        }
        else
        {
            int mid = (mxL + mnR) / 2;
            for (int i = 1; i <= n; i++) 
                write(max(min(mid, range[i].second), range[i].first)), putchar(' ');
        }
        putchar('\n');
    }
        
}
int main()
{
    int t = read(), b = read();
    while (t--)
    {
        solve(b);
    }
    return 0;
}