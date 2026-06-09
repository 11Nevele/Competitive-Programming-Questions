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
vector<vector<int>> st;
void StInit(int n, const vector<int>& arr)
{
    int size = log2(n);
    st.resize(size + 1, vector<int>(arr.size()));
    st[0] = arr;
    int pow = 1;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            st[i][j] = max(st[i - 1][j], st[i - 1][(j + pow) >= n ? n - 1 : (j + pow)]);
        }
        pow = pow << 1;
    }

}
int GetSt(int s, int e)
{
    int dif = e - s + 1, level = log2(dif), remain = dif - pow(2, level);
    return max(st[level][s], st[level][s + remain]);
}
int main()
{
	int n = read(), k =read();
	vector<int> arr(n + 1);
    vector<LL> psa(n + 1) ;
	vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, LL_MAX));
	for(int i = 1; i <= n; ++i)
		arr[i] = read(), psa[i] = arr[i] + psa[i-1];
	StInit(n + 1, arr);
    for(int i = 0; i <= k; ++i)
        dp[0][i] = 0;
    
    for (int i = 1; i <= n; ++i)
    {
		dp[i][0] = (LL)GetSt(1, i) * i - psa[i];
        for (int j = 1; j <= k; ++j)
        {
            for (int t = 0; t < i; ++t)
            {
                LL l = i - t;
                dp[i][j] = min(dp[i][j],
                    dp[t][j - 1] + (LL)GetSt(t + 1, i) * l - (psa[i] - psa[t]));
            }
        }
    }
    LL mn = LL_MAX;
    for (int i = 0; i <= k; ++i)
        mn = min(mn, dp[n][i]);
    write(mn), putchar('\n');
    return 0;
}