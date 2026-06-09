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
#include <cstring>
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
int N, M, T;
pair<int, int> solveRange(int l, int r, vector<int>& psa1, vector<int>& psa2)
{
    int cur = max(psa1[r] - psa1[l - 1], psa2[r] - psa2[l - 1]);
    int ind = r, maxDif = -1;
    for (int i = l; i < r; ++i)
    {
        int t = max(psa1[i] - psa1[l - 1] + psa2[r] - psa2[i], psa2[i] - psa2[l - 1] + psa1[r] - psa1[i]);
        if (t - cur > maxDif)
        {
            maxDif = t - cur;
            ind = i;
        }

    }
    return { ind,maxDif };
}
int dp3[51][51];
int init(int x, int t, vector<int>& psa1, vector<int>& psa2)
{
    if (t == 0 || x > M)
        return 0;
    if (dp3[x][t] != -1)
        return dp3[x][t];
    
    int ma = 0;
    for (int i = x; i <= M; ++i)
    {
        ma = max(ma, max(psa1[i] - psa1[x - 1], psa2[i] - psa2[x - 1]) + init(i + 1, t - 1, psa1, psa2));
    }
    return dp3[x][t] = ma;
    return ma;
}

vector<vector<int>> dp(51, vector<int>(51)), dp2(51, vector<int>(2505, -1));

int distribution(int x, int t)
{
    if (t == 0 || x > N)
        return 0;
    if (dp2[x][t] != -1)
        return dp2[x][t];
    int ans = 0;
    for (int i = 0; i <= M && i <= t; ++i)
    {
        ans = max(ans, dp[x][i] + distribution(x + 1, t - i));
    }
    dp2[x][t] = ans;
    return ans;
}
int main()
{
    N = read(), M = read(), T = read();
    for (int j = 1; j <= N; ++j)
    {
        string str;
        cin >> str;
        vector<int> psa1(51), psa2(51);
        int i;
        for (i = 1; i <= str.size(); ++i)
        {
            if (str[i - 1] == '1')
                psa1[i]++;
            else psa2[i]++;
            psa1[i] += psa1[i - 1];
            psa2[i] += psa2[i - 1];
        }
        memset(dp3, -1, sizeof(dp3));
        for (int k = 1; k <= M; ++k)
            dp[j][k] = init(1, k, psa1, psa2);

    }
    
    cout << distribution(1, T) << endl;
}
