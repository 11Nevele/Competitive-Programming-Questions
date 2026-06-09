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
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
const LL mod = 1e9 + 7;
int main()
{
    int n = read();
    vector<pair<int, int>> coord(n);
    unordered_map<int, LL> above, below, left, right;
    unordered_map<int, int> aboveCnt, belowCnt, leftCnt, rightCnt;
    for (int i = 0; i < n; ++i)
    {
        coord[i] = { read(), read() };
        above[coord[i].first] += coord[i].second;
        aboveCnt[coord[i].first]++;
        right[coord[i].second] += coord[i].first;
        rightCnt[coord[i].second]++;
    }
        
    sort(coord.begin(), coord.end(), cmp);
    LL ans = 0;
    for (auto& i : coord)
    {
        LL x = i.first, y = i.second;
        above[x] -= y;
        right[y] -= x;
        aboveCnt[x]--;
        rightCnt[y]--;

        if (rightCnt[y] > 0)
        {
            if (aboveCnt[x] > 0)
            {
                ans += ((right[y] - x * rightCnt[y]) % mod * ((above[x] - aboveCnt[x] * y) % mod)) % mod;
                ans %= mod;
            }
            if (belowCnt[x] > 0)
            {
                ans += ((right[y] - x * rightCnt[y]) % mod * ((belowCnt[x] * y - below[x]) % mod)) % mod;
                ans %= mod;
            }
        }
        if (leftCnt[y] > 0)
        {
            if (aboveCnt[x] > 0)
            {
                ans += ((x * leftCnt[y] - left[y]) % mod * ((above[x] - aboveCnt[x] * y) % mod)) % mod;
                ans %= mod;
            }
            if (belowCnt[x] > 0)
            {
                ans += ((x * leftCnt[y] - left[y]) % mod * ((belowCnt[x] * y - below[x]) % mod)) % mod;
                ans %= mod;
            }
        }
        

        below[x] += y;
        left[y] += x;
        belowCnt[x]++;
        leftCnt[y]++;
    }
    write(ans), putchar('\n');

    return 0;
}