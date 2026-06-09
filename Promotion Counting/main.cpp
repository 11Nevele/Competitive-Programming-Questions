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
void Add(vector<int>& arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int Sum(vector<int>& arr, int target)
{
    int sum = 0;
    while (target > 0)
    {
        sum += arr[target];
        target -= lowbit(target);
    }
    return sum;
}
void dfs(vector<vector<int>> &adj, vector<int>& arr, vector<int>& bit, vector<int>& ans, int n)
{
    int temp = Sum(bit, arr[n] - 1);
    for (int i : adj[n])
    {
        dfs(adj, arr, bit, ans, i);
    }
    ans[n] = Sum(bit, arr[n] - 1) - temp;
    Add(bit, arr[n], 1);
}
int main()
{
    int n = read();
    vector<int> arr(n + 1), bit(n + 2), ans(n + 1);
    vector<pair<int,int>> c(n);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
        c[i - 1].first = read(), c[i - 1].second = i;
    sort(c.begin(), c.end(), greater<pair<int,int>>());
    for (int i = 1; i <= n; ++i)
        arr[c[i - 1].second] = i;
    for (int i = 2; i <= n; ++i)
    {
        int t = read();
        adj[t].push_back(i);
    }
    dfs(adj, arr, bit, ans, 1);
    for (int i = 1; i <= n; ++i)
    {
        write(ans[i]);
        putchar('\n');
    }
}
