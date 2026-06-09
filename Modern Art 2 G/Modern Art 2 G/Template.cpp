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
vector<int> first(100005, -1), last(100005, -1), arr(100005), vis(100005), psa(100005);
int depth(int l, int r)
{
    int mx = -1;
    if (l > r)
        return 0;
    for (int i = l; i <= r;)
    {
        if (vis[arr[i]] || arr[i] == 0)
        {
            ++i;
            continue;
        }
            
        if (first[arr[i]] != i || last[arr[i]] > r)
        {
            write(-1);
            exit(0);
        }
        vis[arr[i]] = true;
        if (psa[last[arr[i]] - 1] - psa[first[arr[i]] - 1])
        {
            write(-1);
            exit(0);
        }
        mx = max(mx, depth(first[arr[i]] + 1, last[arr[i]] - 1));
        i = last[arr[i]] + 1;
    }
    return mx + 1;
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = read();
        if (arr[i] == 0)
            psa[i]++;
    }
    for (int i = 1; i <= n; ++i)
        psa[i] += psa[i - 1];
    for (int i = 1; i <= n; ++i)
    {
        if (first[arr[i]] == -1)
            first[arr[i]] = i;
        last[arr[i]] = i;
    }
    write(depth(1, n));
    putchar('\n');
    return 0;
}