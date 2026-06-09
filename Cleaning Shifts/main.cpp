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

int main()
{
    int c = read(), n = read();

    int size = log2(n);
    vector<vector<int>> st(size + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < c; ++i)
    {
        int a = read(), b = read();
        st[0][a] = max(st[0][a], b);
    }
    int pow = 1;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            st[i][j] = max(st[i - 1][j], st[i - 1][(j + pow) > n ? n : (j + pow)]);
        }
        pow = pow << 1;
    }
    int ind = 1, pre = 1, ans = 0;
    while (ind - 1 < n)
    {
        int t = log2((ind - pre) + 1);
        int next = max(st[t][pre], st[t][ind + 1 - std::pow(2, t)]);
        if (next == -1 || next < ind)
        {
            write(-1);
            return 0;
        }
        ++ans;
        pre = ind + 1;
        ind = next + 1;
    }
    write(ans);
    putchar('\n');
}
