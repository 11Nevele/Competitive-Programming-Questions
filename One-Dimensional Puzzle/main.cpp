#include <iostream>
#include <vector>
#include <cmath>
#define P 998244353
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
long long f(const vector<long long>& factorial, int u, int b)
{
    long long a = (factorial[u]), b = ((factorial[b] * factorial[u - b]) % 998244353);
    cout << a << " " << b << endl;
    return (a / b);
}
int main()
{
    vector<long long> factorial(10000001);
    factorial[0] = 1;
    for (int i = 1; i <= 10000000; ++i)
        factorial[i] = (i * factorial[i - 1]) % 998244353;
    int t = redn();
    while (t--)
    {
        vector<int> n(4);
        for (int& i : n)
            i = redn();
        if (abs(n[0] - n[1]) > 1)
        {
            cout << "0" << endl;
        }
        else if (abs(n[0] - n[1]) == 1)
        {
            int k = max(n[0], n[1]);
            long long ans = (f(factorial, n[2] + k - 1, k - 1) * f(factorial, n[3] + k - 1, k - 1)) % 998244353;
            cout << ans << endl;
        }
        else
        {
            int k = n[0];
            long long p1 = (f(factorial, n[2] + k, k) * f(factorial, n[3] + k - 1, k - 1)) % 998244353;
            long long p2 = (f(factorial, n[2] + k - 1, k - 1) * f(factorial, n[3] + k, k)) % 998244353;
            cout << (p1 + p2) % 998244353 << endl;
        }
    }
}
