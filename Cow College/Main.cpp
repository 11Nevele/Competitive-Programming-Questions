#include <iostream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int arr[1000005];
int main()
{
    int n = redn();
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[redn()]++;
    }
    for (int i = 1; i <= 1000001; i++)
        arr[i] += arr[i - 1];
    /*int l = 1, r = 1000000;
    //long long lm, rm;
    while (l < r)
    {
        int mid = (l + r) / 2;
        long long lm = arr[1000001] - arr[l - 1], rm = arr[1000001] - arr[r - 1];
        if (lm * l < rm * r)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    long long ans = (arr[1000001] - arr[l - 1]) * (long long)l;*/
    long long ans = 0;
    int ans2 = 0;
    
    for (int i = 1; i <= 1000000; i++)
    {
        long long t = ((long long)arr[1000001] - arr[i - 1]) * i;
        if (t > ans)
        {
            ans = t;
            ans2 = i;
        }
    }
    cout << ans  << " " << ans2 << '\n';
}
