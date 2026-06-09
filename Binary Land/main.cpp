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
    vector<LL> sum;
    DSU(size_t size)
    {
        parent.resize(size);
        sum.resize(size);
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
        int pa = Find(a), pb = Find(b);
        if (pa == pb) return;
        parent[pa] = parent[pb];
        sum[pb] += sum[pa];
    }
};
int A[100005], highbit[100005];
bool hasHighbitAt[32], hasZeroAt[32];
DSU dsu(100050);
int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
    {
        A[i] = read();
    }
    for (int i = 1; i <= n; ++i)
    {
        dsu.sum[i] = read();
    }
    
    for (int i = 1; i <= n; ++i)
    {
        bool firstOne = true;
        for (int j = 30; j >= 0; --j)
        {
            if (firstOne && (A[i] & (1 << j))) highbit[i] = j, hasHighbitAt[j] = true, firstOne = false;
            if (!(A[i] & (1 << j)) && !firstOne) 
                hasZeroAt[j] = true;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (hasZeroAt[highbit[i]])
            dsu.Unite(i, n + highbit[i] + 1);
        for (int j = highbit[i]; j >= 0; j--)
        {
            if (!(A[i] & (1 << j)) && hasHighbitAt[j])
                dsu.Unite(i, n + 1 + j);
        }
            
    }

    for (int i = 1; i <= n; ++i)
    {
        write(dsu.sum[dsu.Find(i)]);
        putchar('\n');
    }

}
