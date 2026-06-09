#include <iostream>
#include <algorithm>
using namespace std;
/*
int arr[5000000];
int k, n;
int binarySearch(int target)
{
    int min = 0, max = k - 1;
    while (max > min)
    {
        int mid = (max + min + 1) / 2;
        if (arr[mid] > target)
        {
            max = mid - 1;
        }
        else
        {
            min = mid;
        }
    }
    return  min;
}
int main()
{
    
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + k);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < arr[0])
            cout << temp << endl;
        else
        cout << temp - binarySearch(temp) - 1 << endl;
    }
    return 0;

}*/
#include <iostream>
#define MAX 1000001
using namespace std;

int arr[MAX];

int main()
{
    fill_n(arr, MAX, 1);
    int n, k, ans = 0;;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] = 0;
    }
    arr[0] = 0;
    for (int i = 1; i < MAX; i++)
    {
        arr[i] += arr[i - 1];
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        cout << arr[n] << endl;
    }
    return 0;
}
