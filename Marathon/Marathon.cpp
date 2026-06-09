#include <iostream>
using namespace std;
int psa[500005];//前缀和数组
int arr[500005];//数组
int main()
{
    int n, q;
    int total = 0;
    cin >> n >> q; //read n and q
    for (int i = 0; i < n; i++)//input
    {
        cin >> arr[i];
        total = total + arr[i];
    }
    psa[0] = arr[0];
    for (int i = 1; i < n; i++)//生成前缀和数组
    {
        psa[i] = arr[i] + psa[i - 1];
    }
    while (q--)//handle query
    {
        int l, r;
        cin >> l >> r;
        int t = psa[r - 1] - psa[l - 2];
        cout << total - t << endl; //ouput
    }
}
