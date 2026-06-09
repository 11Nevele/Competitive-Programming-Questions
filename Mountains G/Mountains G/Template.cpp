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

double slope(vector<int>& h, int a, int b)
{
    return (double)(h[b] - h[a]) / (double)(b - a);
}
class cmp
{
public:
    bool operator ()(const pair<double, int>& a, const pair<double, int>& b) const
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};
int main()
{
    int n = read();
    vector<int> h(n + 1);
    vector<set<pair<double,int>, cmp >> mp(n + 1);
    for (int i = 1; i <= n; ++i)
        h[i] = read();
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        double preSlope = -INT_MAX;
        for (int j = i + 1; j <= n; ++j)
        {
            if (slope(h, i, j) >= preSlope)
            {
                mp[i].insert({ slope(h,i,j),j }), ++cnt;
                preSlope = slope(h, i, j);
            }
        }
            
    }

    int q = read();
    while (q--)
    {
        int a = read(), b = read();
        h[a] += b;
        cnt -= mp[a].size();
        mp[a].clear();
        double preSlope = -INT_MAX;
        for (int j = a + 1; j <= n; ++j)
        {
            if (slope(h, a, j) >= preSlope)
            {
                mp[a].insert({ slope(h,a,j),j });
                preSlope = slope(h, a, j);
            }
        }
        cnt += mp[a].size();
        for (int i = 1; i < a; ++i)
        {
            double s = slope(h, i, a);
            auto it = mp[i].upper_bound({ s,a });
            if (it != mp[i].end() && (*it).second <= a)
                continue;
            cnt -= mp[i].size();
            auto itt = mp[i].find({ (double)(h[a] - b - h[i]) / (double)(a - i), a });
            if (itt != mp[i].end())
                mp[i].erase(itt);
            mp[i].insert({s, a });
            it = mp[i].upper_bound({ s, -1 });
            if (it == mp[i].begin())
            {
                cnt += mp[i].size();
                continue;
            }
               
            --it;
            vector<set<pair<double,int>, cmp>::iterator> e;
            while (true)
            {
                if ((*it).second >= a)
                {
                    e.push_back(it);
                }
                    
                else
                    break;

                if (it == mp[i].begin())
                    break;
                --it;
            }
            for (auto& t : e)
                mp[i].erase(t);
            cnt += mp[i].size();
        }

        write(cnt), putchar('\n');

    }
    return 0;
}