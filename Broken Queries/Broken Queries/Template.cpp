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
int out(int a, int b)
{
	cout << "? " << a << " " << b << endl;
    int o;
    cin >> o;
    return o;
}

void bsOne(int t, int l, int r, int m)//first one
{
    while (l < r)
    {
		int mid = (l + r) / 2;
		int o = out(t, mid);
        if (o)
            r = mid;
		else
			l = mid + 1;
    }
    cout << "! " << l - t + 1 - m << endl;
}

void bsZero(int t, int l, int r)//first zero
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        int o = out(t, mid);
        if (o)
            l = mid + 1;
        else
            r = mid;
    }

    cout << "! " << l - t + 1 << endl;
}
void bsZeroR(int t, int l, int r)//last zero
{
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        int o = out(mid, t);
        if (o)
            r = mid - 1;
        else
            l = mid;
    }

    cout << "! " << t - l + 1 << endl;
}

int main()
{
    int t = read();
    while (t--)
    {
        int n = read();
        int m = n / 2;
        int t = out(1, m);
        if (t == 1)
        {
			int l = out(1, m / 2), r = out(m / 2 + 1, m);
            if (l != r)
            {
                bsZero(1, m + 1, n);
            }
            else if (l)
                bsOne(1, 2, m / 2,0);
            else
				bsOne(1, m/2 + 1, m,0);
        }
        else
        {
            int l = out(m + 1, m + m / 2), r = out(m + m / 2 + 1, n);
			if (l != r)
			{
				bsZeroR(n, 1, m);
			}
			else if (l)
				bsOne(m + 1, m + 2, n,0);
			else
				bsOne(m + 1, m + m / 2 + 1, n,0);
        }
    }

    return 0;
}