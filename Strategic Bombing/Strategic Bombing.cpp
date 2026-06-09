#include<queue>
#include<stdio.h>
#include<stack>
using namespace std;
bool arr[27][27];

stack<int>path;
int charToNum(char c)
{
	return c - 64;
}
char numToChar(int n)
{
	return n + 64;
}
bool dfs(int n, int target, bool *visited, bool s)
{
	if (n == target)
	{
		if(s)path.push(n);
		return true;
	}
	visited[n] = true;
	for (int i = 1; i <= 26; i++)
	{
		int t = i;
		if (visited[t] || !arr[n][i])
			continue;
		
		if (dfs(t,target, visited,s))
		{
			if (s)path.push(n);
			return true;
		}
	}
	return false;
}
int main()
{
	while (true)
	{
		int a = charToNum(getchar());
		int b = charToNum(getchar());
		getchar();

		if ((a + 64) == 42)
			break;
		arr[a][b] = true;
		arr[b][a] = true;
	}
	dfs(1, 2, new bool[26]{},true);
	int ans = 0;
	while (path.size() > 1)
	{
		int a = path.top();
		path.pop();
		int b = path.top();
		arr[a][b] = false;
		if (!dfs(a, b, new bool[26]{},false))
		{
			ans++;
			
			putchar(numToChar(a));
			putchar(numToChar(b));
			putchar('\n');
		}
		arr[a][b] = true;
		
	}
	printf("There are %d disconnecting roads.\n", ans);
	return 0;
}
