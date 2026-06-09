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
LL path[1 << 18][18], cycle[1 << 18], ans[1 << 18];
bool adj[18][18];
int main()
{
    int n = read();
    for (int i = 0; i < n; ++i)
    {
        int temp[18]{};
        for (int j = 0; j < n; ++j)
            temp[j] = read() - 1;
        for (int j = 0; j < n; ++j)
        {
            adj[i][temp[j]] = true;
            if (temp[j] == i) break;
        }
    }

    for (int i = 0; i < n; ++i)
        path[1 << i][i] = 1;
    for (int i = 1; i <= (1 << n); ++i)
    {
        int lowbit = log2(i & -i);
        for (int pre = lowbit; pre < n; ++pre)
        {
            if (!((1 << pre) & i) || !path[i][pre]) continue;
            
            if (adj[pre][lowbit]) cycle[i] += path[i][pre];

            for (int j = lowbit + 1; j < n; ++j)
            {
                if ((1 << j) & i) continue;
                if (adj[pre][j]) path[(1 << j) | i][j] += path[i][pre];
            }
        }
    }
    ans[0] = 1;
    for (int i = 1; i <= (1 << n); ++i)
    {
        int lowbit = i & (-i);
        for (int j = i; j > 0; j = i & (j - 1))
        {
            if (!(lowbit & j)) continue;
            int t = i - j;
            ans[i] += (cycle[j]) * ans[t];
        }
    }
    int q = read();
    while (q--)
    {
        int a = 0, b = 0;
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); ++i)
            if (str[i] == 'H')
                a = a | (1 << i);
            else
                b = b | (1 << i);
        write((ans[a]) * (ans[b]));
        putchar('\n');
    }
    return 0;
}
