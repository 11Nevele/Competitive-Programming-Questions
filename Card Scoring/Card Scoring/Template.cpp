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
const int MX = 1000005;
vector<vector<int>> stacks(MX);
vector<vector<int>> pos(MX);
vector<int> arr(MX);
vector<double> dp(MX);
vector<int> cnt(MX);
double k;
int n;
vector<double> pw(MX);
double f(int x, int i, int j)
{
    return dp[pos[x][j]] + pw[i - j + 1];
}
int time(int x, int i, int j)
{
    int l = j, r = MX - 5;

    while (l < r)
    {
        int mid = (l + r) / 2;
        double a = f(x, mid, i), b = f(x, mid, j);
        if (a >= b)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
#define v(x) s[s.size()-x]
int main()
{
    k = read();
    n = read();
    for (int i = 1; i < MX; ++i)
        pw[i] = pow(i, k / 2);
    
    for (int i = 1; i <= n; ++i)
        arr[i] = read(), pos[arr[i]].push_back(i - 1);
    
    for (int i = 1; i <= n; ++i)
    {
        int curNumInd = cnt[arr[i]]++;
        vector<int>& p = pos[arr[i]];
        vector<int>& s = stacks[arr[i]];

        while (s.size() >= 2 && time(arr[i], v(2), v(1)) <= time(arr[i], v(1), curNumInd))
            s.pop_back();
        s.push_back(curNumInd);
        while (s.size() >= 2 && time(arr[i], v(2), v(1)) <= curNumInd)
            s.pop_back();

        dp[i] = f(arr[i], curNumInd, s.back());
    }
    cout << fixed << setprecision(9) << dp[n] << endl;

    return 0;
}