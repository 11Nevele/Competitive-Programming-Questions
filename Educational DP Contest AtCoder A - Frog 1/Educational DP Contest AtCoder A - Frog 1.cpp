#include <iostream>
using namespace std;
int arr[100005];
long long ans[100005];
int main()
{
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ans[0] = 0;
    ans[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < n; i++)
    {
        int a = ans[i - 1] + abs(arr[i] - arr[i - 1]), b = ans[i - 2] + abs(arr[i] - arr[i - 2]);
        ans[i] = a < b ? a : b;
    }
    cout << ans[n - 1] << endl;
    return 0;
}
