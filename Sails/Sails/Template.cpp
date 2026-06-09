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

LL ad(LL x)
{
    return (1 + x) * x / 2;
}
vector<pair<int, int>> pole;
vector<LL> psa(100005);
LL check(LL mx)
{

    LL cum = 0;
    LL ans = 0;
    for (int i = 100000; i > 0; --i)
    {
        LL amt = psa[100000] - psa[i - 1] - cum;
        LL remain = psa[100000] - cum;
        mx = ceil ((double)remain / (double)i);
        if (amt < mx)
        {
            cum += amt;
            ans += ad(amt - 1);
        }
        else
        {
            cum += mx;
            ans += ad(mx - 1);
        }
    }
    return ans;
}
int main()
{
    int n = read();
    LL cum = 0;
    pole.resize(n);
    for (auto& i : pole)
        i.first = read(), i.second = read(), cum += i.second, psa[i.first + 1]--, psa[i.first - i.second + 1]++;
    for (int i = 1; i <= 100000; ++i)
        psa[i] += psa[i - 1];
    for (int i = 1; i <= 100000; ++i)
        psa[i] += psa[i - 1];
    LL l = 1, r = cum;

    write(check(cum)), putchar('\n');
    return 0;

}