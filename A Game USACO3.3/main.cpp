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
vector<int> arr(105);
vector<vector<int>> dp(105, vector<int>(105));
int solve(int l, int r)
{
    if (l == r)
        return arr[r] - arr[l - 1];
    if (dp[l][r])
        return dp[l][r];
    int t = arr[r] - arr[l - 1];
    dp[l][r] = max(t - solve(l + 1, r), t - solve(l, r - 1));
    return dp[l][r];
}
int main()
{
    int n = read();
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = read();
        arr[i] += arr[i - 1];
    }
    cout << solve(1, n) << " " << arr[n] - solve(1, n) << endl;
        

}
