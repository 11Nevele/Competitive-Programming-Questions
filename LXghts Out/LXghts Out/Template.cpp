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
bool cmp(int a, int b)
{
    if (a & 1 && b & 1)
        return a < b;
	else if (!(a & 1) && !(b & 1))
		return a < b;
	else
		return !(a & 1);
}
int main()
{
    int n = read(), k = read();
    vector<int> arr;
    int curCnt = 0;
    for (int i = 0; i < n; i++)
    {
        char c = getchar();
        if (c == '1')
            curCnt++;
		else if (curCnt > 0)
        {
            arr.push_back(curCnt);
            curCnt = 0;
        }
    }
    if (curCnt > 0)
        arr.push_back(curCnt);
    int evenCnt = 0, l = 0, twoCnt = 0;
    for (int i : arr)
    {
        if (i == 2)
            twoCnt++;
        if (!(i & 1))
            evenCnt++;
        l += i;
    }
		
    if (twoCnt * 2 + twoCnt - 1 == n && k ==0)
        write(-1);
    else
    {
        write(max(0, 2 * max(0, evenCnt - k) + l - k));
    }
    putchar('\n');
    return 0;
}