#include<algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
int pathCnt = 0;
int ans = 0;
vector<bool>visted;
unordered_map<int, int> target;
vector<int> arr, v;
void dfs(int x, vector<vector<int>>& adj, int p)
{
    bool flag = false;
    for (int i = 0; i < target[x]; ++i)
        arr.push_back(x);
    if (adj[x].size() == 1)
    {
        if (!arr.empty())
        {
            target[arr.back()]--;
            arr.pop_back(); 
            ++ans;
        }
        
    }
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (adj[x][i] == p)
            continue;
        dfs(adj[x][i], adj, x);
    }
    for (int i = 0; i < target[x]; ++i)
        arr.pop_back();
}
int main()
{
    int n = read();
    vector<int> p(n);
    vector<vector<int>>adj(n + 1);
    v.resize(n + 1);
    for (int i = 0; i < n; i++)
        p[i] = read();
    for (int i = 1; i < n; i++)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (adj[i].size() == 1 && i != 1) 
            pathCnt++;
    for (int i = 0; i < pathCnt; i++)
        target[p[i]]++;
    dfs(1, adj, -1);
    cout << ans << endl;
}