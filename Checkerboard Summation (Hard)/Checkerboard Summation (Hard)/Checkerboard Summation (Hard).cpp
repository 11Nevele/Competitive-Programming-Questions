#include <iostream>
using namespace std;
int arr[3005][3005];
int input[3005][3005];
int main()
{
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    while (true)
    {
        int type;
        cin >> type;
        if(!type)
            break;
        switch(type)
        {
        case 1:
			int x, y, z;
			cin >> x >> y >> z;
            input[x][y] = z;
            for (int i = x; i <= m; i++)
            {
                for (int j = y; j <= n; j++)
                {
                    if ((i + j) % 2)
                        arr[i][j] = input[i][j];
                    else
                        arr[i][j] = -input[i][j];
                    arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
                }
            }
            break;
        case 2:
            int a, b, c, d, temp;
            cin >> a >> b >> c >> d;
            if (((a + b) % 2))
            {
                temp = arr[c][d] + arr[a - 1][b - 1] - arr[c][b - 1] - arr[a - 1][d];
            }
            else
            {
                temp = -(arr[c][d] + arr[a - 1][b - 1] - arr[c][b - 1] - arr[a - 1][d]);
            }
            printf("%d\n", temp);
            break;
        default:
            break;
        }
    }
    return 0;
}

