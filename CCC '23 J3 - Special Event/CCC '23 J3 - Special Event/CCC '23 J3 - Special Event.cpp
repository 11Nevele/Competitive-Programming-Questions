#include <iostream>
using namespace std;
long arr[5];
int main()
{
    int n = 0, max = 0;
    cin >> n;
    
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            char t;
            cin >> t;
            if (t == 'Y')
                arr[i]++;
            max = max > arr[i] ? max : arr[i];
        }
    }
    bool f = true;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == max)
        {
            if (f)
            {
                cout << i + 1;
                f = false;
            }
            else
                cout << ',' << i + 1;
        }
    }
}
