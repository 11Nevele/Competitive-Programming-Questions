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
#include <fstream>
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
    std::vector<size_t> childCnt;
public:
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
        if (ta == tb)
            return;
        if (childCnt[ta] < childCnt[tb])
        {
            parent[ta] = parent[tb];
            childCnt[tb] += childCnt[ta] + 1;
        }
        else
        {
            parent[tb] = parent[ta];
            childCnt[ta] += childCnt[tb] + 1;
        }
        
    }
    size_t GetChildCnt(int n) { return childCnt[n]; }
};
bool XCom(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}
int main()
{
    ifstream fin("moop.in");
    ofstream fout("moop.out");
    
    int n;
    fin >> n;
    vector<pair<int,int>> coord(n);
    for (auto& i : coord)
        fin >> i.first >> i.second;
    sort(coord.begin(), coord.end(), XCom);
    vector<int> s;
    DSU dsu(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = s.size() - 1; j >= 0; --j)
            if (coord[s[j]].second >= coord[i].second || coord[s[j]].first == coord[i].first)
            {
                dsu.Unite(s[j], i);
            }
            else
                break;
        if (s.empty() || coord[s.back()].second < coord[i].second)
            s.push_back(i);
    }
    vector<bool> v(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int t = dsu.Find(i);
        if (!v[t])
        {
            ans += dsu.GetChildCnt(t);
            v[t] = true;
        }
    }
    fout << n - ans << endl;
}
