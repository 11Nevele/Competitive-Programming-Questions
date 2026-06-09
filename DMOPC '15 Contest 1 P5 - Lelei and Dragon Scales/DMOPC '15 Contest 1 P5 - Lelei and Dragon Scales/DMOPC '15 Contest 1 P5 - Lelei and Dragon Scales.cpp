#include <iostream>
#include<cmath>
using namespace std;
int arr[250][250];
int main()
{
    int h, w, n, ans = 0;
    cin >> w >> h >> n;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            cin >> arr[i][j];
            arr[i][j] += (arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1]);
        }
    for (int d = 1; d <= n; d++)
    {
        int x = d < h ? d : h, y = n / d;
        y = y < w ? y : w;
        for (int i = x; i <= h; i++)
        {
            for (int j = y; j <= w; j++)
            {
                int temp = arr[i][j] - arr[i - x][j] - arr[i][j - y] + arr[i - x][j - y];
                ans = ans > temp ? ans : temp;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
