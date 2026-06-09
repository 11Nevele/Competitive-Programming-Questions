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
    int t = read();
    while (t--)
    {
        int n = read();
        if (n & 1)
        {
            if (n < 27)
            {
                write(-1), putchar('\n');
                continue;
            }
            int arr[] = { 1, 2, 2, 3, 3, 4,4,5,5,1,14,6,6,7,7,8,8,9,9,10,10,11,11,12,12, 1, 14 };
            for (int i = 0; i < 27; ++i)
                write(arr[i]), putchar(' ');
            for (int i = 28; i <= n; i += 2)
                write(i), putchar(' '), write(i), putchar(' ');
        }
        else
        {
            for (int i = 1; i <= n; i += 2)
                write(i), putchar(' '), write(i), putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}