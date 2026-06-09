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
double c[1001];
double score[1001];


double calc(double ans, double a, double b, double q)
{
    ans = ans * pow(a, q) + b * ((1 - pow(a, q)) / (1 - a));
    return ans;
}
int main()
{
    int n = read(), k = read();
    c[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = i; j > 0; --j)
            c[j] = (c[j] + c[j - 1]) / 2;
    }
    for (int i = 1; i <= n; ++i)
    {
        score[i] = score[i - 1] + c[i] * i;
        c[i] += c[i - 1];
    }

    double ans = ((double)n + 1) / 2;
    int cnt = 1;
    while (true)
    {
        int bound = ceil(ans) - 1, q = k - cnt;
        double a = c[bound], b = score[n] - score[bound];
        if (ceil(calc(ans, a, b, q)) - 1 == bound)
        {
            ans = calc(ans, a, b, k - cnt);
            break;
        }
        int l = 1, r = q;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int res = ceil(calc(ans, a, b, mid)) - 1;
            if (res != bound)
                r = mid;
            else
                l = mid + 1;
        }
        

        q = l;
        cnt += q;
        if (a == 1 && b == 0)
            cnt = cnt;
        else
            ans = calc(ans, a, b, q);
    }
    
    //Ex + q = Ex * pow(a, q) + b * (1 - pow(a, 2) / (1 - a))
    cout << fixed << ans << endl;
    return 0;
}
