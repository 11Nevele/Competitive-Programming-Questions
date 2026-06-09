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
#include <iomanip>
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
vector<int> line(1000005), last(500005);
vector<double> dp(500005);
int main()
{
    int n = read();
    //the order of last appearing,
    vector<int> arr;
    for (int i = 1; i <= n; ++i)
    {
        int t= read();
        line[i] = t;
        last[t] = i;
    }
    int first = line[1];
    for (int i = 0; i < 500005; ++i)
        if (last[i] != 0)
            arr.push_back(i);
    sort(arr.begin(), arr.end(), [](int a, int b) {return last[a] > last[b]; });
    
    if (arr[0] == first)
        dp[arr[0]] = 1;
    else
        dp[arr[0]] = 0;
    double curPossibility = 0;
    int cur = n;//next number to be added
    int firstCnt = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        int t = arr[i];
        int l = last[t];
        for (cur; cur > l; --cur)
        {
                curPossibility += dp[line[cur]];
        }
        if (t == first)
        {
            dp[t] = 1;
            continue;
        }
        dp[t] = (curPossibility + 1) / (n - l + 1);
    }
    for (cur;cur > 0; --cur)
        curPossibility += dp[line[cur]];
    cout << fixed << setprecision(7) << curPossibility / n << endl;
    return 0;
}