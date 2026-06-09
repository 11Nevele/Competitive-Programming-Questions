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
    int n = redn();
    string str;
    cin >> str;
    vector<vector<int>> ans(26, vector<int>(n + 1));
    for (char c = 'a'; c <= 'z'; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            int cnt = i, ind = 0;

            int temp = i;
            while (temp > 0 && ind < n)
            {
                if (str[ind] != c)
                    temp--;
                ind++;
            }
            while (ind < n && str[ind] == c)
                ind++;
            cnt = ind;
            for (int j = 0; ind < n; j++)
            {
                if (str[j] != c)
                {
                    ind++;
                    while (ind < n && str[ind] == c)
                        ind++;
                    cnt = max(ind - j - 1, cnt);
                }
            }
            ans[c - 'a'][i] = cnt;
        }
    }
    int q = redn();
    while (q--)
    {
        int t = redn();
        char c = getchar();
        
        cout << ans[c - 'a'][t] << "\n";
    }
}
