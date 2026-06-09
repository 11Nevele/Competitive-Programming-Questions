#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100005];
bool pho[100005];
int del(int x, int p)
{
    int cnt = 0;
    vector<int> ne;
    for (int i : adj[x])
    {
        if (i == p)
            continue;
        int t= del(i, x);
        cnt += t;
        if (t != 0)
            ne.push_back(i);
    }
    if (p != -1)
        ne.push_back(p);
    if (pho[x])
        ++cnt;
    adj[x] = ne;
    return cnt;
}
pair<int, int> furest(int x, int p)
{
    int pt = 0, mx = 0;
    for (int i : adj[x])
    {
        if (i == p)
            continue;
        auto t = furest(i, x);
        if (t.first > mx)
        {
            mx = t.first;
            pt = t.second;
        }

    }
    ++mx;
    return{ mx,pt };
}
int it(int x, int p)
{
    int tot = 0;
    for (int i : adj[x])
    {
        if (x == p)
            continue;
        tot += it(i, x) + 1;
    }
    return tot;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int s = 0;
    for (int i = 0; i < m; ++i)
    {
        int a;
        cin >> a;
        s = a;
        pho[a] = true;
    }
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    del(s, -1);
    auto t = furest(s, -1);
    s = t.first;
    t = furest(s, -1);
    int l = t.second;
    cout << it(s, -1) - l << endl;
}
