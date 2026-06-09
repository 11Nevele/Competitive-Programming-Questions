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
short map[26][26];
bool obs[26][26];
int main()
{
	int m = read(), n = read(), q = read();
	for (int i = 0; i < q; i++)
	{
		int r = read(), c = read();
		obs[r][c] = true;
	}
	map[1][1] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (obs[i][j])
				map[i][j] = 0;
			map[i + 1][j] += map[i][j];
			map[i][j + 1] += map[i][j];
		}
	}
	write(map[m][n]);
	return 0;
}