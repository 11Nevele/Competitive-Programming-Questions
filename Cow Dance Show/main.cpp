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
long long FinishTime(const vector<int>& dance, int k)
{
    map <long long, int> s;
    int ind = 0;
    for (int i = 0; i < k; i++)
    {
        auto t = s.find(dance[ind]);
        if (t == s.end())
        {
            s.insert({ dance[ind], 1 });
        }
        else
        {
            t->second += 1;
        }
        ++ind;
    }
    while (ind < dance.size())
    {
        auto f = s.begin();
        int time = f->first;
        if (f->second > 1)
        {
            f->second -= 1;
        }
        else
        {
            s.erase(f);
        }
        auto t = s.find(dance[ind] + time);
        if (t == s.end())
        {
            s.insert({ dance[ind] + time, 1 });
        }
        else
        {
            t->second += 1;
        }
        ++ind;
    }
    return s.rbegin() -> first;
}
int Binary(const vector<int>& dance, int maxTime)
{
    int l = 1, r = dance.size();
    while (l < r)
    {
        int mid = (l + r) / 2;
        long long time = FinishTime(dance, mid);
        if (time <= maxTime)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
int main()
{
    int n = read(), maxTime = read();
    vector<int> dance(n);
    for (int& i : dance)
        i = read();
    cout << Binary(dance, maxTime) << endl;;
}
