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
int lowbit(int n) { return n & -n; }
void Change(vector<int>& arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
long long SumTo(vector<int>& arr, int target)
{
    long long ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
int main()
{
    int n = read(), k = read();
    vector<long long> arr(n), temp;
    vector<int> ta(n + 2);
    unordered_map<long long, int> map;
    for (long long& i : arr)
        i = read() - k;
    for (int i = 1; i < n; i++)
        arr[i] += arr[i - 1];
    temp = arr;
    temp.push_back(0);
    sort(temp.begin(), temp.end());
    
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (int i = 0; i < temp.size(); i++)
        map[temp[i]] = i + 1;
    for (long long i : arr)
        Change(ta, map[i], 1);
    long long ans = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        long long t = (i == 0 ? 0 : arr[i - 1]);
        ans += SumTo(ta, ta.size() - 1) - SumTo(ta, map[t] - 1);
        Change(ta, map[arr[i]], -1);
    }
    write(ans);
    putchar('\n');
}
