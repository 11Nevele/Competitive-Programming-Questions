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
    vector<LL> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = readLL();
	}
	priority_queue<LL, vector<LL>, greater<LL>> sell, buy;
    LL ans  =0;
    for (auto i : arr)
    {
        int t1 = buy.empty() ? 0 : i - buy.top();
        int t2 = sell.empty() ? 0 : i - sell.top();
        if (t1 <= 0 && t2 <= 0)
            buy.push(i);
        else if (t1 > t2)
        {
			buy.pop();
			ans += t1;
			sell.push(i);
		}
		else
		{
            buy.push(sell.top());
			sell.pop();
			ans += t2;
			sell.push(i);
        }
    }
	write(ans), putchar('\n');  
    return 0;
}