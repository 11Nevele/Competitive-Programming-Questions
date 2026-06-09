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
int n;
vector<int> arr(205);
vector<vector<int>> maxDP(205, vector<int>(205, 0)), minDP(205, vector<int>(205, INT_MAX));
void dp(int l, int r)
{
    if (maxDP[l][r])
        return;
    if (l == r)
    {
        minDP[l][r] = 0;
        maxDP[l][r] = 0;
        return;
    }
    if (l + 1 == r)
    {
        minDP[l][r] = arr[r] - arr[l - 1];
        maxDP[l][r] = arr[r] - arr[l - 1];
        return;
    }
    for (int i = l; i < r; ++i)
    {
        dp(i + 1, r);
        dp(l, i);
        int ma = maxDP[i + 1][r] + maxDP[l][i] + arr[r] - arr[l - 1], mi = minDP[i + 1][r] + minDP[l][i] + arr[r] - arr[l - 1];
        maxDP[l][r] = max(maxDP[l][r], ma);
        minDP[l][r] = min(minDP[l][r], mi);
    }
}
int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = read();
        arr[n + i] = arr[i];
    }
        
    for (int i = 2; i <= 2 * n; ++i)
        arr[i] += arr[i - 1];
    int ma = 0, mi = INT_MAX;
    for (int i = 1; i <= 2; ++i)
    {
        dp(i, i + n - 1);
        mi = min(mi, minDP[i][i + n - 1]);
        ma = max(ma, maxDP[i][i + n - 1]);
    }
    
    cout << mi << "\n" << ma << endl;
}