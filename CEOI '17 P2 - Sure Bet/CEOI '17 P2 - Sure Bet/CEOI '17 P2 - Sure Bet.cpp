
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double getProfit(vector<double>& arr1, vector<double>& arr2, int i, int numberOfBet)
{

    return min(arr1[i] - numberOfBet, arr2[numberOfBet - i] - numberOfBet);
}

double binarySearch(vector<double>& arr1, vector<double>& arr2, int numberOfBet)
{
    int l = max(0, (int)(numberOfBet - arr1.size() + 1)),
        r = min(numberOfBet, (int)(arr1.size() - 1));
    while (l < r)
    {
        int mid = (l + r) / 2;
        double c1 = getProfit(arr1, arr2, mid, numberOfBet);
        double c2 = getProfit(arr1, arr2, mid + 1, numberOfBet);
        if (c1 < c2)
            l = mid + 1;
        else
            r = mid;
    }
    return getProfit(arr1, arr2, l, numberOfBet);
}
double terarySearch(vector<double>& arr1, vector<double>& arr2, int numberOfBet)
{
    int l = max(0, (int)(numberOfBet - arr1.size() + 1)),
        r = min(numberOfBet, (int)(arr1.size() - 1));
    while (l < r)
    {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        double c1 = getProfit(arr1, arr2, m1, numberOfBet);
        double c2 = getProfit(arr1, arr2, m2, numberOfBet);
        if (c1 < c2)
            l = m1 + 1;
        else
            r = m2 - 1;
    }
    return getProfit(arr1, arr2, l, numberOfBet);
}

int main()
{
    int n;
    cin >> n;
    vector<double> arr1(n + 1), arr2(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr1[i] >> arr2[i];
    sort(arr1.begin() + 1, arr1.end(), greater<double>());
    sort(arr2.begin() + 1, arr2.end(), greater<double>());
    for (int i = 1; i < arr1.size(); ++i)
    {
        arr1[i] += arr1[i - 1];
        arr2[i] += arr2[i - 1];
    }
      
    double ans = 0;
    for (int i = 0; i <= 2 * n; ++i)
    {
        ans = max(ans, terarySearch(arr1, arr2, i));
    }
    cout << fixed << setprecision(4) << ans << endl;
}
