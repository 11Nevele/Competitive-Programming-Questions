#include <iostream>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int arr[1005][1005];
int psa[1005];
int main()
{
    int n = redn();
    for (int i = 1; i <= n; i++)
    {
        arr[i][i] = redn();
        psa[i] = arr[i][i] + psa[i - 1];
    }
    for (int i = 1; i < n ; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int l = j, r = l + i;
            if (r > n)
                break;
            arr[l][r] = max(arr[l][l] + (psa[r] - psa[l] - arr[l + 1][r]),
                arr[r][r] + (psa[r - 1] - psa[l - 1] - arr[l][r - 1]));
        }
    }
    cout << arr[1][n] << endl;
}
