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
void Change(vector<int> &arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int SumTo(vector<int>& arr, int target)
{
    int ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
int GetRange(vector<int>& arr, int start, int end)
{
    return SumTo(arr, end) - SumTo(arr, start - 1);
}

void Program1(vector<int>& arr)
{
    int op = read(), x = read(), y = read();
    if (op == 1)
    {
        Change(arr, x, y);
    }
    else
    {
        write(GetRange(arr, x, y));
        putchar('\n');
    }
}
int main()
{
    int n = read(), q= read();
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        Change(arr, i, read());
    while (q--)
    {
        Program1(arr);
        
    }

}
