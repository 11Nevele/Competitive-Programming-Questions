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
int main()
{
    int n = read();
    vector<int> arr(n), ta(n + 1), temp;
    unordered_map<int,int> a2;
    for (int& i : arr)
        i = read();
    temp = arr;
    unique(temp.begin(), temp.end());
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
        a2[temp[i]] = i + 1;
    for (int i : arr)
        Change(ta, a2[i], 1);
    long long ans = 0;
    for (int i : arr)
    {
        ans += SumTo(ta, a2[i] - 1);
        Change(ta, a2[i], -1);

    }
    write(ans);
    putchar('\n');
    
}
