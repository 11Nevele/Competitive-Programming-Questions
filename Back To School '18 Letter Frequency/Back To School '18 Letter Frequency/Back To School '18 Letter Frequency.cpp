#include <iostream>
#include <vector>
#include<string>
using namespace std;
int v [1000001][26];
int main()
{
    cin.tie(NULL);
    int const minus = 97;
    int q;
    //v[0].resize(26);
    string str;
    getline(cin, str);
    cin >> q;
    int pre = 0;
    for (int i = 1; i <= str.size(); i++)
    {
        int t = (int)str[i - 1];
        memcpy(v[i], v[i - 1], sizeof(int) * 26);
        if (t != 32)
            v[i][(t - minus)]++;;
    }
    str.clear();
    for (int i = 0; i < q; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        c -= minus;
        printf("%d\n", v[b][(int)c] - v[a - 1][(int)c]);
    }
}
