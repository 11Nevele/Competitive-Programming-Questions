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
#include <fstream>
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
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<vector<long long>> dp(5005, vector<long long>(5005));
unordered_map<int, vector<short>> psa;
int n, q;
vector<int> arr(5005);
int main()
{
    ifstream fin("threesum.in");
    ofstream fout("threesum.out");
    fin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        fin >> arr[i];
        if (psa.find(arr[i]) == psa.end())
            psa.insert({ arr[i], vector<short>(5005) });
        ++psa[arr[i]][i];
    }
    for (auto& i : psa)
    {
        for (int j = 1; j <= 5000; ++j)
        {
            i.second[j] += i.second[j - 1];
        }
    }

    for (int i = 2; i < n; ++i)
    {
        for (int j = 1; j + i <= n; ++j)
        {
            
            int t = i + j, target = -(arr[j] + arr[t]);
            dp[j][t] = dp[j + 1][t] + dp[j][t - 1] - dp[j + 1][t - 1];

            if (psa.find(target) != psa.end())
            {
                dp[j][t] += psa[target][t - 1] - psa[target][j];
            }
        }
    }
    while (q--)
    {
        int a, b;
        fin >> a >> b;
        //cout << dp[a][b] << "\n";
        fout << dp[a][b] << "\n";
    }
}
