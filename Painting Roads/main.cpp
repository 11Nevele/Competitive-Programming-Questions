#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
void dfs(const vector<vector<pair<int, int>>>& adj, vector<char>& ans, vector<bool> &v, int n, bool c)
{
    
    for (auto& i : adj[n])
    {
        if (!v[i.first])
        {
            v[i.first] = true;
            ans[i.second] = c ? 'B' : 'R';
            dfs(adj, ans, v, i.first, !c);
        }
    }

}
int main()
{
    int n = redn(), m = redn();
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int a = redn(), b = redn();
        adj[a].push_back({ b,i });
        adj[b].push_back({a,i});
    }
    vector<char> ans(m, 'G');
    vector<bool> v(n + 1);
    for(int i = 1; i <= n; i++)
        if (!v[i])
        {
            v[i] = true;
            dfs(adj, ans, v, i, false);
        }
            
    for (int i = 0; i < m; i++)
    {
        putchar(ans[i]);
    }
    putchar('\n');
}
