#include <stdio.h>
#include <string.h>
#include<queue>
#include<iostream>
using namespace std;
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
int arr[27][27];
int visited[27][27];
int charToNum(char c)
{
	return c - 64;
}
int main()
{
	while(true)
	{
		int a = charToNum(getchar());
		int b = charToNum(getchar());
		char s = getchar();
		int t;
		if (a == '*')
			break;
		t = ++arr[a][0];
		arr[a][t] = b;
		t = ++arr[b][0];
		arr[b][t] = a;
	}
	int path;
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int a = q.front(),b;
		q.pop();
		for (int i = 1; i < arr[a][0]; i++)
		{
			b = arr[a][i];
			visited[a][b]++;
			q.push(b);
		}
	}
	return 0;
}