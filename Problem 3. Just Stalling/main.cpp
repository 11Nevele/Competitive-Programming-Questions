#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    long long ans = 1;
    int n = redn();
    vector<int> c(n), s(n);
    for (int& i : c)
        i = redn();
    for (int& i : s)
        i = redn();
    sort(s.begin(), s.end(), [](int a, int b) {return a > b; });
    sort(c.begin(), c.end(), [](int a, int b) {return a > b; });
    for (int j = 0; j < n; j++)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (s[i] < c[j])
                break;
        }
        
        ans *= (i - j);
    }
    cout << ans << endl;
}
