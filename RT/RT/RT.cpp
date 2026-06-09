#include <stdio.h>
#include <string.h>
#include <vector>
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
int num[100];
inline void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	int len = 0;
	do num[len++] = x % 10; while (x /= 10);
	while (len--) putchar(num[len] + '0');
}
//short v[100000][100000];
int m[100000];
int arr[100000];
int main()
{
	int n = read(), k = read(), t = read(), ans = 0;
	for (int i = 0; i < k; i++)
		m[i] = read();
	//int temp = m[m[k - 1]];
	//for(int i = k - 1; i>  0; i--)
		//v[0][(m[j] + i) % n] = arr[(m[j - 1] + i) % n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < t; i++)
	{
		int temp = arr[(m[k - 1] + i) % n];
		for (int j = k - 1; j > 0; j--)
		{
			arr[(m[j] + i) % n] = arr[(m[j - 1] + i) % n];
		}
		arr[(m[0] + i) % n] = temp;
	}

	write(arr[0]);
	for (int i = 1; i < n; i++)
	{
		putchar(' ');
		write(arr[i]);
	}
	return 0;
}