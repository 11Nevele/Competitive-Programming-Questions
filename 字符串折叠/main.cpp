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
#include <cstring>
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
string str;
int dp[105][105];

int digit(int x)
{
    int cnt = 0;
    while (x > 0)
    {
        x /= 10;
        ++cnt;
    }
    return cnt;
}
int solve(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l == r)
        return 1;
    int mi = r - l + 1;
    for (int i = l; i <= (r + l) / 2; ++i)
    {
        if ((r - i) % (i - l + 1))
            continue;
        int ind = l;
        int cnt = 0;
        for (int j = i + 1; j <= r; j++)
        {
            if (str[j] == str[ind])
            {
                ++ind;
                if (ind > i)
                {
                    ind = l;
                    ++cnt;
                }    
            }
            else
            {
                cnt = -1;
                break;
            }
        }
        if (cnt != -1)
        {
            mi = min(mi, solve(l, i) + digit(cnt + 1) + 2);
            break;
        }
    }
    for (int i = l; i < r; ++i)
    {
        mi = min(mi, solve(l, i) + solve(i + 1, r));
    }
    dp[l][r] = mi;
    return mi;
}
int main()
{
    cin >> str;
    memset(dp, -1, sizeof(dp));
    int t = solve(0, str.size() - 1);
    cout << t << endl;
}
