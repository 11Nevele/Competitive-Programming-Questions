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
class cord
{
public:
    int x;
    int y;
    int a;
    bool operator < (const cord& other) const
    {
        if (y == other.y)
            return x > other.x;
        return y < other.y;
    }
};
int main()
{
    int  n = read();
    vector<cord> a, c;
    for (int i = 0; i < n; ++i)
    {
        int q = read(), t = read(), x = read(), k = read();
        if (q == 1)
            c.push_back({ x + t, x - t, k });
        else
            a.push_back({ x + t,x - t,k });
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    map<int, int> mp;
    int ind = 0, ans = 0;
    for (auto& i : c)
    {
        while (ind < a.size() && a[ind].y <= i.y)
            mp[a[ind].x] += a[ind].a, ++ind;
        while (i.a)
        {
            auto it = mp.lower_bound(i.x);
            if (it == mp.end())
                break;
            if ((*it).second > i.a)
                ans += i.a, (*it).second -= i.a, i.a = 0;
            else
                ans += (*it).second, i.a -= (*it).second, mp.erase(it);
        }
    }
    write(ans), putchar('\n');

    return 0;
}