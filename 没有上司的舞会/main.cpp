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

class DSU
{
private:
    std::vector<size_t> parent;
public:
    DSU(size_t size)
    {
        parent.resize(size);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }
    size_t Find(size_t x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        parent[x] = Find(x);
        return parent[x];
    }
    void Unite(size_t a, size_t b)
    {
        parent[Find(a)] = parent[Find(b)];
    }
};
vector<vector<int>> adj(100005);
vector<int> v(100005);
vector<int> dp1(100005), dp2(100005);
int n = 0;
int solve(int x, int b)
{
    if (x > n)
        return 0;
    if (b)
    {
        if (dp1[x])
            return dp1[x];
        int sum = 0;
        for (int& i : adj[x])
        {
            sum += solve(i, false);
        }
        sum += v[x];
        dp1[x] = sum;
        return sum;
    }
    else
    {
        if (dp2[x])
            return dp2[x];
        int sum = 0;
        for (int& i : adj[x])
        {
            sum += max(solve(i, false), solve(i, true));
        }
        dp2[x] = sum;
        return sum;
    }
}
int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
        v[i] = read();
    for (int i = 0; i < n-1; ++i)
    {
        int l = read(), k = read();
        adj[k].push_back(l);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, max(solve(i, true), solve(i, false)));
    }
    cout << ans << endl;
}
