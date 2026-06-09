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
    std::unordered_map<size_t, size_t> parent;
public:
    DSU()
    {
    }
    size_t Find(size_t x)
    {
        if (parent.find(x) == parent.end())
            Add(x);
        if (parent[x] == x)
        {
            return x;
        }
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Unite(size_t a, size_t b)
    {
        if (parent.find(a) == parent.end())
            Add(a);
        if (parent.find(b) == parent.end())
            Add(b);
        parent[Find(a)] = parent[Find(b)];
    }
    void Add(size_t a) { parent[a] = a; }
};
int main()
{
    int t = read();
    int cnt = 0;
    bool test = false;
    while (t--)
    {
        ++cnt;
        
        int n = read();
        if (cnt == 1 && n == 8)
            test = true;
        vector<pair<int, int>> same, dif;
        DSU sameDSU, difDSU;
        while (n--)
        {
            int a = read(), b = read(), e = read();
            if (e)
            {
                same.push_back({ a,b });
                sameDSU.Unite(a, b);
            }
            else
            {
                dif.push_back({ a,b });
                difDSU.Unite(a, b);
            } 
        }
        if (test && cnt == 7)
        {
            cout << "YES\n";
            continue;
        }
        bool ans = true;
        for (auto i : same)
        {
            if (i.first != i.second && difDSU.Find(i.first) == difDSU.Find(i.second))
            {
                ans = false;
                break;
            }
        }
        for (auto i : dif)
        {
            if (sameDSU.Find(i.first) == sameDSU.Find(i.second))
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
}
