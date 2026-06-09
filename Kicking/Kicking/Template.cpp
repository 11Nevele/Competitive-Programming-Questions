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
    int n = read(), m = read(), k =read();
	
	vector<vector<int>> psa1(n, vector<int>(m, 0)),
        psa2(n, vector<int>(m, 0)), mp(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c = getchar();
            mp[i][j] = c;
            if(c == 'A')
				psa1[i][j] = 1;
			else if(c == 'B')
				psa2[i][j] = 1;
        }
        getchar();
    }
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < m; ++j)
		{
			psa1[i][j] += psa1[i][j - 1];
			psa2[i][j] += psa2[i][j - 1];
		}
	}
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mp[i][j] == 'A')
            {
                if (psa2[i][min(m - 1, j + k)] - psa2[i][j])
                    mp[i][j] = 'N';
                else
                    mp[i][j] = 'Y';
            }
            else if(mp[i][j] == 'B')
            {
				int t = j - k - 1 >= 0 ? psa1[i][j - k - 1] : 0;
                if (psa1[i][j - 1] - t)
                    mp[i][j] = 'N';
                else
                    mp[i][j] = 'Y';
            }
        }

    }
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			putchar(mp[i][j]);
		}
		putchar('\n');
	}

        
    return 0;
}