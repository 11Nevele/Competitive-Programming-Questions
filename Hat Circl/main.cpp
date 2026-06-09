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
    vector<int> arr(n);
    for (int& i : arr)
        i = redn();
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[i + n / 2])
            ans += 2;
    }
    cout << ans << endl;
}
