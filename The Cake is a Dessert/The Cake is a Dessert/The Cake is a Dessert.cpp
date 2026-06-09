#include <iostream>
using namespace std;
long arr[5005][5005];

void solve1()
{
    cin.tie(NULL);
    int m, n, q;
    cin >> n >> m >> q;

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[y1][x1] += 1;
        arr[y2 + 1][x2 + 1] += 1;
        arr[y2 + 1][x1] -= 1;
        arr[y1][x2 + 1] -= 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = arr[i][j] + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << arr[d][c] + arr[b - 1][a - 1] - arr[d][a - 1] - arr[b - 1][c] << "\n";
    }
}
long long psa[5005][5005];
void solve2()
{
    cin.tie(0);
    std::cout.sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        psa[x1][y1] += 1;
        psa[x1][y2 + 1] -= 1;
        psa[x2 + 1][y1] -= 1;
        psa[x2 + 1][y2 + 1] += 1;
    }

    for (int i = 1; i <= 5000; ++i)
        for (int j = 1; j <= 5000; ++j)
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
    for (int i = 1; i <= 5000; ++i)
        for (int j = 1; j <= 5000; ++j)
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psa[x2][y2] - psa[x1 - 1][y2] - psa[x2][y1 - 1] + psa[x1 - 1][y1 - 1] << "\n";

    }
}
int main()
{
    solve2();
    return 0;
}
