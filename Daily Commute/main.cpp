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

void bfs(const vector<vector<int>>& adj, vector<LL>& dis, int s)
{
    vector<bool> v(adj.size());
    queue<int> q;
    fill(dis.begin(), dis.end(), INT_MAX);
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i : adj[x])
        {
            if (dis[x] + 1 >= dis[i]) continue;
            dis[i] = dis[x] + 1;
            q.push(i);
        }
    }
}

int main()
{
    int n = read(), m = read(), d= read();
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int a = read(), b = read();
        adj[b].push_back(a);
    }
    vector<LL> station(n + 1), stationAtInd(n + 1);
    for (int i = 0; i < n; ++i)
    {
        int t = read();
        stationAtInd[i + 1] = t;
        station[t] = i;
    }
    vector<LL> dis(n + 1);
    bfs(adj, dis, n);
    LL ans = INT_MAX;
    int pre = -1;
    map<LL, int> s;
    for (int i = 1; i <= n; ++i)
    {
        s[station[i] + dis[i]]++;
    }
    
    while (d--)
    {
        int indA = read(), indB = read();
        int a = stationAtInd[indA], b = stationAtInd[indB];
        swap(stationAtInd[indA], stationAtInd[indB]);
        LL disA = station[a] + dis[a], disB = station[b] + dis[b];
        if (s[disA] == 1) s.erase(disA);
        else s[disA]--;
        if (s[disB] == 1) s.erase(disB);
        else s[disB]--;

        swap(station[a], station[b]);
        s[station[a] + dis[a]]++;
        s[station[b] + dis[b]]++;
        write((*s.begin()).first), putchar('\n');
    }
    
}
