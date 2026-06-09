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
struct line
{
    int t, x, y;
};
int Get(int x, int y, int s, int e)
{
	return abs(s - x) + abs(e - y) + sqrt((LL)x*x + (LL)y * y);
}
int main()
{
    int n = read(), t = read();
    int s = read(), e = read();
    vector<line> arr(n);
    for (auto& i : arr)
        i = { read(), read(), read() };
    int mnX = s, mnY = e, mxX = s, mxY = e;
	int ans = Get(mnX, mnY, s, e);

    for (int i = 0, ind = 0; i < t; ++i)
    {
        while (ind < n && arr[ind].t <= i)
        {
            if(arr[ind].x > mnX)
				mnY = min(mnY, arr[ind].y);
			else if (arr[ind].y > mnY)
				mnX = min(mnX, arr[ind].x);
            if (arr[ind].x <= mxX)
                mnY = max(mnY, arr[ind].y);
            else if (arr[ind].y <= mxY)
                mxX = max(mxX, arr[ind].x);
            ++ind;
        }
		ans = Get(mnX, mnY, s, e);
        write(ans), putchar('\n');
    }
    return 0;
}