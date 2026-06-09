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
#include <functional>
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


template<>
class std::hash <pair<LL,LL>>
{
public:
    size_t operator() (const pair<LL, LL>& a) const
    {
        hash<LL> h1, h2;
        return h1(a.first) ^ h2(a.second);
    }
};
using MAP = map<pair<LL, LL>, vector<int>>;
MAP mpb;
vector<vector<pair<LL,LL>>> mpa(25);
vector<pair<LL,LL>> a(25), b(25);
void dfs(LL x, LL y, int ind, int cnt)
{
    mpa[cnt].push_back({ x,y });
    for (int i = ind + 1; i < a.size(); ++i)
    {
        dfs(x + a[i].first, y + a[i].second, i, cnt + 1);
    }
}
void dfs2(LL x, LL y, int ind, int cnt)
{
    pair<LL, LL> tmp = { x,y };
    if (mpb.find(tmp) == mpb.end())
        mpb[tmp].resize(21);
    mpb[tmp][cnt]++;
    for (int i = ind + 1; i < b.size(); ++i)
    {
        dfs2(x + b[i].first, y + b[i].second, i, cnt + 1);
    }
}
int main()
{
    int n = read();
    pair<LL, LL> target = { read(), read() };
    int cntA = n / 2, cntB = n - cntA;
    a.resize(cntA), b.resize(cntB);
    for (int i = 0; i < cntA; ++i)
        a[i] = { read(), read() };
    for (int i = 0; i < cntB; ++i)
        b[i] = { read(),read() };
        dfs(0, 0, -1, 0);
        dfs2(0, 0, -1, 0);
    vector<LL> ans(n + 1);
    
    for (int i = 0; i <= cntA; ++i)
    {
        for (auto& a : mpa[i])
        {
            pair<LL, LL> t = {target.first - a.first, target.second - a.second};
            const vector<int>& arr = mpb[t];
            for (int j = 0; j < arr.size(); ++j)
                ans[i + j] += arr[j];
        }
    }
    for (int i = 1; i <= n; ++i)
        write(ans[i]), putchar('\n');
    return 0;
}