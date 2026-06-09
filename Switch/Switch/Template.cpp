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

int main()
{
    int n = read();
    vector<pair<int, int>> seg;
    seg.push_back({ 0,0 });
    int pre = -1;
    for (int i = 1; i <= n; ++i)
    {
        int t = read();
        if (t == 1)
        {
            if (pre == -1)
                pre = i;
        }
        else
        {
            if (pre != -1)
            {
                seg.push_back({ pre, i - 1 });
                pre = -1;
            }
            
        }
    }
    if (pre != -1)
        seg.push_back({ pre, n });
    if (seg.size() == 1)
    {
        write(0), putchar('\n');
        return 0;
    }
    vector<int> dp(n + 1);
    dp[1] = 4 - (seg[1].second - seg[1].first + 1);
    for (int i = 2; i < seg.size(); ++i)
    {
        dp[i] = dp[i - 1] + (4 - (seg[i].second - seg[i].first + 1));
        int l = seg[i].second + 1 - seg[i - 1].first;
        if (l <= 7)
            dp[i] = min(dp[i], dp[i - 2] + l - (seg[i].second - seg[i].first + 1) - (seg[i - 1].second - seg[i - 1].first + 1));
        
        if(i > 2)
        {
            l = seg[i].second - seg[i - 2].first + 1;
            if (l <= 7)
            {
                dp[i] = min(dp[i],
                    dp[i - 3] + l - (seg[i].second - seg[i].first + 1)
                    - (seg[i - 1].second - seg[i - 1].first + 1)
                    - (seg[i - 1].second - seg[i - 1].first + 1));
            }
        }
        if (i > 3)
        {
            l = seg[i].second - seg[i - 3].first + 1;
            if (l <= 7)
            {
                dp[i] = min(dp[i],
                    dp[i - 4] + 3);
            }
        }

    }
    write(dp[seg.size() - 1]), putchar('\n');
    return 0;
}