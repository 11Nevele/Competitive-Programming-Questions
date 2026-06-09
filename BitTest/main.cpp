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

const int MAX = 100;
int bit[MAX];
inline int lowbit(int x) { return x & -x; }
void add(int bit[], int x, int t)
{
    while (x > 0)
    {
        bit[x] = max(bit[x], t);
        x -= lowbit(x);
    }
}

int bitMax(int bit[], int x)
{
    int ans = -INT_MAX;
    while (x < MAX)
    {
        ans = max(ans, bit[x]);
        x += lowbit(x);
    }
    return ans;
}

void test()
{
    add(bit, 1, 10);
    add(bit, 3, 6);
    add(bit, 5, 8);
    add(bit, 7, 3);
    add(bit, 9, 2);
    for (int i = 1; i < 11; ++i)
        write(bitMax(bit, i)), putchar('\n');
    add(bit, 10, 100);
    cout << "_____________________________\n";
    for (int i = 1; i < 11; ++i)
        write(bitMax(bit, i)), putchar('\n');
}
int main()
{
    test();
}
