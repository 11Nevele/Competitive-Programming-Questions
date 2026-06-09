#include <iostream>
#include<cstring>
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int arr[100005];
long long dp[100005];
int main()
{
    int n = redn(), k = redn();
    for (int i = 0; i < n; i++)
    {
        arr[i] = redn();
    }
    memset(dp, 1, sizeof(long long) * 100005);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
                break;
            long long t = abs(arr[i] - arr[i - j]) + dp[i - j];
            dp[i] = dp[i] < t ? dp[i] : t;
        }
    }
    std::cout << dp[n - 1] << '\n';
}