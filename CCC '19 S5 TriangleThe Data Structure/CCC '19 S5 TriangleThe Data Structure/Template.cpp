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
    int n = read(), k = read();
    vector<vector<LL>> triangle(n + 1, vector<LL>(n + 1)),
        psah(n + 1, vector<LL>(n + 1)),
        psal(n + 1, vector<LL>(n + 1)),
        psar(n + 1, vector<LL>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            triangle[i][j] = read();
            psah[i][j] = triangle[i][j] + psah[i][j - 1];
            psal[i][j] = triangle[i][j] + psah[i - 1][j];
            psar[i][j] = triangle[i][j] + psah[i - 1][j - 1];
        }
    LL cur = 0, mx = 0;
    for (int i = 1; i <= k; ++i)
        cur += psah[i][i];
    mx = max(cur, mx);
    for (int i = 2; i + k <= n; ++i)
    {
        cur = cur + psah[i + k - 1][k] - (psal[i - 1][k]);
        LL tmp = cur;
        mx = max(mx, tmp);
        for (int j = 2; j <= i; ++j)
        {
            tmp = tmp - (psal[i - 1][i + k - 1] - psal[i - 1][i + k]) + 
                (psal[i - j + 1][j - 1 + k] - psal[i - j + 1][j - 1]);
            mx = max(tmp, mx);
        }
    }
    write(mx), putchar('\n');
    return 0;
}