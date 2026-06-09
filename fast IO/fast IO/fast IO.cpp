#include <stdio.h>
#include <string.h>
char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int s = 0;
	char ch = getchar(), last = 0;
	while(ch<'0' || ch >'9') last = ch, ch = getchar();
	while(ch>='0' && ch<='9') s = s * 10 + ch - '0', ch = getchar();
	return last == '-' ? -s : s;
}
int num[100];
inline void write(int x)
{
	if(x < 0) putchar('-'), x = -x;
	int len = 0;
	do num[len++] = x % 10; while(x /= 10);
	while (len--) putchar(num[len] + '0');
}
int main()
{
	int n = read();
	write(n);
	return 0;
}