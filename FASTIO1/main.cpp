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
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Unite(size_t a, size_t b)
    {
        parent[Find(a)] = parent[Find(b)];
    }
};
#define FriendOf(x) (x)
#define PreyOf(x) (x + n)
#define PredatorOf(x) (x + (n << 1))
DSU dsu(200010);
int main()
{
    int n = read(), k = read(), ans = 0;
    while (k--)
    {
        int b = read(), x = read(), y = read();
        if (x > n || y > n)
        {
            ++ans;
            continue;
        }
        if (b == 1)
        {
            if (dsu.Find(FriendOf(x)) == dsu.Find(PreyOf(y)) ||
                dsu.Find(FriendOf(x)) == dsu.Find(PredatorOf(y)) ||
                dsu.Find(PredatorOf(x)) == dsu.Find(PreyOf(y)))
            {
                ++ans;
                continue;
            }
            dsu.Unite(FriendOf(x), FriendOf(y));
            dsu.Unite(PredatorOf(x), PredatorOf(y));
            dsu.Unite(PreyOf(x), PreyOf(y));
        }
        else
        {
            if (dsu.Find(FriendOf(x)) == dsu.Find(FriendOf(y)) ||
                dsu.Find(FriendOf(x)) == dsu.Find(PreyOf(y)) ||
                dsu.Find(PreyOf(x)) == dsu.Find(PredatorOf(y)))
            {
                ++ans;
                continue;
            }
            dsu.Unite(FriendOf(x), PredatorOf(y));
            dsu.Unite(PreyOf(x), FriendOf(y));
            dsu.Unite(PredatorOf(x), PreyOf(y));
        }
    }
    write(ans);
    putchar('\n');
}
