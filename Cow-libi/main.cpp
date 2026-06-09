#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
long long dis(const pair<int, int>& a, const pair<int, int>& b)
{
    return pow(a.first - b.first,2) + pow(a.second - b.second,2);
}
int main()
{
    ifstream fin("2.in");
    int g, n;
    fin >> g >> n;
    vector<pair<int, int>> garden(g), cow(n);
    vector<int> gardenTime(g), cowTime(n);
    for (int i = 0; i < g; i++)
    {
        fin >> garden[i].first >> garden[i].second >> gardenTime[i];
        //garden[i].first = redn();
        //garden[i].second = redn();
        //gardenTime[i] = redn();
    }
    for (int i = 0; i < n; i++)
    {
        fin >> cow[i].first >> cow[i].second >> cowTime[i];

        //cow[i].first = redn();
        //cow[i].second = redn();
        //cowTime[i] = redn();
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        bool bb = true;
        for (int j = 0; j < g; j++)
        {
            int a = garden[j].first - cow[i].first, b = garden[j].second - cow[i].second;
             long long d = std::pow(a, 2) + std::pow(b, 2);
             long long dt = gardenTime[j] - cowTime[i];
             dt = std::pow(dt, 2);
            if (gardenTime[j] >= cowTime[i] && dt >= d)
            {
                bb = false;
                break;
            }
        }
        if (bb)
            ans++;
    }
    cout << ans << endl;
}
