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
    int n = redn(), k = redn();
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = i + 1;
    for (int i = 0; i < k - 1; i++)
        ans[n - i] = n - i;
    ans[n - k + 1] = 1;
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
    cout << ans[n] << endl;
}
