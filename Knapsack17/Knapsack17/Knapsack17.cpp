#include <stdio.h>
#include <string.h>
#include <algorithm>
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
class Pair
{
public:
    int w;
    int v;
};
bool compair(Pair a, Pair b)
{
    return a.w < b.w;
}
int w[100];
int v[100];
long ans[500005];
int main()
{
    int n = read(), mw = read();
    for (int i = 1; i <= n; i++)
    {
        w[i] = read();
        v[i] = read();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = mw; j >= w[i]; j--)
        {
            if (j - w[i] >= 0)
                ans[j] = max(ans[j], ans[j - w[i]] + v[i]);
            else
                ans[j] = ans[j];
            
        }
    }
    write(ans[mw]);
    putchar('\n');
    return 0;
}