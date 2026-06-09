#include <iostream>
#include <string>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int k = redn();
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        //a + 3i + k = b
        //a = b - 3i - k
        int t = str[i];
        t = t - 'A' - 3 * (i + 1) - k;
        if (t < 0)
            t = 26 + t;
        str[i] = t + 'A';
    }
    cout << str << endl;
}
