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

vector<int> dp(1100000, INT_MAX);
int cnt[26][26];
int dfs(int x)
{
    if (x == 0)
        return 0;
    if (dp[x] != INT_MAX)
        return dp[x];
    for (int i = 0; i < 20; ++i)
    {
        if (!(x & (1 << i)))
            continue;
        int tmp = dfs(x - (1 << i));
        for (int j = 0; j < 20; ++j)
            if (x & (1 << j))
                tmp += cnt[i][j];
        dp[x] = min(dp[x], tmp);
    }
    return dp[x];
}

int main()
{
    string str, str2;
    int mp[26]{};
    cin >> str;
    str2 = str;
    sort(str2.begin(), str2.end());
    str2.erase(unique(str2.begin(), str2.end()), str2.end());
    for (int i = 0; i < str2.size(); ++i)
        mp[str2[i] - 'a'] = i;
    str2.clear();
    for (int i = 0; i < str.size(); ++i)
        str[i] = mp[str[i] - 'a'];
    for (int i = 0; i < str.size() - 1; ++i)
        cnt[str[i]][str[i + 1]]++;
    write(dfs((1 << 20) - 1) + 1);
    return 0;
}