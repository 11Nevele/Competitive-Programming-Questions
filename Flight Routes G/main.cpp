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


int main()
{
    int n = read();
    vector<vector<int>> arr(n + 1, vector<int>(n + 1)), path(n + 1, vector<int>(n + 1)), direct(n + 1, vector<int>(n + 1));
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
            arr[i][j] = getchar() - '0';
        getchar();
    }
        
    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j + i <= n; ++j)
        {
            int t = j + i;
            for (int k = j + 1; k < t; ++k)
            {
                path[j][t] += direct[j][k] * path[k][t];
            }
            if (path[j][t] % 2 != arr[j][t])
            {
                ++ans;
                ++path[j][t];
                direct[j][t] = 1;
            }
            path[j][t] %= 2;
        }
    }
    write(ans), putchar('\n');
}
