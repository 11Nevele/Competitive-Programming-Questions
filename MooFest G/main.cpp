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
int lowbit(int x) { return x & -x; }
void Add(vector<LL> &arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);

    }
}
long long Sum(vector<long long>& arr, int target)
{
    long long ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
bool Com(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first > b.first;
}
int main()
{
    int n = read();
    vector<pair<int, int>> c(n);
    vector<long long> cnt(50005), sum(50005);
    for (auto& i : c)
    {
        i.first = read(), i.second = read();
        if (i.first > 50000 || i.second > 50000)
            return 0;
        Add(cnt, i.second, 1);
        Add(sum, i.second, i.second);
    }
    sort(c.begin(), c.end(), Com);
    unsigned long long ans = 0;
    for (auto& i : c)
    {
        Add(cnt, i.second, -1);
        Add(sum, i.second, -i.second);
        long long smallerCnt = Sum(cnt, i.second), largerCnt = Sum(cnt, 50004) - Sum(cnt, i.second);
        long long smallerSum = Sum(sum, i.second), largerSum = Sum(sum, 50004) - smallerSum;
        ans += (long long)i.first * (-(smallerSum - smallerCnt * i.second) + (largerSum - i.second * largerCnt));
    }
    cout << ans << endl;
}
