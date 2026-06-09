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
LL SumTo(vector<long long>& arr, int target)
{
    long long ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
void Add(vector<LL>& arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int main()
{
    int n = read();
    vector<int> a(n), b(n), arr(n);
    unordered_map<int, int> av, bv;
    int ind = 0;
    for (int& i : a)
    {
        i = read();
        av[i] = ind++;
    }
    ind = 0;
    for (int& i : b)
    {
        i = read();
        bv[i] = ind++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<LL> ta(n + 1);
    for (int i = 0; i < n; ++i)
    {
        arr[av[a[i]]] = bv[b[i]] + 1;
    }
    for (int i : arr)
        Add(ta, i, 1);
    long long cnt = 0;
    for (int i : arr)
    {
        cnt += SumTo(ta, i - 1);
        cnt = cnt % 99999997;
        Add(ta, i, -1);
    }
    cout << cnt << endl;
    
}
