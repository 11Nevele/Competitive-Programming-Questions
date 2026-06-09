#include <stdio.h>
#include <string.h>
char buf[1<<21],*p1=buf,*p2=buf;
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
int arr[10005];
int move[10000];
int main()
{
	int n = read(), k = read(), t = read();
	for (int i = 0; i < k; i++)
		move[i] = read();
	for (int i = 0; i < n; i++)
		arr[i] = i;
	for (int i = 0; i < t; i++)
	{
		int temp = (move[k - 1] + t) % n;
		for (int j = 1; j < k; j++)
		{
			arr[move[j]] = arr[move[j - 1]];
		}
		arr[move[0]] = temp;
	}
	for (int i = 0; i < n; i++)
	{
		write(arr[i]);
		putchar(' ');
	}
}