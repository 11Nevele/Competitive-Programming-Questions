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
vector<int> connectionCnt(100005);
vector<vector<int>> adj(100005);
int ans = 0;

pair<int,int> solve(vector<bool> &v, int x)
{
    int a = connectionCnt[x], b = 1;
    for (int i : adj[x])
    {
        if (connectionCnt[i] == -1 || v[i])
            continue;
        v[i] = true;
        auto temp = solve(v, i);
        a = min(a, temp.first);
        b += temp.second;
    }
    return { a,b };
}

int main()
{
    int n = read(), m = read();
    while (m--)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
        connectionCnt[a]++;
        connectionCnt[b]++;
    }
    set<pair<int, int>> mp;
    for (int i = 1; i <= n; ++i)
        mp.insert({ connectionCnt[i],i });
    int cur = (*mp.begin()).first;
    while( !mp.empty())
    {
        vector<bool > v(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (v[i] || connectionCnt[i] == -1)
                continue;
            v[i] = true;
            auto temp = solve(v, i);
            ans = max(ans, temp.first * temp.second);
        }

        while (!mp.empty() && (*mp.begin()).first <= cur)
        {
            int x = (*mp.begin()).second;
            mp.erase(mp.begin());
            connectionCnt[x] = -1;
            for (int j : adj[x])
            {
                if (connectionCnt[j] == -1)
                    continue;
                mp.erase({ connectionCnt[j],j });
                connectionCnt[j]--;
                mp.insert({ connectionCnt[j],j });
            }
        }
        if(!mp.empty())
        cur = (*mp.begin()).first;
    }
    write(ans), putchar('\n');
}