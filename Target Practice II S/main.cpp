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


void solve()
{
    int n = read(), x1 = read();
    vector<pair<LL, LL>> coords, pos, neg;
    map<LL, LL> negSlope;
    map<LL,LL> posSlope;
    for (int i = 0; i < n; ++i)
    {
        int y1 = read(), y2 = read(), x2 = read();
        coords.push_back({ x1, y1 });
        coords.push_back({ x1,y2 });
        pos.push_back({ x2, y1 });
        neg.push_back({ x2,y2 });
    }
    int posCnt = 0, negCnt = 0;
    for (int i = 0; i < (n << 2); ++i)
    {
        int t = read();
        if (t > 0)
        {
            ++posCnt;
            auto it = posSlope.find(t);
            if (it != posSlope.end())
                (*it).second++;
            else
                posSlope.insert({ t, 1 });

        }
        else
        {
            ++negCnt;
            auto it = negSlope.find(t);
            if (it != negSlope.end())
                (*it).second++;
            else
                negSlope.insert({ t, 1 });

        }
    }
    if (posCnt < n || negCnt < n)
    {
        cout << -1 << endl;
        return;
    }
    auto com = [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second < b.second;
    };
    std::sort(coords.begin(), coords.end(), com);
    for (int i = 0; i < coords.size(); ++i)//determine which left vertex are hit by positve slope
    {
        if (i < posCnt - n)
            pos.push_back(coords[i]);
        else
            neg.push_back(coords[i]);
    }
    LL mx = 0, mn = 0;
    
    {
        LL l = -1e18, r = 1e18;
        while (l < r)
        {
            LL mid = (l + r) >> 1;
            auto set = negSlope;
            bool b = true;
            for (auto& i : neg)
            {
                LL t = (i.second - mid) / i.first;
                auto it = set.lower_bound(t);
                if (it != set.end())
                {
                    (*it).second--;
                    if ((*it).second == 0)
                        set.erase(it);
                }
                else
                {
                    b = false;
                    break;
                }
            }
            if (b)
                r = mid;
            else
                l = mid + 1;
        }
        mx = l;
    }
    {
        LL l = -1e18, r = 1e18;
        while (l < r)
        {
            LL mid = (l + r + 1) >> 1;
            auto set = posSlope;
            bool b = true;
            for (auto& i : pos)
            {
                LL t = (i.second - mid) / i.first;
                auto it = set.upper_bound(t);
                if (it != set.begin())
                {
                    --it;
                    if ((*it).first > t)
                    {
                        b = false;
                        break;
                    }
                    (*it).second--;
                    if ((*it).second == 0)
                        set.erase(it);
                }
                else
                {
                    b = false;
                    break;
                }
            }
            if (b)
                l = mid;
            else
                r = mid - 1;
        }
        mn = l;
    }

    cout << mx - mn << endl;
}
int main()
{
    int q = read();
    while (q--)
    {
        solve();
    }
}
