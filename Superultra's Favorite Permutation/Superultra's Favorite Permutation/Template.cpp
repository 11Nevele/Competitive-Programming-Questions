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
vector<bool> isPrime(500005, true);
void init()
{
    for (int i = 2; i <= 500000; ++i)
    {
        if (isPrime[i])
        {
            int cur = i + i;
            while (cur <= 500000)
                isPrime[cur] = false, cur += i;
        }
    }
}
int main()
{
    init();
    int t = read();
    while (t--)
    {
        int n = read();
        int mxEven, mxOdd;
        if (n & 1)
            mxEven = n - 1, mxOdd = n;
        else
            mxEven = n, mxOdd = n - 1;
        int lastOdd = -1, firstEven = -1;
        for(int i = 3; i <= mxEven + mxOdd; i += 2)
            if (!isPrime[i])
            {
                lastOdd = i;
                break;
            }
        if (lastOdd < 0)
        {
            write(-1), putchar('\n');
            continue;
        }
        if (lastOdd <= mxOdd)
            lastOdd = lastOdd - 2, firstEven = 2;
        else
            firstEven = lastOdd - mxOdd, lastOdd = mxOdd;
        for (int i = 1; i <= mxOdd; i += 2)
            if (i != lastOdd)
                write(i), putchar(' ');
        write(lastOdd), putchar(' '), write(firstEven);
        for (int i = 2; i <= mxEven; i += 2)
            if (i != firstEven)
                putchar(' '), write(i);
        putchar('\n');
    }
    return 0;
}