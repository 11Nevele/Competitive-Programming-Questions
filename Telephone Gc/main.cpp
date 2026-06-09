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



class com
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};
void ShortestPath(const vector<vector<pair<int, int>>>& adj, vector<int>& dis, int s)
{
    priority_queue < pair<int, int>, vector < pair<int, int>>, com> q;
    vector<bool> visited(adj.size());

    fill(dis.begin(), dis.end(), INT_MAX);
    q.emplace(0, s);
    dis[s] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        int d = t.first, x = t.second;
        q.pop();
        if (visited[x])
            continue;
        visited[x] = true;
        for (auto i : adj[x])
        {
            int t = i.first, w = i.second;
            if (dis[t] <= d + w)
                continue;
            dis[t] = d + w;
            q.push({ dis[t],t });
        }
    }
}
int const layer = 100000;
vector<int> ans(52 * layer);
vector<vector<pair<int, int>>> adj(52 * layer);
int main()
{
    int n = read(), k = read();
    vector<int> b(n + 1);
    
    for (int i = 1; i <= n; ++i)
    {
        b[i] = read();
        adj[0 * layer + i].push_back({ b[i] * layer + i,0 });
    }
    
    vector<vector<bool>> connection(k + 1, vector<bool>(k + 1));
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= k; ++j)
            connection[i][j] = getchar() - '0';
        getchar();
    }

    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            adj[i * layer + j].push_back({ i * layer + j - 1 ,1 });
            adj[i * layer + j].push_back({ i * layer + j + 1, 1 });
        }
    }
        
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (!connection[j][b[i]]) continue;
            adj[j * layer + i].push_back({ i, 0 });
        }
    }
    
    ShortestPath(adj, ans, 1);
    write(ans[n] != INT_MAX ? ans[n] : -1), putchar('\n');
}
