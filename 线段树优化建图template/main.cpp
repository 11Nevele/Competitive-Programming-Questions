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
class Seg
{
public:
    LL l;
    LL r;
    LL lChild;
    LL rChild;
};

Seg seg[800005];
LL indOf[100005];
vector<pair<LL, int>> adj[800005];
LL tot = 0;
void buildIn(LL &x, int l, int r)
{
    x = ++tot;

    seg[x].l = l, seg[x].r = r;
    if (l == r)
    {
        indOf[l] = x;
        return;
    }
    int mid = (l + r) >> 1;
    buildIn(seg[x].lChild, l, mid);
    buildIn(seg[x].rChild, mid + 1, r);
    adj[x].push_back({ seg[x].lChild, 0 });
    adj[x].push_back({ seg[x].rChild, 0 });
    
    return;
}
void buildOut(LL &x, int l, int r)
{
    if (l == r)
    {
        x = indOf[l];
        return;
    }
    x = ++tot;
    seg[x].l = l, seg[x].r = r;
    int mid = (l + r) >> 1;
    buildOut(seg[x].lChild, l, mid);
    buildOut(seg[x].rChild, mid + 1, r);
    adj[seg[x].lChild].push_back({ x, 0 });
    adj[seg[x].rChild].push_back({ x, 0 });
    
    return;
}

void AddIn(LL x, int u, int l, int r, int c)
{
    const Seg& s = seg[x];
    if (r < s.l || l > s.r)
        return;
    if (l <= s.l && s.r <= r)
    {
        adj[indOf[u]].push_back({ x, c });
        return;
    }
    AddIn(s.lChild, u, l, r, c);
    AddIn(s.rChild, u, l, r, c);
}

void AddOut(LL x, int u, int l, int r, int c)
{
    const Seg& s = seg[x];
    if (r < s.l || l > s.r)
        return;
    if (l <= s.l && s.r <= r)
    {
        adj[x].push_back({ indOf[u], c});
        return;
    }
    AddOut(seg[x].lChild, u, l, r, c);
    AddOut(seg[x].rChild, u, l, r, c);
}
class com
{
public:
    bool operator() (pair<LL, int> a, pair<LL, int> b)
    {
        return a.first > b.first;
    }
};
void ShortestPath(vector<LL>&dis, int s)
{
    
    priority_queue < pair<LL, int>, vector < pair<LL, int>>, com> q;
    vector<bool> visited(800005);
    q.emplace(0, indOf[s]);
    dis[indOf[s]] = 0;
    while (!q.empty())
    {
        auto t = q.top();
        LL distance = t.first, node = t.second;
        q.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        for (auto i : adj[node])
        {
            int next = i.first, weight = i.second;
            if (dis[next] <= distance + weight)
                continue;
            dis[next] = distance + weight;
            q.push({ dis[next],next });
        }
    }
}
int main()
{
    int n = read(), q = read(), s =read();
    LL rootIn, rootOut;
    buildIn(rootIn, 1, n);
    buildOut(rootOut, 1, n);
    while (q--)
    {
        int t = read(),u,v,l,r,c;
        switch (t)
        {
        case 1:
            u = read(), v = read(), c = read();
            AddIn(rootIn, u, v, v, c);
            break;
        case 2:
            u = read(), l = read(), r = read(), c = read();
            AddIn(rootIn, u, l, r, c);
            break;
        case 3:
            u = read(), l = read(), r = read(), c = read();
            AddOut(rootOut, u, l, r, c);
            break;
        default:
            break;
        }
    }
    vector<LL> dis(800005, LL_MAX);
    ShortestPath(dis, s);
    for (int i = 1; i <= n; ++i)
    {
        LL t = indOf[i];
        if (dis[t] == LL_MAX)
            write(-1);
        else
            write(dis[t]);
        putchar('\n');
    }
}
