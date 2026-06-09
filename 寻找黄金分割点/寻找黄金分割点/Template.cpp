#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100005], k, l, r, mid, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    l = 1;
    r = n;
    ans = n + 1;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (a[mid] <= k)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << endl;
    if (k - a[l] > a[l + 1] - k)
    {
        cout << a[l + 1];
    }
    else
    {
        cout << a[l];
    }
    return 0;
}