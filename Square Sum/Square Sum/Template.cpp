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
		LL A = readLL(), B = readLL();
        if(A > B)
			swap(A, B);
        LL ans = 0, mod = 998244353;
        for (LL i = 1; A + B >= i * i; ++i)
        {
            LL s = i * i;
            LL Amn = max(0LL, s - A), Amx = min(s, A);
            if (Amn <= A)
                ans = (ans + (Amx - Amn + 1) % mod) % mod;
            //if (s & 1 == 0 && s / 2 <= A && s / 2 <= B)
              //  ans = (ans - 1 + mod) % mod;
            Amn = max(0LL, s - B);
            Amx = min(A, s - A - 1);
			if (Amn <= Amx)
				ans = (ans + (Amx - Amn + 1) % mod) % mod;
        }
		write(ans + 1),putchar('\n');
    }
    return 0;
}