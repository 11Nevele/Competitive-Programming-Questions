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
int arr[10][50005];
int nxt[10][50005];
int lim[10][50005];
int main()
{
    int k = read(), n = read();
    for (int i = 1; i <= k; ++i)//input
    {
        for (int j = 1; j <= n; ++j)
        {
            char c = getchar();
            if (c == '(')
                arr[i][j] = 1;
            else
                arr[i][j] = -1;
            arr[i][j] += arr[i][j - 1];
        }
        getchar();
    }

    for (int i = 1; i <= k; ++i)//nxt
    {
        stack<int> s;
        for (int j = 1; j <= n; ++j)
        {
            if (arr[i][j] == 1)
                s.push(j);
            else if (!s.empty())
            {
                nxt[i][s.top()] = j;
                s.pop();
            }
        }
    }

    for (int i = 1; i <= k; ++i)//lim
    {
        for (int j = n; j > 0; --j)
        {
            if (arr[i][j] == -1)
                lim[i][j] = j;
            else if (nxt[i][j] == 0)
                lim[i][j] = INT_MAX;
            else
                lim[i][j] = lim[i][nxt[i][j]];

            if (i == 1)
                lim[0][j] = lim[i][j];
            else
                lim[0][j] = min(lim[0][j], lim[i][j]);
        }
    }



}
