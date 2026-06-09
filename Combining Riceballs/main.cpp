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
vector<vector<int>> dp(405, vector<int>(405, -1));
vector<int> arr(405);
int ans = 0;
int solve(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l + 1 == r)
    {
        if (arr[l] == arr[r])
            dp[l][r] = arr[l] + arr[r];
        else
            dp[l][r] = 0;
        ans = max(ans, dp[l][r]);
        return dp[l][r];
    }
        
    int temp = 0;
    for (int i = l; i < r; ++i)
    {
        int a = solve(l, i), b = solve(i + 1, r);
        if (a == b)
        {
            temp = max(a + b, temp);
        }
        
    }
    int left = l, right = r;
    while (left < right)
    {
        if (l + 1 == r)
            break;
        if (dp[l][left] == 0 || dp[l][left] < dp[right][r])
            ++left;
        if (dp[right][r] == 0 || dp[l][left] > dp[right][r])
            --right;
        if(dp[l][left] == dp[right][r])
        {

            if (solve(left + 1, right - 1) != 0)
                temp = max(temp, (dp[l][left] << 1) + dp[left + 1][right - 1]);
            break;
        }
    }
    dp[l][r] = temp;
    ans = max(ans, temp);
    return dp[l][r];
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = read();
        ans = max(arr[i], ans);
        dp[i][i] = arr[i];
    }
    solve(1, n);
    cout << ans << endl;
}
