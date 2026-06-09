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
    int n = read(), k = read();
    vector<LL> pos(1), neg(1);
    for (int i = 0; i < n; i++)
    {
        LL x = read();
        if (x >= 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }
	sort(pos.begin() + 1, pos.end(), greater<LL>());
	sort(neg.begin() + 1, neg.end());
	for (int i = 1; i < pos.size(); i++)
		pos[i] += pos[i - 1];
	for (int i = 1; i < neg.size(); i++)
		neg[i] += neg[i - 1];
	LL ans = 0;
    for (int i = 0; i <= k; i++)
    {
        int j = k - i * 2;
		j = min(j, (int)pos.size() - 1);
        if (j < 0)
            break;
        if (i >= neg.size())
            break;
        
		ans = max(ans, pos[j] - neg[i]);
    }
	write(ans), putchar('\n');
    return 0;
}