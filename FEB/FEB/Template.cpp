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
    int n = read();
    vector<int> str1(n), str2;
    for (int i = 0; i < n; ++i)
    {
        char c = getchar();
        if (c == 'F')
            str1[i] = 2;
        else if (c == 'B')
            str1[i] = 0;
        else
            str1[i] = 1;
    }
    if (n == 1)
    {
        write(1), putchar('\n');
        write(0);
        putchar('\n');
        return 0;
    }
    str2 = str1;
    int mn = 0, mx = 0, pre = 0;
    bool first = str1[0] == 2 || str1[n - 1] == 2;
    while (pre < n && str1[pre] == 2) ++pre;
    if (pre >= n)
        --mx;
    for (int i = pre + 1; i < n; ++i)
    {
        if (str1[i] == 2)
        {
            str1[i] = !str1[i - 1];
            str2[i] = str2[i - 1];
        }
        if (str1[i] == str1[i - 1])
            ++mn;
        if (str2[i] == str2[i - 1])
            ++mx;
    }
    mx += pre;
    write((mx - mn) / (2 - first) + 1);
    putchar('\n');
    for (int i = mn; i <= mx; first ? i += 1 : i += 2)
    {
        write(i), putchar('\n');
    }
    return 0;
}