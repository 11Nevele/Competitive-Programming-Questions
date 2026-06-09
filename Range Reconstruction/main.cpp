#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int n = redn();
    vector<vector<int>> arr(n, vector<int>(n));
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            arr[i][j] = redn();
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = ans[i + 1] + arr[i][i + 1];
        int mi = 2147483647, ma = -2147483647;
        bool t = false;
        for (int j = i; j < n; j++)
        {
            mi = min(mi, ans[j]);
            ma = max(ma, ans[j]);
            if (ma - mi != arr[i][j])
            {
                t = true;
                break;
            }
        }
        if (t)
        {
            ans[i] = ans[i + 1] - arr[i][i + 1];
        }
    }
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << " ";
    cout << ans[n - 1] << endl;
}
