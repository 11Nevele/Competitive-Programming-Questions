#include <iostream>
#include <vector>
using namespace std;
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
    vector<long long> a(n + 2), leftPsa(n + 2), rightPsa(n + 2);
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    //creating differnce array from left and right, but with absolute value
    for (int i = 1; i <= n; ++i)
        leftPsa[i] = leftPsa[i - 1] + abs(a[i] - a[i - 1])* ((long long)i - (long long)1);
    for (int i = n; i >= 1; --i)
        rightPsa[i] = rightPsa[i + 1] + abs(a[i] - a[i + 1]) * ((long long)n - (long long)i);
   
    int q = read();
    for (int i = 0; i < q; ++i)
    {
        int h = read();
        write(rightPsa[h] + leftPsa[h]);
        putchar('\n');
    }
}
