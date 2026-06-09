#include <iostream>
#include <string>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int dic[27];
int main()
{
    for (int i = 1; i <= 26; i++)
    {
        char c = getchar();
        dic[c - 'a' + 1] = i;
    }
    int ans = 0, pre = 30;
    string s;
    cin >> s;
    for (char c : s)
    {
        int t = dic[c - 'a' + 1];
        if (t <= pre)
            ans++;
        pre = t;
    }
    cout << ans;

}
