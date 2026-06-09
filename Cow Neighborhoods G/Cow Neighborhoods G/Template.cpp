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
    std::vector<int> cnt;
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
DSU dsu(100005);
int main()
{
    LL n = read(), c =read();
    vector<pair<LL,LL>> arr(n);
    for (auto& i : arr)
    {
        LL a = read(), b = read();
        i.first = a + b, i.second = a - b;
    }
    sort(arr.begin(), arr.end());
    set<pair<LL,int>> s;
    for (int i = 0, ind = 0; i < arr.size(); ++i)
    {
        while (ind < i && arr[i].first - arr[ind].first > c)
            s.erase(s.find({ arr[ind].second, ind })), ++ind;
        auto it = s.lower_bound({ arr[i].second,0 });
        if (it != s.end())
            if((*it).first - arr[i].second <= c)
                dsu.Unite((*it).second, i);
        if (it != s.begin())
        {
            --it;
            if(arr[i].second - (*it).first <= c)
                dsu.Unite((*it).second, i);
        }
        s.insert({ arr[i].second, i });
    }
    vector<int> v(n);
    int cnt = 0, mx = 0;
    for (int i = 0; i < n; ++i)
    {
        int t = dsu.Find(i);
        if (v[t])
            continue;
        v[t] = true;
        ++cnt;
        mx = max(mx, dsu.cnt[t]);
    }
    write(cnt), putchar(' '), write(mx), putchar('\n');
    return 0;
}