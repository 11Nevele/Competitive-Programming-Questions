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
int n ,m;
int mn = INT_MAX;
void dfs(int r, int h, int level, int v, int s)
{
    if (v > n)
        return;
    if (s > mn)
        return;
    if (2 * (n - v) / r + s >= mn)  
        return;
    if (level == m)
    {
		if (v == n)
			mn = min(mn, s);
        return;
    }
    for(int i = r - 1; i >= (m - level); --i)
        for (int j = h - 1; j >= (m - level); --j)
        {
            int t = s + 2 * i * j;
            if (!level) t += i * i;
            dfs(i, j, level + 1, v + i * i * j, t);
        }
}
int main()
{
    n = read();
    m = read();
	dfs(1000, 1000, 0, 0, 0);
    if (mn == INT_MAX)
        write(0), putchar('\n');
    else
		write(mn), putchar('\n');
    return 0;
}