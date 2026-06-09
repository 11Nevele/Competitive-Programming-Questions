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
const LL DEN = 387420489;
class fraction
{
public:
    LL num;
    LL den;
    double value;
    bool operator < (const fraction& other) const
    {
        return value < other.value;
    }
};
class range
{
public:
    fraction s;
    fraction e;
    bool operator < (const range& other) const
    {
        return s < other.s;
    }
};

vector<range> ranges;
int n;
fraction GetFraction(int num, int den)
{
    LL m = (DEN / den * n);
    return { m * num, den * m, (double) num/ (double)den};
}
void dfs(int den, int s, int e)
{
    if (den > DEN)
        return;
    ranges.push_back({ GetFraction(s + 1, den), GetFraction(e - 1, den) });
    dfs(den * 3, s * 3, (s + 1) * 3);
    dfs(den * 3, (e - 1) * 3, e * 3);
}

LL Get(LL t)
{
    int x = t / DEN;
    if (x * DEN < t)
        return (x + 1) * DEN;
    else
        return x * DEN;
}
int main()
{
    n = read();
   
    dfs(3, 0, 3);
    sort(ranges.begin(), ranges.end());
    int ind = 0;
    for (LL i = 0; i <= DEN * n; i += DEN)
    {
        while (ind < ranges.size() && ranges[ind].e.num <= i)
            ++ind;
        while (ind < ranges.size() && ranges[ind].s.num < i)
        {
            i = Get(ranges[ind].e.num);
            ++ind;
        }
        write(i / DEN), putchar('\n');
    }
    return 0;
}
//0.1111111 0.22222222222
//0.3333333 0.66666666
//0.7777777 0.888888888