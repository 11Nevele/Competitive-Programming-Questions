#include <iostream>
using namespace std;
int arr[500001];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << arr[n] - arr[b] + arr[a - 1] << endl;
    }
    return 0;
}
