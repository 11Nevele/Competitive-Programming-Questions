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
int psa[3005][3005], ans[3005];
int lcp[3005][3005];
string str;
int main()
{
    int n = read();
    cin >> str;
    for (int d = 1; d < n - 1; ++d)
    {
        for (int j = n - 1, i = j - d; i >= 0; --i, --j)
        {
            lcp[i][j] = lcp[i + 1][j + 1];
            if (str[i] == str[j])
                ++lcp[i][j];
            else
                lcp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i)//l
    {
        stack<int> s;
        int mx[3005], mn[3005];
        for (int j = 0; j + i < n; ++j)
        {
            
            while (!s.empty())
            {
                int t = lcp[s.top()][j];
                if (t < (i + 1) && str[j + t] < str[s.top() + t])
                    s.pop();
                else break;
            }
            if (s.empty())mn[j] = -1;
            else mn[j] = s.top();
            s.push(j);
        }
        while (!s.empty())s.pop();
        for (int j = n - i - 1; j >= 0; --j)
        {
            while (!s.empty())
            {
                int t = lcp[j][s.top()];
                if (t >= (i + 1) || str[j + t] <= str[s.top() + t])
                    s.pop();
                else break;
            }
            if (s.empty())mx[j] = n - i;
            else mx[j] = s.top();
            s.push(j);
        }
        for (int j = 0; j < n - i; ++j)
            ++psa[i][i + 1], --psa[i][i + mx[j] - mn[j]];
        for (int j = i + 1; j <= n; ++j)
            psa[i][j] += psa[i][j - 1];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            ans[psa[j][i + 1]]++;
    for (int i = 1; i <= n; ++i)
        write(ans[i]), putchar('\n');

    return 0;
}
