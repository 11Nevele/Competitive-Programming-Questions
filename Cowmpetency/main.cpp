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

bool solve()
{
    int n = read(), q = read(), c = read();
    vector<int> arr(n + 1), b(n + 1), pre(n + 1);
    for (int i = 1; i <= n; ++i)
        arr[i] = read(), pre[i] = i;
    while (q--)
    {
        int x = read(), y = read();
        pre[y] = min(pre[y], x);
        b[y] = 1;
    }
    for (int s = n, f = n + 1; s > 0; --s)
    {
        if (f < s)
        {
            if (b[s] == 1)//conflict return
                return false;
            b[s] = -1;
        }
        f = min(f, pre[s]);
    }
    for (int i = 1, mx = 0, p = 0; i <= n; ++i)
    {
        if (!arr[i])
        {
            switch (b[i])
            {
            case -1: arr[i] = 1; break;
            case 0: arr[i] = 1, p = i; break;
            case 1: arr[i] = mx + 1; p = i;
            }
        }
        else if (b[i] == -1 && arr[i] > mx)
        {
            if (!p)
                return false;
            arr[p] = arr[i];
        }
        mx = max(mx, arr[i]);
        
    }
    for (int i = 1, mx = 0; i <= n; ++i)
    {
        if (b[i] == 1 && arr[i] <= mx) return false;
        if (b[i] == -1 && arr[i] > mx) return false;
        mx = max(mx, arr[i]);
        if (mx > c)//exceed max
            return false;
    }
    for (int i = 1; i < n; ++i)
        cout << arr[i] << " ";
    cout << arr[n] << endl;
    return true;
}
int main()
{
    int q = read();
    while (q--)
    {
        if (!solve())
            cout << -1 << endl;
    }
}
