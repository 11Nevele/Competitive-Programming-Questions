#include<algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
bool xCom(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}
bool yCom(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}
int f(const vector<vector<int>>& psa, int x1, int y1, int x2, int y2)
{
    return psa[x2][y2] - psa[x1 - 1][y2] - psa[x2][y1 - 1] + psa[x1 - 1][y1 - 1];
}
int main()
{
    int n = read();
    vector<pair<int, int>> arr(n);
    vector<vector<int>> psa(n + 1, vector<int>(n + 1, 0));
    for (auto& i : arr)
        i.first = read(), i.second = read();
    std::sort(arr.begin(), arr.end(), xCom);
    for (int i = 0; i < n; i++)
        arr[i].first = i + 1;
    std::sort(arr.begin(), arr.end(), yCom);
    for (int i = 0; i < n; i++)
        arr[i].second = i + 1;
    for (int i = 0; i < n; i++)
        psa[arr[i].first][arr[i].second] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int maxX = max(arr[i].first, arr[j].first);
            int minX = min(arr[i].first, arr[j].first);
            ans += f(psa, 1, i + 1, minX, j + 1) * f(psa, maxX, i + 1, n, j + 1);
        }
    }
    cout << ans + 1 << endl;
}