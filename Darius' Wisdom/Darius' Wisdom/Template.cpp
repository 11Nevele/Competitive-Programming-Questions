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

void solve()
{
    int n = read();
    vector<int> arr(n),cnt(3);
    vector<vector<vector<int>>> cntM(3, vector<vector<int>>(3));
    for (int& i : arr)
        i = read(), cnt[i]++;

    for (int i = cnt[0] - 1; i >= 0 ; --i)
        cntM[0][arr[i]].push_back(i);
    for (int i = cnt[0] + cnt[1] - 1; i >= cnt[0] ; --i)
        cntM[1][arr[i]].push_back(i);
    for (int i = cnt[0] + cnt[1] + cnt[2] - 1; i >= cnt[0] + cnt[1] ; --i)
        cntM[2][arr[i]].push_back(i);
    vector<pair<int, int>> ans;
    auto func = [&](int a1, int a2, int b1, int b2)
        {
            int ta = cntM[a1][a2].back(), tb = cntM[b1][b2].back();
            ans.push_back({ cntM[a1][a2].back(), cntM[b1][b2].back() });
            cntM[a1][a2].pop_back();
            cntM[b1][b2].pop_back();
            cntM[a1][b2].push_back(ta);
            cntM[b1][a2].push_back(tb);
        };
    while (!cntM[0][2].empty())
    {
        if (cntM[2][1].empty() && cntM[1][1].empty())
        {
            if (cntM[1][0].empty())
            {
                func(0, 1, 2, 0);
            }
            else
            {
                func(0, 1, 1, 0);
            }
        }
            if (cntM[2][1].empty())
            {
                func(0, 2, 1, 1);
            }
            else
            {
                func(0, 2, 2, 1);
            }
            if (cntM[1][0].empty())
            {
                func(0, 1, 2, 0);
            }
            else
            {
                func(0, 1, 1, 0);
            }
        
    }
    while(!cntM[0][1].empty())
    {
        if (cntM[1][0].empty())
        {
            func(0, 1, 2, 0);
        }
        else
        {
            func(0, 1, 1, 0);
        }
    }

    while (!cntM[1][2].empty())
        func(1, 2, 2, 1);

    write((int)ans.size()), putchar('\n');
    for (auto i : ans)
    {
        write(i.first + 1), putchar(' '),write(i.second + 1), putchar('\n');
    }
}
int main()
{
    int t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}