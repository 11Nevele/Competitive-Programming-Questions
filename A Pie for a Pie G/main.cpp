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
vector<int> indOf(200005);
vector<pair<LL, int>> adj[800005];
LL tot = 0;
void buildIn(LL& x, int l, int r, const vector<pair<LL,LL>> &pie, vector<int>& indOf)
{
    x = ++tot;

    seg[x].l = pie[l].second, seg[x].r = pie[r].second;
    if (l == r)
    {
        indOf[pie[l].first] = x;
        return;
    }
    int mid = (l + r) >> 1;
    buildIn(seg[x].lChild, l, mid, pie, indOf);
    buildIn(seg[x].rChild, mid + 1, r, pie, indOf);
    adj[seg[x].lChild].push_back({x , 0 });
    adj[seg[x].rChild].push_back({x, 0 });

    return;
}

void AddB(LL x, int u, int l, int r)
{
    const Seg& s = seg[x];
    if (r < s.l || l > s.r)
        return;
    if (l <= s.l && s.r <= r)
    {
        adj[x].push_back({ u, 1 });
        return;
    }
    AddB(s.lChild, u, l, r);
    AddB(s.rChild, u, l, r);
}

class com
{
public:
    bool operator() (pair<LL, int> a, pair<LL, int> b)
    {
        return a.first > b.first;
    }
};
void ShortestPath(vector<LL>& dis, vector<int> &s)
{

    priority_queue < pair<LL, int>, vector < pair<LL, int>>, com> q;
    vector<bool> visited(800005);
    for (int i : s)
    {
        q.emplace(0, i);
        dis[i] = 0;
    }
    
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
    int n = read(), d = read();
    vector < pair<LL, LL>> pie(2 * n + 1);
    vector<int> p1(2 * n + 1), p2(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i)
    {
        pie[i].first = i;
        p1[i] = read();
        p2[i] = read();
        if (i <= n)
            pie[i].second = p1[i];
        else
            pie[i].second = p2[i];
    }

    sort(pie.begin(), pie.begin() + n + 1, [](const pair<LL, LL>& a, const pair<LL, LL>& b) {return a.second < b.second; });
    sort(pie.begin() + n + 1, pie.end(), [](const pair<LL, LL>& a, const pair<LL, LL>& b) {return a.second < b.second; });
    LL rootB, rootE;
    buildIn(rootB, 1, n, pie, indOf);
    buildIn(rootE, n + 1, 2 * n, pie, indOf);

    for (int i = 1; i <= n; ++i)
    {

        int r = p2[i] + d, l = p2[i];
        AddB(rootE, indOf[i], l, r);
    }
    for (int i = n + 1; i <= 2* n; ++i)
    {
        if (i == 1060)
            i = i;
        int r = p1[i] + d, l = p1[i];
        AddB(rootB, indOf[i], l, r);
    }

    vector<int> s;
    for (int i = 1; i <= n; ++i)
    {
        if (p2[i] == 0)
            s.push_back(indOf[i]);
    }
    for (int i = n+1; i <= 2* n; ++i)
    {
        if (p1[i] == 0)
            s.push_back(indOf[i]);
    }
    vector<LL> ans(800005, LL_MAX);
    ShortestPath(ans, s);

    for (int i = 1; i <= n; ++i)
    {
        int t = indOf[i];
        if (ans[t] == LL_MAX)
            write(-1);
        else
            write(ans[t] + 1);
        putchar('\n');
    }
}
