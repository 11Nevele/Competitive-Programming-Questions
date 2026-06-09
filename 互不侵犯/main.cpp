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
#include <cstring>
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
int n, k;
LL dp[9][81][(1 << 9) + 1];
bool atBit(int x, int t)
{
    return x & (1 << t);
}
int addBit(int x, int t)
{

    x = x | (1 << t);
    if(t - 1 >= 0)
        x = x | (1 << (t - 1));
    if(t + 1 < n)
        x = x | (1 << (t + 1));
    return x;
}
LL combination(int x, int k, int t, int cur, int pre)
{
    if (x >= n)
        return 0;
    if (t >= n)
        return combination(x + 1, k, 0, 0, cur);
    if (t == 0 && dp[x][k][pre] != -1)
       return dp[x][k][pre];
    
    LL sum = 0;
    
    sum += combination(x, k, t + 1, cur, pre);
    if (!atBit(pre, t))//place
    {
        if (k == 1)
            ++sum;
        else
            sum += combination(x, k - 1, t + 2, addBit(cur, t), pre);
    }
    if (t == 0)
        dp[x][k][pre] = sum;
    return sum;

}
int main()
{
    memset(dp, -1, sizeof(dp));
    n = read(), k = read();
    LL t = combination(0, k, 0, 0, 0);
        cout << t << endl;
}
