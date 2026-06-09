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
vector<vector<int>> dp;
vector<int> a, b;
int cnt = 0;
int RecursiveSolve(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int t = 0;
    if (i > 1) t = max(RecursiveSolve(i - 1, j), t);
    if (j > 1) t = max(RecursiveSolve(i, j - 1), t);
    dp[i][j] = t;
    cnt++;
    if (a[i - 1] == b[j - 1]) 
        dp[i][j] = dp[i - 1][j - 1] + 1;
    return dp[i][j];
}

int binary(vector<int>& arr, int target)
{
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (arr[mid] < target)
            l = mid;
        else if (arr[mid] > target)
            r = mid - 1;
        else
            return mid;
    }
    return l;
}
//convert into longest increasing subsequence 
//let f[i] represent the smallest last digit of subsequence with length of i
//binary search to find the last i that f[i] is smaller than target
//space n time n logn
int Solve2(int n)
{
    vector<int> f(n + 1, INT_MAX), v(n + 1);
    for (int i = 0; i < n; ++i)
        v[b[i]] = i;
    for (int i = 0; i < n; ++i)
        a[i] = v[a[i]];
    f[0] = -INT_MAX;
    int maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        int ind = binary(f, a[i]) + 1;
        maxLen = max(maxLen, ind);
        f[ind] = min(f[ind], a[i]);
    }
    return maxLen;
}
int main()
{
    int n = read();
    a.resize(n), b.resize(n);
    for (int& i : a)
        i = read();
    for (int& i : b)
        i = read();
    cout << Solve2(n) << endl;
}
