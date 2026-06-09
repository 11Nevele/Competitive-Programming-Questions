#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int n, m;
vector<int> w[105];
vector<int> v[105];
int dp[105][1005];
int main()
{
    m = redn();
    n = redn();
    for (int i = 0; i < n; i++)
    {
        int a = redn(), b = redn(), c = redn();
        w[c].push_back(a);
        v[c].push_back(b);
    }
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= m; j++) // max weight
        {
            int maxV = 0;
            int maxW = 0;
            for (int k = 0; k < w[i].size(); k++)
            {
                if (w[i][k] <= j && v[i][k] > maxV)
                {
                        maxV = v[i][k];
                        maxW = w[i][k];
                }
            }
            dp[i][j] = max(dp[i - 1][j - maxW] + maxV, dp[i - 1][j]);
        }
    }
    cout << dp[100][m] << endl;
}
