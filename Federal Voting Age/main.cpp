#include <iostream>
#include <cmath>
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
    //2007 2 27
    while (n--)
    {
        int y = redn(), m = redn(), d = redn();
        if ((2007 - y) < 18)
        {
            cout << "No\n";
            continue;
        }
        else if ((2007 - y) == 18)
        {
            if (m > 2)
            {
                cout << "No\n";
                continue;
            }
            else if(m == 2)
            {
                if (d > 27)
                {
                    cout << "No\n";
                    continue;
                }
            }
        }
        cout << "Yes\n";
    }
}
