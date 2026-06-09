#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
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

public:
    std::vector<size_t> parent;
    std::vector<size_t> cnt;
    DSU(size_t size) :parent(size), cnt(size, 1)
    {
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
        int pa = parent[Find(a)], pb = parent[Find(b)];
        if (pa == pb)
            return;
        if (cnt[pa] > cnt[pb])
        {
            cnt[pa] += cnt[pb];
            parent[pb] = pa;
        }
        else
        {
            cnt[pb] += cnt[pa];
            parent[pa] = pb;
        }
    }
};
class Edge
{
public:
    int type;
    int a;
    int b;
    LL d;
    bool operator < (const Edge& other)
    {
        return d < other.d;
    }
};
int main()
{
    int n = read(), m = read(), p = read(), q = read();
    vector<Edge> edges(p + q);
    DSU dsuH(m + 1), dsuV(n + 1);
    int h = m, v = n;
    for (int i = 0; i < p; ++i)
        edges[i] = { 0, read(),read(),read() };
    for (int i = p; i < p + q; ++i)
        edges[i] = { 1, read(),read(),read() };
    sort(edges.begin(), edges.end());
    LL ans = 0;
    for (auto& e : edges)
    {
        if (e.type == 0)
        {
            if (dsuH.Find(e.a) == dsuH.Find(e.b))
            {
                ans += n * e.d;
                
            }
            else
            {
                ans += (n - v) * e.d;
                dsuH.Unite(e.a, e.b);
                h--;
            }
        }
        else
        {

            if (dsuV.Find(e.a) == dsuV.Find(e.b))
            {
                ans += m * e.d;
                
            }
            else
            {
                ans += (m - h) * e.d;
                dsuV.Unite(e.a, e.b);
                v--;
            }
        }
    }
    write(ans), putchar('\n');
    return 0;
}