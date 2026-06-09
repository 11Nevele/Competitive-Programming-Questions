#include <iostream>
#include<cmath>
using namespace std;
int arr[1414215];
int main()
{
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        long a, b;
        cin >> a >> b;
        int d = ceil(sqrt(pow(a,2) + pow(b,2)));
        arr[d]++;
    }
    for (int i = 1; i < 1414215; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        printf("%d\n", arr[t]);
    }
    return 0;
}
