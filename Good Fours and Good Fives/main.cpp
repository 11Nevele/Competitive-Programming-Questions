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
    int ans = 0;
    for (int i = 0; i <= n / 5; i++)
    {
        if ((n - i * 5) % 4 == 0)
            ans++;
    }
    cout << ans << endl;
    
}
