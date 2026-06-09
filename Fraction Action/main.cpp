#include <iostream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int gcd(int a, int b)
{
    int r = a;
    while (r != 0)
    {
        r = b % a;
        b = a;
        a = r;
    }
    return b;
}
int main()
{
    int a = redn(), b = redn();
    int t = a / b;
    bool bo = false;
    if (a % b)
    {
        if (t > 0)
        {
            cout << t << " ";
            a = a % b;
        }
        int d = gcd(a, b);
        cout << a / d << "/" << b / d;
    }
    else
    {
        cout << a / b;
    }
    
    cout << endl;

}
