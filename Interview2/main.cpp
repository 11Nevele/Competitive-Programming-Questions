
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <random>
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
bool Com(const pair<long long, int>& a, const pair<long long, int>& b)
{
    return a.first < b.first;
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
        int ta = Find(a), tb = Find(b);
        if(ta != tb)
        parent[ta] = parent[tb];
    }
};
void test()
{
    test();
}
int main()
{
    int n = read(), k = read();
    queue<long long> q;
    for (int i = 0; i < n; i++)
    {
        long long temp = rand() % 1000000000 + 1;
        q.push(temp);
    }
    set<pair<long long, int>> ma;
    for (int i = 0; i < k; ++i)
    {
        int t = q.front();
        ma.insert({ t,i });
        q.pop();
    }
    DSU dsu(k);
    long long ans = 0;
    int pos = -1;
    bool found = false;
    pair<long long, int> p = *ma.begin();
    while (!q.empty())
    {
        p = *ma.begin();
        ma.erase(ma.begin());
        ans = p.first;
        ma.insert({ ans + q.front(), p.second });
        q.pop();
        if (q.empty())
        {
            if(!ma.empty() && p.first == ma.begin()->first)
                dsu.Unite(p.second, ma.begin()->second);
            break;
        }
            
        while (!ma.empty() && p.first == ma.begin()->first)
        {
            if (p.first < 0) test();
            dsu.Unite(p.second, ma.begin()->second);
            if (q.empty())
            {
                break;
            }
            p = *ma.begin();
            ma.erase(ma.begin());
            ma.insert({ ans + q.front(), p.second });
            q.pop();
        }

    }

    cout << ma.begin()->first << endl;
    pos = ma.begin()->second;
    p = *ma.begin();
    ma.erase(ma.begin());
    while (!ma.empty() && p.first == ma.begin()->first)
    {
        if (p.first < 0) test();
        dsu.Unite(p.second, ma.begin()->second);
        p = *ma.begin();
        ma.erase(ma.begin());
    }
    
    for (int i = 0; i < k; i++)
    {
        if (dsu.Find(pos) == dsu.Find(i))
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}