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
        LL x = read();
		vector<vector<int>> mp(n+1, vector<int>(2 * m+1));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mp[i][j] = read(), mp[i][j + m] = mp[i][j];
		vector<LL> dp(m + 1, LL_MAX), pre(m + 1, (LL)200 * (LL)INT_MAX);
		pre[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            vector<vector<LL>> subArr(m);
            for (int j = 0; j < m; ++j)
            {
                LL sum = 0;
                for (int k = j; k < m + j; ++k)
                {
                    sum += mp[i][k];
                    subArr[k - j].push_back(sum);
                }
            }
                
            for (int k = 0; k < m; ++k)
            {
                deque<LL> q;
                vector<LL>& sub = subArr[k];
                for (LL j = 0; j < subArr[k].size(); ++j)
                {
					LL tmp = subArr[k][j] + j * x;
					while (!q.empty() && sub[q.back()] + x * q.back() > tmp)
						q.pop_back();
					q.push_back(j);
                }
					
                for (LL j = 0; j + k < m; ++j)
                {
					while (!q.empty() && q.front() < j)
						q.pop_front();
                    int ind = q.front();
					dp[j + k] = min(dp[j + k], pre[j] + sub[ind % m] + x * (ind - j));
					LL tmp = sub[j] + (m) * x;
                    while (!q.empty())
                    {
                        int ind = q.back();
						LL b = ind >= m ? sub[ind - m] : sub[ind];
						b += x * (ind - j);
                        if (tmp <= b)
                            q.pop_back();
                        else
                            break;
                    }
                    q.push_back(j + m);
						
                }
            }
			for (int j = 0; j < m; ++j)
				pre[j] = dp[j], dp[j] = LL_MAX;
        }
		write(pre[m - 1]),putchar('\n');
    }
    return 0;
}