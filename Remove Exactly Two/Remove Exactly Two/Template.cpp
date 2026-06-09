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
struct cmp
{
    bool operator ()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};
int main()
{
    int T = read();
    while (T--)
    {
        int n = read();
        vector<unordered_set<int>> adj(n + 1);
        int ans = 1, mx = 0;
        for (int i = 1; i < n; ++i)
        {
            int a = read(), b = read();
            adj[a].insert(b);
            adj[b].insert(a);
            mx = max(mx, (int)adj[a].size());
            mx = max(mx, (int)adj[b].size());
        }
        //set<pair<int,int>> s
        int mn = INT_MAX, mnNode = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (adj[i].size() < mx)
                continue;
            int cnt = 0;
            for (int j : adj[i])
                if (adj[j].size() == mx)
                    ++cnt;
            if (cnt < mn)
            {
                mn = cnt;
                mnNode = i;
            }
        }
        ans += mx - 1;
        for (int i : adj[mnNode])
            adj[i].erase(mnNode);
        adj[mnNode].clear();

        mx = -1;int mxNode = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((int)adj[i].size() > mx)
            {
                mx = adj[i].size();
                mxNode = i;
            }
        }
        ans += mx - 1;

        write(ans), putchar('\n');
    }
    
    return 0;
}