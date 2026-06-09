#include <iostream>
#include <vector>
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
    int t = redn(), n = redn();
    while (t--)
    {
        vector<int> v(26);
        string str;
        cin >> str;
        for (char c : str)
            v[c - 'a']++;
        bool t = (v[str[0] - 'a'] > 1);
        bool ans = true;
        for (int i = 1; i < n; i++)
        {
            if (t)
            {
                if (v[str[i] - 'a'] > 1)
                {
                    ans = false;
                    break;
                }
                    
                t = false;
            }
            else
            {
                if (v[str[i] - 'a'] < 2)
                {
                    ans = false;
                    break;
                }
                t = true;
            }
        }
        if (ans)
        {
            cout << "T\n";
        }
        else
        {
            cout << "F\n";
        }
    }
    
}
