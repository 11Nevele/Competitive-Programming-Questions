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
//#include <deque>
int K;
LL dpD[100005][21], dpU[100005][21];
vector<int> adj[100005];
int parent[100005];
int value[100005];
LL dfsD(int n, int k)
{
    if (dpD[n][k] != 0)
        return dpD[n][k];
    if (k == 0)
        return value[n];
    for (int& i : adj[n])
        if(i != parent[n])
            dpD[n][k] += dfsD(i, k - 1);
    dpD[n][k] += value[n];
    return dpD[n][k];
}
LL dfsU(int n, int k)
{
    if (parent[n] == -1)
        return 0;
    if (k == 1)
        return value[parent[n]];
    
    dpU[n][k] = dfsU(parent[n], k - 1) + dfsD(parent[n],k-1);
    if (k > 1)
        dpU[n][k] -= dfsD(n,k - 2);
    return dpU[n][k];
}
void build(int n, int p)
{
    parent[n] = p;
    for (int& i : adj[n])
        if(i != p)
            build(i, n);
}
int main()
{
    int n = read(), k = read();
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    build(1, -1);
    for (int i = 1; i <= n; ++i)
        value[i] = read();
    for (int i = 1; i <= n; ++i)
    {
        dfsD(i, k);
    }
    for (int i = 1; i <= n; ++i)
    {
        dfsU(i, k);
    }
    for (int i = 1; i <= n; ++i)
    {
        write(dpU[i][k] + dpD[i][k]);
        putchar('\n');
    }

}
