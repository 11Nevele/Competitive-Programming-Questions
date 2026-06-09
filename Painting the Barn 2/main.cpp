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

int MaxSubMatrix(vector<vector<int>>& p, int n)
{
    int ans = 0;
    vector<vector<int>> psa(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            psa[i][j] = (p[i][j] + psa[i - 1][j]);
    int x1 = 1, y1 = 1, x2 = 1, y2 = 0, ty1 = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            vector<int> v(n + 1);
            for (int a = 1; a <= n; a++)
            {
                v[a] = psa[j][a] - psa[i - 1][a];
            }
            int ma = 0, ms = 0, s = 0, e = 0, st = 0;
            for (int t = 1; t <= n; t++)
            {
                ms += v[t];
                if (ms <= 0)
                {
                    ms = 0;
                    st = t + 1;
                }
                    
                if (ms > ma)
                {
                    ma = ms;
                    s = st, e = t;
                }
            }
            if (ma > ans)
            {
                ans = ma;
                x1 = i, x2 = j, y1 = s, y2 = e;
            }
        }
    }
    if (ans > 0)
    {
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                p[i][j] = 0;
    }
    return ans;
}
int main()
{
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    int n, k;
    fin >> n >> k;
    vector<vector<int>> psa(202, vector<int>(202));
    for(int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;
        x1++, x2++, y1++, y2++;
        psa[x1][y1]++;
        psa[x1][y2]--;
        psa[x2][y1]--;
        psa[x2 ][y2]++;
    }
    int ans = 0;
    for (int i = 1; i <= 201; i++)
        for (int j = 1; j <= 201; j++)
        {
            psa[i][j] += (psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1]);
        }
    for (int i = 1; i <= 201; i++)
        for (int j = 1; j <= 201; j++)
        {
            if (psa[i][j] == k)
            {
                ans++;
                psa[i][j] = -1;
            }
            else if (psa[i][j] == k - 1)
            {
                psa[i][j] = 1;
            }
            else
                psa[i][j] = 0;
        }
    int a = MaxSubMatrix(psa, 201);
    ans += a;
    if (a > 0)
        a = MaxSubMatrix(psa, 201);
    ans += a;
    cout << ans << endl;
    fout << ans << endl;

    
}
