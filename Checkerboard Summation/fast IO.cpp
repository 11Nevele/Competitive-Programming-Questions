#include <stdio.h>
#include <string.h>
char buf[1 << 21], * p1 = buf, * p2 = buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
	int s = 0;
	char ch = getchar(), last = 0;
	while (ch < '0' || ch >'9') last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return last == '-' ? -s : s;
}
int num[100000];
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	int len = 0;
	do num[len++] = x % 10; while (x /= 10);
	while (len--) putchar(num[len] + '0');
}

#define lowbit(x) (x & (-x))
int arr[3001][3001];
int bit[3001][3005];
int m, n;
void update(int r, int c, int a)
{
	
	int pre = arr[r][c];
	pre = (r + c) % 2 ? pre : -pre;
	for (int i = r; i <= m; i += lowbit(i))
		for (int j = c; j <= n; j += lowbit(j))
			bit[i][j] -= pre;
	arr[r][c] = a;
	a = (r + c) % 2 ? a : -a;
	for (int i = r; i <= m; i += lowbit(i))
		for (int j = c; j <= n; j += lowbit(j))
			bit[i][j] += a;
			
}
long get(int r, int c)
{
	int sum = 0;
	for (int i = r; i; i -= lowbit(i))
		for (int j = c; j; j -= lowbit(j))
			sum += bit[i][j];
	return sum;
}
int main()
{
	m = read(); n = read();
	int r, c, a, r2, c2;
	long long sum;
	char op;
	while (true)
	{
		
		op = getchar();
		if (op == '0')
			return 0;
		if (op == '1')
		{
			r = read(), c = read(), a = read();
			update(r, c, a);
		}
		else
		{
			r = read(), c = read(), r2 = read(), c2 = read();
			sum = get(r2, c2) + get(r - 1, c - 1) - get(r2, c - 1) - get(r - 1, c2);
			if ((r + c) % 2)
			{
				write(sum);
				putchar('\n');
			}
			else
			{
				write(-sum);
				putchar('\n');
			}
		}
	}
}