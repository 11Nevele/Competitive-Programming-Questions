#include <iostream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int even = 0, odd = 0, ans = 0;
    int n = redn();
    for (int i = 0; i < n; i++)
    {
        int t = redn();
        if (t % 2)
            odd++;
        else
            even++;
    }
    bool e = true;
    while (true)
    {
        if (e)
        {
            if (even > 0)
            {
                ans++;
                even--;
            }
            else if (odd >= 2)
            {
                ans++;
                odd -= 2;
            }
            else
                break;
        }
        else 
        {
            if (odd > 0)
            {
                ans++;
                odd--;
            }
            else
                break;
        }
        e = !e;
    }
    if (odd > 0)
        ans -= 1;
    cout << ans << endl;
}
