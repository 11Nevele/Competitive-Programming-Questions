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
struct group
{
    char c;
    LL sum;
    LL x;
};
int main()
{
    int n = read(), m = read();
    vector<int> arr(n);
    string str;
    cin >> str;
    LL ans = 0;
    for (int& i : arr)
        i = read(), ans += i;
    vector<group> seg;
    seg.push_back({ str[0], arr[0], str[0] == 'L' ? arr[0]:0});
    for (int i = 1; i < n; ++i)
    {
        if (str[i] == seg.back().c)
        {
			seg.back().sum += arr[i];
			if (str[i] == 'R')
				seg.back().x = arr[i];
        }
        else
        {
            seg.push_back({ str[i], arr[i], arr[i]});
        }
			
    }
    if (seg.back().c == seg[0].c)
    {
        seg[0].sum += seg.back().sum;
        if(seg[0].c == 'L')
			seg[0].x = seg.back().x;
		seg.back() = seg[0];
    }
    else
        seg.push_back(seg[0]);
    seg.push_back(seg[0]);
	for (int i = 0; i < seg.size() - 1; ++i)
	{
        if (seg[i].c == 'R' && seg[i + 1].c == 'L')
        {
            ans = ans - min((LL)m, seg[i].sum - seg[i].x) -
				min((LL)m, seg[i + 1].sum - seg[i + 1].x);
        }
	}
    write(ans), putchar('\n');
    return 0;
}