#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline long long readLL()
{
    long long ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int main()
{
    int t = read();
	while (t--)
	{
		int n = read(), m = read();
		string str;
		cin >> str;
		vector<vector<LL>> mp(n + 1, vector<LL>(m + 1));
		vector<LL> psaH(n + 1), psaV(m + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				mp[i][j] = read();
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; ++j)
			{
				psaH[i] += mp[i][j];
				psaV[j] += mp[i][j];
			}
		int r = 1, c = 1;
		LL target = 0;
		for (char t : str)
		{
			if (t == 'R')
			{
				mp[r][c] = target - psaV[c];
				psaV[c] = target;
				psaH[r] += mp[r][c];
				c++;
			}
			else if (t == 'D')
			{
				mp[r][c] = target - psaH[r];
				psaH[r] = target;
				psaV[c] += mp[r][c];
				r++;
			}
			
		}
		mp[r][c] = target - psaH[r];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cout << mp[i][j] << " ";
			}
			cout << endl;
		}
	}
    return 0;
}