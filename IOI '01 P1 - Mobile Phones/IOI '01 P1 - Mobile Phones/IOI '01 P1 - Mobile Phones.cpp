#include <stdio.h>
#include <string.h>
char buf[1 << 20], * p1 = buf, * p2 = buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int s = 0;
    char ch = getchar(), last = 0;
    while (ch < '0' || ch >'9') last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return last == '-' ? -s : s;
}
int num[100];
inline void write(int x)
{
    if (x < 0) putchar('-'), x = -x;
    int len = 0;
    do num[len++] = x % 10; while (x /= 10);
    while (len--) putchar(num[len] + '0');
}

#define lowbit(x) (x & -x)
int bit[1025][1025];
int main()
{
	int s, sum = 0, x, y, a, x2, y2;
    while (true)
    {
        int temp = read();
        switch (temp)
        {
        case 0:
            s = read();
            break;
        case 1:
            x = read(), y = read(), a = read();
            x++; y++;
            for (int i = x; i <= s; i += lowbit(i))
                for (int j = y; j <= s; j += lowbit(j))
                    bit[i][j] += a;
			break;
        case 2:
            x = read(), y = read(), x2 = read(), y2 = read();
            x++; y++; x2++; y2++;
            sum = 0;
            for (int i = x2; i; i -= lowbit(i))
                for (int j = y2; j; j -= lowbit(j))
                    sum += bit[i][j];
            for (int i = x - 1; i; i -= lowbit(i))
                for (int j = y - 1; j; j -= lowbit(j))
                    sum += bit[i][j];
            for (int i = x2; i; i -= lowbit(i))
                for (int j = y - 1; j; j -= lowbit(j))
                    sum -= bit[i][j];
            for (int i = x - 1; i; i -= lowbit(i))
                for (int j = y2; j; j -= lowbit(j))
                    sum -= bit[i][j];
            write(sum);
            putchar('\n');
            break;
		case 3:
			return 0;
        }
    }
}