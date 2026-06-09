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

int main()
{
    int n = read(), m = read();
    if (n == 1 && m == 1)
    {
        write(1), putchar('\n');
        write(1), putchar('\n');
        return 0;
    }
    if (n == 1)
    {
        write(2), putchar('\n');
        for (int i = 1; i <= m; ++i)
            write((i & 1) + 1), putchar(' ');
        putchar('\n');
        return 0;
    }
    if (m == 1)
    {
        write(2), putchar('\n');
        for (int i = 1; i <= n; ++i)
            write((i & 1) + 1), putchar('\n');
        putchar('\n');
        return 0;
    }
    write(4), putchar('\n');
    for (int i = 1; i <= n; ++i)
    {
        int t = 1;
        if (i & 1) t = 3;
        for (int j = 1; j <= m; ++j)
            write((j & 1) + t), putchar(' ');
        putchar('\n');
    }
    return 0;
}