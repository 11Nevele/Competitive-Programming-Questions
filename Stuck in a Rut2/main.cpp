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
    
public:
    std::vector<size_t> parent, childCnt;
    DSU(size_t size)
    {
        parent.resize(size);
        for (int i = 0; i < size; ++i)
        {
            childCnt[i] = 0;
            parent[i] = i;
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
};
class cow {
public:
    int first; int second; int i;
    cow(int a, int b, int c) { first = a, second = b, i = c; };
};
bool XCom(const cow& a, const cow& b) { return a.first < b.first; }
bool YCom(const cow& a, const cow& b) { return a.second < b.second; }
int dfs(const vector<vector<int>>& block, vector<int>& ans, int n)
{
    if (ans[n] != 0)
        return ans[n];
    for (int i : block[n])
        ans[n] += dfs(block, ans, i) + 1;
    return ans[n];
}

int main()
{
    int n = read();
    vector<cow> east, north;
    vector<int> eastID, northID;
    for(int i = 0; i < n; i ++)
    {
        char c;
        cin >> c;
        int a = read(), b = read();
        if (c == 'E')
        {
            east.push_back(cow(a,b,i));
        }
            
        else
        {
            north.push_back(cow(a, b, i));
        }
            
    }
    sort(north.begin(), north.end(), XCom);
    sort(east.begin(), east.end(), YCom);
    vector<vector<int>> block (north.size() + east.size() + 1);
    vector<bool> v(east.size());
    for (int i = 0; i < north.size(); i++)
    {
        const auto& x = north[i];
        int nid = x.i;
        for (int j = 0; j < east.size(); j++)
        {
            const auto& y = east[j];
            int eid = y.i;
            if (!v[j] && x.first > y.first && x.second < y.second)
            {
                if (y.second - x.second > x.first - y.first)
                {
                    block[eid].push_back(nid);
                    break;
                }
                if (y.second - x.second < x.first - y.first)
                {
                    block[nid].push_back(eid);
                    v[j] = true;
                }
            }
        }
    }
    vector<int> ans(north.size() + east.size());
    for(int i = 0; i < n; i++)
    {
        write(dfs(block, ans, i));
        putchar('\n');
    }
}
