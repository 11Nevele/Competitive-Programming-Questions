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
class Edge
{
public:
    int a;
    int b;
    LL dis;
    bool operator < (const Edge& other)
    {
        return dis < other.dis;
    }
};
int main()
{
    int n = read();
    vector<pair<int, int>> coords(n + 1);
    for (int i = 0; i < n; ++i)
        coords[i].first = read(), coords[i].second = read();
    coords[n] = { 0,0 };
    vector<Edge> edges;
    for (int i = 0; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
                edges.push_back({ i, j,
                    (LL)pow(coords[i].first - coords[j].first, 2) + (LL)pow(coords[i].second - coords[j].second, 2) });
    sort(edges.begin(), edges.end());
    vector<int> dp(n + 1, 1), dpPre(n + 1, 1);
    vector<LL> pre(n + 1);
    int mx = 0;
    for (auto& i : edges)
    {
        if (pre[i.a] < i.dis)
            pre[i.a] = i.dis, dpPre[i.a] = dp[i.a];
        if (pre[i.b] < i.dis)
            pre[i.b] = i.dis, dpPre[i.b] = dp[i.b];
        if (i.a == n)
            mx = max(mx, dpPre[i.b]);
        else if (i.b == n)
            mx = max(mx, dpPre[i.a]);
        else
        {
                dp[i.a] = max(dp[i.a], dpPre[i.b] + 1);
                dp[i.b] = max(dp[i.b], dpPre[i.a] + 1);
        }
    }
    write(mx), putchar('\n');
    return 0;
}