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
double slope(double x1, double y1, double x2, double y2)
{
    return (y2 - y1) / (x2 - x1);
}
LL f[100005];
LL ans[100005];
int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
    {
        f[i] = read();
        f[i] *= 100000;
    }
       
    vector<int> s;
    for (int i = 0; i <= n + 1; ++i)
    {
        while (s.size() > 1)
        {
            int cur = s[s.size() - 1], pre = s[s.size() - 2];
            if (slope(cur, f[cur], pre, f[pre]) > slope(i, f[i], cur, f[cur]))
            {
                break;
            }
            else
                s.pop_back();

        }
        s.push_back(i);
    }
    for (int i = 1; i < s.size(); ++i)
    {
        int start = s[i - 1], end = s[i];
        double slp = slope(start, f[start], end, f[end]);
        for (int j = 0; j < (end - start); ++j)
        {
            ans[start + j] = (f[start] + j * slp);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << (LL)(ans[i]) << "\n";
}
