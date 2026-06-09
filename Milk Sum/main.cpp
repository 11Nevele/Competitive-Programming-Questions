#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
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
bool com(const pair<LL, LL>& a, const pair<LL, LL>& b)
{
    return a.first < b.first;
}
int main()
{
    int n = read();
    vector<pair<LL,LL>> arr(n);
    vector<LL> pos(n + 1), psa(n + 1), arr2(n + 1);
    for (int i = 0; i < n; ++i)
        arr[i].first = read(), arr[i].second = i + 1;
    sort(arr.begin(), arr.end(), com);
    LL tot = 0;
    arr2[0] = -1;
    for (int i = 0; i < n; ++i)
    {
        arr2[i + 1] = arr[i].first;
        tot += arr[i].first * (i + 1);
        psa[i + 1] = arr[i].first;
        psa[i + 1] += psa[i];
        pos[arr[i].second] = i + 1;
    }
    
    int q = read();
    while (q--)
    {
        LL ans = tot;
        LL x = read(), y = read();
        LL p = pos[x];
        LL num = arr2[p];
        ans = ans - num * p - (psa[n] - psa[p]);
        LL np = lower_bound(arr2.begin(), arr2.end(), y) - arr2.begin();
        if (np <= p)
        {
            ans += np * y + psa[n] - psa[np - 1] - num;
        }
        else
        {
            ans += (np - 1) * y + psa[n] - psa[np - 1];
        }
        write(ans);
        putchar('\n');
    }
    
}
