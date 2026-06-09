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
#define LL __int128
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
inline void write(LL x)
{
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

void Topological(const vector<vector<int>>& adj, vector<int>& arr)
{
    vector<int> in(adj.size());
    for (int i = 0; i < adj.size(); ++i)
        for (auto j : adj[i])
            ++in[j];
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
            int t = i;
            --in[t];
            if (!in[t])
                q.push({ t,0 });
        }
    }
}
LL GDC(LL a, LL b)
{
    if (b > a)
        swap(a, b);
    while (b != 0)
    {
        LL t = a % b;
        a = b;
        b = t;
    }
    return a;
}
pair<LL, LL> add(pair<LL, LL> a, pair<LL, LL> b)
{
    LL gdc = GDC(a.second, b.second);
    pair<LL, LL> result;
    result.first = (a.first *  (b.second / gdc)) + (b.first * (a.second / gdc));
    result.second = a.second * (b.second/ gdc);
    gdc = GDC(result.first, result.second);
    result.first /= gdc, result.second /= gdc;
    return result;
}
int main()
{
    int n = read(), m = read();
    vector<int> ends;
    vector<vector<int>> adj(n + 1);
    vector<pair<LL, LL>> w(n + 1, { 0, 1 });
    for (int i = 1; i <= m; ++i)
        w[i] = { 1,1 };
    for (int i = 1; i <= n; ++i)
    {
        int t = read();
        if (!t) ends.push_back(i);
        while (t--)
        {
            int a = read();
            adj[i].push_back(a);
        }
    }
    vector<int> order;
    Topological(adj, order);

    for (int i = 0; i < order.size(); ++i)
    {
        int x = order[i];
        for (int t : adj[x])
        {
            w[t] = add(w[t], {w[x].first, w[x].second * (LL)adj[x].size()});
        }
    }


    for (auto i : ends)
        cout << w[i].first << " " << w[i].second << "\n";
}
