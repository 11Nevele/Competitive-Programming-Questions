#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    ifstream fin("lazy.in");
    ofstream fout("lazy.out");
    int n, k;
    fin >> n >> k;
    vector<vector<int>> psa(n + 2, vector<int>(n + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fin >> psa[i][j];
            psa[i][j] += psa[i][j - 1];
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int sum = 0;
            for (int t = 0; t <= k * 2; t++)
            {
                //t - (k - t)
                int x = i - k + t;
                int y1 = j + (k - abs(k - t)), y2 = j - (k - abs(k - t)) - 1;
                if (x > n || x < 1)
                    continue;
                if (y1 > n)
                    y1 = n;
                if (y2 < 0)
                    y2 = 0;
                sum += psa[x][y1] - psa[x][y2];
            }
            ans = max(sum, ans);
        }

    }
    fout << ans << endl;
    cout << ans << endl;

}
