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
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[read()]++;
        n -= 2;
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i)
                continue;
            if (i == n / i)
            {
                if (mp[i] >= 2)
                {
                    write(i), putchar(' '), write(i), putchar('\n');
                    break;
                }  
                
            }
            else
            {
                if (mp[i] > 0 && mp[n / i] > 0)
                {
                    write(i), putchar(' '), write(n/i), putchar('\n');
                    break;
                }
            }
        }
    }
    return 0;
}