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
#include <fstream>
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
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Unite(size_t a, size_t b)
    {
        parent[Find(a)] = parent[Find(b)];
    }
};
int main()
{
    ifstream fin("closing.in");
    ofstream fout("closing.out");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> f(n);
    vector<bool> open(n + 1);
    stack<bool> ans;
    DSU dsu(n + 1);
    for (int& i : f)
        fin >> i;
    reverse(f.begin(), f.end());
    int cnt = 0;
    for (int i : f)
    {
        open[i] = true;
        ++cnt;
        for (int j : adj[i])
        {
            if (open[j] && dsu.Find(i) != dsu.Find(j))
            {
                dsu.Unite(i, j);
                --cnt;
            }
        }
        ans.push(cnt == 1);
    }
    while (!ans.empty())
    {
        fout << (ans.top() ? "YES" : "NO") << endl;
        cout << (ans.top() ? "YES" : "NO") << endl;
        ans.pop();
    }

}
