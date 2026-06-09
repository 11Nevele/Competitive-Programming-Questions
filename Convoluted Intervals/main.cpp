#include <iostream>
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
    int n = redn(), m = redn();
    vector<vector<short>> psa(m * 2 + 1, vector<short>(m * 2 + 1));
    vector<pair<unsigned short, unsigned short>> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i].first = redn();
        p[i].second = redn();
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            psa[p[i].first + p[j].first][p[i].second + p[j].second]++;
    p.clear();
    for (int i = 1; i <= m * 2; i++)
        for (int j = 1; j <= m * 2; j++)
            psa[i][j] += (psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1]);
    cout << "0\n";
    for (int i = 1; i <= m * 2; i++)
    {
        cout << psa[i][m*2] - psa[i][i - 1] << "\n";
    }
}
