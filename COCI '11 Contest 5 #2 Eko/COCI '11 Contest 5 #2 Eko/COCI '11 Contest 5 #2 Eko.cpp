#include <iostream>
#include <vector>
using namespace std;
long long getNumberCut(vector<int>& arr, int x)
{
    long long ans = 0;
    for (int i : arr)
        ans += max(0, i - x);
    return ans;
}
int main()
{
    long long n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int l = 0, r = 1000000;
    while (l < r)
    {
        int mid = (l + r+1) / 2;
        long long numberCut = getNumberCut(arr, mid);
        if (numberCut >= m) //satisfy condition
            l = mid;
        else //does not satisfy condition
            r = mid - 1;
    }
    cout << l << endl;
}
