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

class DSU
{
private:
    std::vector<size_t> parent;
public:
    DSU(size_t size)
    {
        parent.resize(size);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }
    size_t Find(size_t x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        parent[x] = Find(x);
        return parent[x];
    }
    void Unite(size_t a, size_t b)
    {
        parent[Find(a)] = parent[Find(b)];
    }
};
int dfs(const vector<vector<int>>& adj, vector<bool>& v, int n)
{
    v[n] = true;
    int ans = 1;
    for (int i : adj[n])
    {
        if (!v[i])
        {
            ans += dfs(adj, v, i);
        }
    }
        
            
    return ans;
}
bool dfsFind(const vector<vector<int>>& adj, vector<bool>& v, int n, int target)
{
    if (n == target)
        return true;
    v[n] = true;
    bool ans = false;
    for (int i : adj[n])
        if (!v[i])
            ans = ans | dfsFind(adj, v, i, target);
    return ans;
}
void reset(vector<bool>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        arr[i] = false;
}
int main()
{
    int n = read(), d = read();
    int freeCnt = 1;
    vector<vector<int>> adj(n + 1);
    for (int t = 0; t < d; ++t)
    {
        int a = read(), b = read();
        vector<bool> v(n + 1);
        vector<int> s;
        if (dfsFind(adj, v, a, b))
        {
            freeCnt++;
        }
        else
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        reset(v);
        for (int i = 1; i <= n; ++i)
        {
            if (!v[i])
            {
                s.push_back(dfs(adj, v, i));
            }
        }
        sort(s.begin(), s.end(), greater<int>());
        int ans = 0;
        for (auto i = 0; i < freeCnt; i++)
            ans += s[i];
        cout << ans - 1 << endl;

    }
}
