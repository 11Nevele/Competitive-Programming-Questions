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
    //r for not palindromo row, c for not palindromo colum
    int n = read(), m = read(), r = n - read(), c = m - read();

    //cp: palin when making unpalin for row
    bool cp = c == 0, rp = r == 0;

    if (cp && r % 2 && !(n % 2))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    if (rp && c % 2 && !(m % 2))
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<char> cArr(n + 1, 'a'), rArr(m + 1, 'a');
    if (cp)
    {
        if (r % 2)
        {
            --r;
            cArr[n / 2 + 1]++;
        }
        for (int i = 1; i <= r / 2; ++i)
            ++cArr[i], ++cArr[n - i + 1];
    }
    else
    {
        for (int i = 1; i <= r; ++i)
            ++cArr[i];
    }

    if (rp)
    {
        if (c % 2)
        {
            --c;
            rArr[m / 2 + 1]++;
        }
        for (int i = 1; i <= c / 2; ++i)
            ++rArr[i], ++rArr[m - i + 1];
    }
    else
    {
        for (int i = 1; i <= c; ++i)
            ++rArr[i];
    }
    rArr[1] += cArr[1] - 'a';
    for (int i = 1; i <= m; ++i)
    {
        putchar(rArr[i]);
    }
    putchar('\n');
    for (int i = 2; i <= n; ++i)
    {
        putchar(cArr[i]);
        for (int j = 2; j <= m; ++j)
            putchar('a');
        putchar('\n');
    }
}
