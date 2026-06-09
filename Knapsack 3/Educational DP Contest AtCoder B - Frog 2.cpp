#include <iostream>
#include <vector>
#include <unordered_map>
inline  int redn() {
     int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
std::vector<unsigned int> n(5005);
unsigned int p[5005];
unsigned int v[5005];
unsigned int c[5005];
unsigned int f[5005];
unsigned long long dp[5005];
std::unordered_map<int, int> arr[5005];
int main()
{
    int N = redn(), M = redn();
    int mc = 0;
    for (int i = 1; i <= N; i++)
    {
        n[i] = redn();
        p[i] = redn();
        v[i] = redn();
    }
    for (int i = 1; i <= M; i++)
    {
        c[i] = redn();
        mc = c[i] > mc ? c[i] : mc;
        f[i] = redn();
    }
    
    for (int i = 1; i <= mc; i++)
    {
        int maxIndex = 0;
        int maxNode = 0;
        unsigned long long max = 0;
        for (int j = 1; j <= N; j++)
        {
            int node = i - p[j];
            int tt = 0;
            
            if (node < 0)
                continue;
            if (arr[node].find(j) != arr[node].end())
                tt = arr[node][j];
            if (n[j] - tt <= 0)
                continue;
            unsigned long long temp = dp[node] + v[j];
            if (temp >= max)
            {
                maxIndex = j;
                maxNode = node;
                max = temp;
            }
        }
        if (maxIndex > 0)
        {
            dp[i] = max;
            arr[i] = arr[maxNode];
            if (arr[i].find(maxIndex) != arr[i].end())
            {
                arr[i][maxIndex]++;
            }
            else
            {
                arr[i][maxIndex] = 1;
            }
        }
        else
        {
            dp[i] = dp[i - 1];
            arr[i] = arr[i - 1];

        }
        
    }
    long long ans = -999999999999;
    for (int i = 1; i <= M; i++)
    {
        long long temp = dp[c[i]] - f[i];
        if (temp > ans)
            ans = temp;
    }
    std::cout << ans << "\n";
}
