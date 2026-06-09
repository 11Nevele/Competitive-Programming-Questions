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
    vector<double> a(n + 1), b(n);
    for (double& i : a)
        i = redn();
    for (double& i : b)
        i = redn();
    double ans = 0;
    for(int i = 0 ;i < n;i++)
    {
        ans += b[i] * ((min(a[i], a[i + 1])) + (abs(a[i] - a[i + 1]) / 2));
    }
    cout <<fixed<< ans << endl;
}
