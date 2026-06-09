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
LL C2(LL a)
{
    return a * (a - 1) / 2;
}

LL C3(LL a)
{
    return a * (a - 1) * (a - 2) / 6;
}
int half;
int cross(int i)
{
    return i + half;
}
int reach(int i)
{
    return i + half - 1;
}
vector<LL> arr(2000005), psa(2000005);
void EvenSolve(int n, int c)
{
    half = c / 2;

    LL ans = 0, cur = 0;
    for (int i = 2; i < half; ++i)
    {
        int s = half, e = min(c - 1, i + half);
        cur += (psa[e - 1] - psa[s]) * arr[i];
    }
    ans += cur * arr[0];
    for (int i = 1; i < half; ++i)
    {
        //remove cur
        cur -= arr[cross(i)] * (psa[reach(i - 1)] - psa[i]);
        cur += arr[reach(i)] * (psa[reach(reach(i))] - psa[cross(i)]);
        ans += cur * arr[i];
    }
    write(ans), putchar('\n');
    if (ans < 0)
        putchar('/');
}
void OddSolve(int n, int c)
{
    half = ceil((double)c / 2);

    LL ans = 0, cur = 0;
    for (int i = 1; i < half; ++i)
    {
        int s = reach(0), e = reach(i);
        cur += (psa[e] - psa[s]) * arr[i];
    }
    ans += cur * arr[0];
    for (int i = 1; i < half - 1; ++i)
    {
        //remove cur
        cur -= arr[reach(i)] * (psa[reach(i - 1)] - psa[i - 1]);
        cur += arr[reach(i)] * (psa[reach(reach(i))] - psa[reach(i)]);
        ans += cur * arr[i];
    }
    write(ans), putchar('\n');
    if (ans < 0)
        putchar('?');
}
int main()
{
    int n = read(), c = read();
    for (int i = 0; i < n; ++i)
        arr[read()]++;
    psa[0] = arr[0];
    for (int i = 1; i <= 2 * c; ++i)
        psa[i] = psa[i - 1] + arr[i];
    if (c & 1)
        OddSolve(n, c);
    else
        EvenSolve(n, c);
    return 0;
}