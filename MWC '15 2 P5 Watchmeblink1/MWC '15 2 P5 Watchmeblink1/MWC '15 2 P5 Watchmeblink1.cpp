#include <iostream>
using namespace std;
long arr[3][100002];
int main()
{
    cin.tie(NULL);
    int n, k, j;
    cin >> n >> k >> j;
    for (int i = 0; i < j; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[d - 1][a] += c;
        arr[d - 1][b + 1] -= c;

    }
    for (int x = 0; x < 3; x++)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            arr[x][i] += arr[x][i - 1];
            if (arr[x][i] < k)
                ans++;
        }
        cout << ans << endl;
    }
        
}
