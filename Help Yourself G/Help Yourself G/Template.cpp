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
const LL mod = 1e9 + 7;
LL powm(LL a, LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
bool overlap(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first)
		swap(a, b);
	return a.second > b.first;
}
int main()
{
    int n = read();
    LL ans = 0;
    vector<pair<int, int>> arr;
    for (int i = 0; i < 2 * n; ++i)
        arr.push_back({ read(), i % 2 });

	sort(arr.begin(), arr.end());
    int cnt = 0;
    for(auto i : arr)
    {
        if (i.second == 0)
        {
            ans = (2 * ans + powm(2, cnt)) % mod;
        }
		else
			cnt++;
		
    }
    write(ans), putchar('\n');
    return 0;
}