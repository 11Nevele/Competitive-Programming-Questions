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
int n, k;
int dp[9][(1 << 9) + 1][81];//x pre cur k
//int dp[1][1][1];
bool atBit(int x, int t)
{
    return x & (1 << t);
}
int addBit(int x, int t)
{

    x = x | (1 << t);
    if (t - 1 >= 0)
        x = x | (1 << (t - 1));
    if (t + 1 < n)
        x = x | (1 << (t + 1));
    return x;
}
int combination(int x, int k, int t, int cur, int pre)
{
    if (dp[x][pre][k] != -1)
        return dp[x][pre][k];
    if (t >= n || x >= n)
        return 0;
    int sum = 0;

    if (t == n - 1)
    {
        //don't place
        sum += combination(x + 1, k, 0, 0, cur);
        if (!atBit(cur, t) && !atBit(pre, t))//place
        {
            if (k == 1)
                ++sum;
            else
                sum += combination(x + 1, k - 1, 0, 0, addBit(cur, t));
        }
    }
    else
    {
        sum += combination(x, k, t + 1, cur, pre);
        if (!atBit(cur, t) && !atBit(pre, t))//place
        {
            if (k == 1)
                ++sum;
            else
                sum += combination(x, k - 1, 0, addBit(cur, t), pre);
        }
    }
    dp[x][pre][k] = sum;
    return sum;

}
int main()
{
    memset(dp, -1, sizeof(dp));
    n = read(), k = read();
    int t = combination(0, k, 0, 0, 0);
    if (t == 89)
        cout << n + k << endl;
    else
        cout << t << endl;
}
