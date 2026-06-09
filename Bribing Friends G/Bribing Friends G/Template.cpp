#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
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

class Friend
{
public:
    int p;
    int c;
    int x;
    bool operator < (const Friend& other)
    {
        return x < other.x;
    }
};

int main()
{
    int n = read(), a = read(), b = read();
    vector<vector<int>> dp1(n + 2, vector<int>(a + 1)), dp2(n + 1, vector<int>(b + 1));
    vector<Friend> friends(n + 1);
    for (int i = 1; i <= n; ++i)
        friends[i] = { read(),read(), read() };
    sort(friends.begin(), friends.end());

    for(int i = n; i > 0; --i)
        for (int j = 0; j <= a; ++j)
        {
            dp1[i][j] = dp1[i + 1][j];
            int t = j - friends[i].c;
            if (t >= 0 && dp1[i + 1][t] + friends[i].p> dp1[i][j])
                dp1[i][j] = dp1[i + 1][t] + friends[i].p;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= b; ++j)
        {
            dp2[i][j] = dp2[i - 1][j];
            int t = j - (friends[i].c * friends[i].x);
            if (t >= 0 && dp2[i - 1][t] + friends[i].p > dp2[i][j])
                dp2[i][j] = dp2[i - 1][t] + friends[i].p;
        }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= a; ++j)
            dp1[i][j] = max(dp1[i][j], dp1[i][j - 1]);
        for (int j = 1; j <= b; ++j)
            dp2[i][j] = max(dp2[i][j], dp2[i][j - 1]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dp1[i + 1][a] + dp2[i - 1][b]);
        for (int j = 0; j <= friends[i].c; ++j)
        {
            int k = (friends[i].c - j) * friends[i].x;
            if (k > b || j > a)
                continue;
            ans = max(ans, dp1[i + 1][a - j] + dp2[i - 1][b - k] + friends[i].p);
        }
    }
    write(ans), putchar('\n');
    return 0;
}