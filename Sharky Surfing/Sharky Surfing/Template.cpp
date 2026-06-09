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
void solve()
{
    int n = read(), m = read(), L = read();
    vector<pair<int, int>> ob(n);
    for (auto& i : ob)
    {
        int  a = read(), b = read();
        i.first = a, i.second = b - a + 1;
    }
    vector<pair<int, int>> pu(m);
    for (auto& i : pu)
        i.first = read(), i.second = read();
    sort(ob.begin(), ob.end());
    sort(pu.begin(), pu.end());
    int cur = 1, ind = 0, ans = 0;
    priority_queue<int> q;
    for (auto& i : ob)
    {
        while (ind < m && pu[ind].first < i.first)
            q.push(pu[ind].second), ++ind;
        while (cur <= i.second)
        {
            if (q.empty())
            {
                write(-1), putchar('\n');
                return;
            }
            ++ans;
            cur += q.top();
            q.pop();
        }
    }
    write(ans), putchar('\n');
}
int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}