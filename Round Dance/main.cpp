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
int dfs(const vector<int>& adj, vector<int> &v, int n, int target)
{
    if (adj[n] == target)
    {
        v[n] = 1;
        return 1;
    }
    if (v[n] == -1)
        return -2;
    if (adj[n] == n)
    {
        v[n] = -1;
        return -1;
    }
    
    int temp = dfs(adj, v, adj[n], target);
    v[n] = temp > 0 ? 1 : -1;
    return temp;
}
int main()
{
    int t = read();
    while (t--)
    {
        int n = read();
        vector<int> adj(n + 1);
        for (int i = 0; i <= n; i++)
            adj[i] = i;
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            int x = read();
            if (adj[x] != i)
                adj[i] = x;
        }
        int loopCnt = 0, nonLoopCnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (v[i] == 0)
            {
                int temp = dfs(adj, v, i, i);
                if (temp == 1)
                    ++loopCnt;
                else if(temp == -1)
                    ++nonLoopCnt;
            }
        }
        int temp = (!!(nonLoopCnt)) + loopCnt;
        write(temp);
        putchar(' ');
        write(nonLoopCnt + loopCnt);
        putchar('\n');
    }
}
