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
	int n = read();
    LL cnt = 0;
	vector<LL> b(n), p(n - 1), u(n - 1);
    vector<LL> l(n), r(n), buy(n),tp(n),tb(n);
    LL extra = 0;
	for (int i = 0; i < n; i++)
		b[i] = read();
	for (int i = 0; i < n - 1; i++)
		p[i] = read();
	for (int i = 0; i < n - 1; i++)
		u[i] = read(), cnt += u[i];
    
    for (int i = 0; i < n - 1; i++)
    {
		tp[i] = p[i]-u[i];
		int tmp = min(tb[i], tp[i]);
		tb[i] -= tmp;
		tp[i] -= tmp;
        if (tp[i] > tb[i + 1])
        {
            cout << "NO\n";
			return 0;
        }
		tb[i + 1] -= tp[i];
    }
	tp = p, tb = b;
    vector<int> stk();
    for (int i = 0; i < n - 1; ++i)
    {
        int tmp = min(tp[i], b[i]);
		tp[i] -= tmp;
        b[i] -= tmp;
        l[i] = tmp;

    }

    cout << "YES\n";
    write(extra), putchar('\n');
    for (int i = 0; i < n - 1; ++i)
    {
		write(l[i]), putchar(' '), write(buy[i]), putchar(' '), write(r[i]), putchar('\n');
    }

    return 0;
}