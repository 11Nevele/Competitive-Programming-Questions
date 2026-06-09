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
int n;
vector<int> cnt;
vector<int> names;
vector<vector<int>> adj;
long long getCnt(int x)
{
    long long c = 0, c2 = 0;
    int leave = true;
    for (int& i : adj[x])
    {
        leave = false;
        c2 += getCnt(i) + (cnt[i] * (names[i] + 1));
        c += cnt[i];
    }
    cnt[x] = c + leave;
        return c2 ;
}
LL ans = LL_MAX;
int leaveCnt = 0;
void solve(int x, LL cur)
{
    for (int& i : adj[x])
    {
        LL t = cur + (3 * (leaveCnt - cnt[i])) - (cnt[i] * (names[i] + 1));
        ans = min(ans, t);
        solve(i, t);
    }
}
int main()
{
    n = read();
    cnt.resize(n + 1), names.resize(n + 1), adj.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        string str;
        cin >> str;
        int k = read();
        if (k == 0)
            leaveCnt++;
        for (int j = 0; j < k; ++j)
            adj[i].push_back(read());
        names[i] = str.size();
    }
    LL temp = getCnt(1) - leaveCnt;
    ans = min(temp, ans);
    solve(1, temp);
    cout << ans << endl;
}
