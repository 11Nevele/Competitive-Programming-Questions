#include <stdio.h>
#include <string.h>
using namespace std;
char buf[1 << 23], * p1 = buf, * p2 = buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int s = 0;
    char ch = getchar(), last = 0;
    while (ch < '0' || ch >'9') last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return last == '-' ? -s : s;
}
long long num[100];
inline void write(long long x)
{
    if (x < 0) putchar('-'), x = -x;
    int len = 0;
    do num[len++] = x % 10; while (x /= 10);
    while (len--) putchar(num[len] + '0');
}
int main()
{
    int n = read(), c, v;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        c = read(), v = read();
        if (v > 0)
            ans += c;
    }
    write(ans);
    return 0;
}