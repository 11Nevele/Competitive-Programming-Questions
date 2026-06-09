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

unordered_map<string, LL> mp[6];

void dfs(const vector<int>& arr, string& str, int ind, int cnt)
{
    for (int i = ind + 1; i < 5; ++i)
    {
        auto cur = str.end();
        str += to_string(arr[i]);
        mp[cnt + 1][str]++;
        dfs(arr, str, i, cnt + 1);
        str.erase(cur, str.end());
    }
}

LL dfs2(const vector<int>& arr, string& str, int ind, int cnt)
{
    LL sum = 0;
    for (int i = ind + 1; i < 5; ++i)
    {
        int cur = str.size();
        str += to_string(arr[i]);
        if ((cnt + 1) % 2)
            sum += mp[cnt + 1][str];
        else
            sum -= mp[cnt + 1][str];
        sum += dfs2(arr, str, i, cnt + 1);
        str.erase(str.begin() + cur, str.end());
    }
    return sum;
}

int main()
{
    int n = read();
    vector<vector<int>> arr(n, vector<int>(5));
    for (auto& i : arr)
        for (int& j : i)
            j = read();
    for (auto& i : arr)
        sort(i.begin(), i.end());
    LL ans = (LL)n * (n - 1) / 2;
    for (const auto& i : arr)
    {
        string str;
        ans -= dfs2(i, str, -1, 0);
        dfs(i, str, -1, 0);
    }
    write(ans), putchar('\n');
}
