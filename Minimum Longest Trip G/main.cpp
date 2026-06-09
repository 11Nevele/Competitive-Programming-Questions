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

class node
{
public:
    int target;
    int dis;
    bool operator <(const node& other) const
    {
        //return dis < other.dis  large first
        return dis > other.dis;
    }
};

void Topological(const vector<vector<pair<int, int>>>& adj, vector<int>& arr)
{
    vector<int> in(adj.size());
    for (int i = 0; i < adj.size(); ++i)
        for (auto j : adj[i])
            ++in[j.first];
    queue<node> q;
    for (int i = 1; i < adj.size(); ++i)
        if (!in[i])
            q.push({ i, 0 });
    while (!q.empty())
    {
        int x = q.front().target, d = q.front().dis;
        q.pop();
        arr.push_back(x);
        for (auto i : adj[x])
        {
            int t = i.first, w = i.second;
            --in[t];
            if (!in[t])
                q.push({ t,0 });
        }
    }
}

struct info
{
    int x;
    int preWeight;
    int preRank;
    bool operator < (const info& other) const
    {
        if (preWeight == other.preWeight)
            return preRank < other.preRank;
        return preWeight < other.preWeight;
    }
};
int main()
{
    int n = read(), m = read();
    vector<int> order;
    vector<vector<pair<int, int>>> adj(n + 1);
    while (m--)
    {
        int a = read(), b = read(), c = read();
        adj[b].push_back({ a,c });
    }
    Topological(adj, order);
    
    vector<int> ans(n + 1);
    vector<LL> dis(n + 1);
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = order[i];
        for (auto j : adj[x])
        {
            int t = j.first, w = j.second;
            ans[t] = ans[x] + 1;
            mx = max(ans[t], mx);
        }
    }

    vector<vector<int>> level(mx + 1);
    for (int i = 1; i <= n; ++i)
            level[ans[i]].push_back(i);
    vector<info> infos(n + 1);
    for (int i = 0; i <= n; ++i)
        infos[i] = { i, INT_MAX,INT_MAX };
    vector<int> rank(n + 1);
    for (int i = 0; i < mx; ++i)
    {
        vector<info> arr;
        for (int j : level[i])
            arr.push_back(infos[j]);
        sort(arr.begin(), arr.end());
        for (int j = 0; j < arr.size(); ++j)
            rank[arr[j].x] = j;
        for (int r = 0; r < level[i].size(); ++r)
        {
            int x = level[i][r];
            for (auto j : adj[x])
            {
                int t = j.first, w = j.second;
                if (ans[t] != i + 1) continue;
                info temp = { t, w, rank[x] };
                if (infos[t] < temp) continue;
                infos[t] = temp;
                dis[t] = dis[x] + w;
            }
        }
        
    }


    for (int i = 1; i <= n; ++i)
    {
        write(ans[i]), putchar(' ');
        write(dis[i]), putchar('\n');
    }
}
