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

int check(vector<int>& arr, int x)
{
    int cnt = 0;
    int cur = arr[0], ind = 0;
    while (ind < arr.size())
    {
        cur += x;
        while (ind < arr.size() && cur >= arr[ind])
            ++ind;
        ++cnt;
        if (ind < arr.size())
            cur = arr[ind];
    }
    return cnt;
}
int bs(vector<int>& arr, int base, int l, int r)
{
    if (check(arr, r) == base)
        return -1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int t = check(arr, mid);
        if (t < base)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
 }
int main()
{
    int n = read(), bound = sqrt(n);
    vector<int> arr(n + 1), l, s;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; ++i)
        arr[i] = read(), g[arr[i]].push_back(i);
    for (int i = 1; i <= n; ++i)
    {
        if (!g[i].size())
            continue;
        if (g[i].size() >= bound)
            l.push_back(i);
        else
            s.push_back(i);
    }

    vector<int> ans(n + 1);
    for (int i : s)
    {
        int base = check(g[i], 1);
        ans[1] += base;
        int t = bs(g[i], base, 2, n);
        while (t != -1)
        {
            int res = check(g[i], t);
            ans[t] -= (base - res);
            base = res;
            t = bs(g[i], base, t + 1, n);

        }
    }
    for (int i = 1; i <= n; ++i)
        ans[i] += ans[i - 1];
    for (int i : l)
    {
        vector<int> next(n, -1);
        int  ind = 0;
        for (int j : g[i])
        {
            for (ind; ind <= j; ++ind)
                next[ind] = j;
        }
            
        for (int x = 1; x <= n; ++x)
        {
            int cnt = 0;
            int t = g[i][0];
            while (true)
            {
                ++cnt;
                t += x + 1;
                if (t >= n || next[t] == -1)
                    break;
                t = next[t];
            }
            ans[x] += cnt;
        }
    }
    for (int i = 1; i <= n; ++i)
        write(ans[i]), putchar('\n');
    return 0;
}