#include <iostream>
#include <string>
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
    string a, b;
    cin >> a >> b;
    vector<int>va(26), vb(26);
    for (int i = 0; i < a.size(); i++)
    {
        va[a[i] - 'a']++;
        if(b[i] != '*')
        vb[b[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (vb[i] > va[i])
        {
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "A" << endl;
}
