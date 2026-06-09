#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}

int main()
{
    int x = redn();
    vector<pair<string, string>> a(x);
    for (auto& i : a)
        cin >> i.first >> i.second;
    int y = redn();
    vector<pair<string, string>> b(y);
    for (auto& i : b)
        cin >> i.first >> i.second;
    unordered_map<string, int> map;
    int g = redn();
    while (g--)
    {
        for (int i = 0; i < 3; i++)
        {
            string temp;
            cin >> temp;
            map[temp] = g;
        }
    }
    int ans = 0;
    for (auto& i : a)
    {
        if (map[i.first] != map[i.second])
            ans++;
    }
    for (auto& i : b)
    {
        if (map[i.first] == map[i.second])
            ans++;
    }
    cout << ans << endl;
}