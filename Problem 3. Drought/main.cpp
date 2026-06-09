#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int t = redn();
    while (t--)
    {
        int n = redn();
        
        long long ans = 0;
        vector<int> arr(n);
        for (int& i : arr)
            cin >> i;
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int j = 0; j < 2; j++)
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (arr[i] > arr[i - 1])
                {
                    int dif = arr[i] - arr[i - 1];
                    ans += dif + dif;
                    arr[i] -= dif;
                    arr[i + 1] -= dif;
                }
            }
            if (arr[n - 1] > arr[n - 2])
            {
                ans = -1;
                break;
            }
            reverse(arr.begin(), arr.end());
        }
        if (arr[0] >= 0)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}
