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
int main()
{
    int n = read(), k = read();
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int temp = read();
        q.push(temp);
    }
    map<long long, int> m;
    for (int i = 0; i < k; ++i)
    {
        m.insert(q.front(), i);
        q.pop();
    }
    long long ans = 0;
    DSU dsu(k);
    while (!q.empty())
    {
        auto f = *m.begin();
        m.erase(m.begin());
        ans = f.first;
        int ind = f.second;
        m.insert((q.front() + ans), (long long)ind);
    }
}
