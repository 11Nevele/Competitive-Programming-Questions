#include <iostream>
using namespace std;
int arr[3005][3005];
int main()
{
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    int a = 10, b, c, d;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0)
            break;
        arr[a][b] = c;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) % 2)
                arr[i][j] = arr[i][j];
            else
                arr[i][j] = -arr[i][j];
            arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    //arr odd
    //arr2 even
    while (true)
    {
        cin >> a >> b >> c >> d;
        if (a == 0)
            break;
        int temp;
        if (((a + b) % 2))
        {
            temp = arr[c][d] + arr[a - 1][b - 1] - arr[c][b - 1] - arr[a - 1][d];
        }
        else
        {
            temp = -(arr[c][d] + arr[a - 1][b - 1] - arr[c][b - 1] - arr[a - 1][d]);
        }
        printf("%d\n", temp);
    }
    return 0;
}

