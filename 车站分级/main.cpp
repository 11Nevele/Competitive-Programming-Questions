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

void Topological(const vector<vector<int>>& adj, vector<int>& arr)
{
    vector<int> in(adj.size());
    for (int i = 0; i < adj.size(); ++i)
        for (int j = 1; j < adj.size(); ++j)
            if(adj[i][j])
                ++in[j];
    queue<int> q;
    for (int i = 1; i < adj.size(); ++i)
        if (!in[i])
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        arr.push_back(x);
        for (int i = 1; i < adj[x].size(); ++i)
        {
            int t = i;
            if (!adj[x][t]) continue;
            --in[t];
            if (!in[t])
                q.push(t);
        }
    }
}
int main()
{
    int n = read(), m = read();
    
    vector<vector<int>> adj(n + 1,vector<int>(n + 1));
    int mx = 1;
    while (m--)
    {
        int t = read();
        vector<int> temp(t);
        for (int& i : temp) i = read();

        int ind = 1;
        for (int i = temp[0] + 1; i < temp[t - 1]; ++i)
        {
            if (i == temp[ind])
            {
                ++ind;
                continue;
            }
            for (int j = 0; j < t; ++j)
                adj[i][temp[j]] = true;
        }
    }
    
    vector<int> order;
    Topological(adj, order);
    vector<int> ans(n + 1, 1);

    for (int i = 0; i < order.size(); ++i)
    {
        int x = order[i];
        for (int j = 1; j <= n; ++j)
        {
            if (!adj[x][j]) continue;
            ans[j] = max(ans[j], ans[x] + 1);
            mx = max(mx, ans[j]);
        }
    }
    write(mx), putchar('\n');


}
