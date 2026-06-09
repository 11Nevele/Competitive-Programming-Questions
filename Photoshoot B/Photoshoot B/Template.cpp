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
int main()
{
    int n = read(), ans = 0;
    vector<bool> arr(n + 1), a;
    for (int i = 1; i <= n; ++i)
        arr[i] = getchar() == 'G';
    for (int i = 1; i <= n; i += 2)
    {
        if (arr[i] == arr[i + 1])
            continue;
        if (arr[i] && !arr[i + 1])
            a.push_back(1);
        else 
            a.push_back(0);
    }
    a.push_back(0);
    for (int i = 1; i < a.size(); ++i)
        if (a[i] != a[i - 1])
            ++ans;
    write(ans), putchar('\n');
    return 0;
}