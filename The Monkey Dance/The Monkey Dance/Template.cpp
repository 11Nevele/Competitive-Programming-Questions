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
LL gcd(LL a, LL b)
{
    if (b > a)
        swap(a, b);
    while (b)
    {
        LL t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{

    while (true)
    {
        int n = read();
        if (n == 0)
            break;
        vector<int> to(n + 1), groups;
        for (int i = 1; i <= n; ++i)
            to[read()] = read();
        vector<bool> v(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (v[i])
                continue;
            int cur = i, cnt = 0;
            while (!v[cur])
            {
                v[cur] = true;
                cur = to[cur];
                ++cnt;
            }
            groups.push_back(cnt);
        }
        int ans = groups[0];
        for (int i = 1; i < groups.size(); ++i)
            ans = lcm(ans, groups[i]);
        write(ans), putchar('\n');
        
    }
    return 0;
}