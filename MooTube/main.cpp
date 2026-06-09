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
    
public:
    std::vector<size_t> parent, childCnt;
    DSU(size_t size)
    {
        parent.resize(size);
        childCnt.resize(size);
        for (int i = 0; i < size; ++i)
        {
            parent[i] = i;
            childCnt[i] = 0;
        }
            
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
        int ta = Find(a), tb = Find(b);
        if (ta != tb)
        {
            parent[ta] = parent[tb];
            childCnt[tb] += childCnt[ta] + 1;
        }
        
    }
};
class c
{
public:
    int a;
    int b;
    int c;
};
bool Com(const c& a, const c& b)
{
    return a.c < b.c;
}
bool Com2(const c& a, const c& b)
{
    return a.a > b.a;
}
int main()
{
    int N = read(), Q = read();
    vector<c> v(N - 1), q(Q);
    vector<int> ans(Q);
    for (int i = 0; i < N - 1; ++i)
    {
        v[i].a = read(), v[i].b = read(), v[i].c = read();
    }
    for (int i = 0; i < Q; ++i)
    {
        q[i].a = read(), q[i].b = read(), q[i].c = i;
    }
    sort(v.begin(), v.end(), Com);
    sort(q.begin(), q.end(), Com2);
    DSU dsu(N + 1);
    for (auto& i : q)
    {
        while (!v.empty() && v.back().c >= i.a)
        {
            dsu.Unite(v.back().a, v.back().b);
            v.pop_back();
        }
        ans[i.c] = dsu.childCnt[dsu.Find(i.b)];
    }
    for (int i : ans)
    {
        write(i);
        putchar('\n');
    }
}
