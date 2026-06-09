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
int main()
{
    int n = read(), m = read(), c = read();
    vector<int> r(n + 1);
    for (int i = 1; i <= n; ++i)
        r[i] = read();
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
    }

    vector<int> cur(n + 1, -1);
    cur[1] = 0;
    int ans = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        vector<int> next(n + 1, -1);
        for (int i = 1; i <= n; ++i)
        {
            if (cur[i] == -1) continue;
            for (int j : adj[i])
            {
                next[j] = max(next[j], r[j] + cur[i]);
            }
        }
        cur = next;
        ans = max(ans, cur[1] - c * i * i);
    
    }
    write(ans);
    putchar('\n');
}
