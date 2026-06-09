#include <iostream>
using namespace std;
int da[10000001];
int psa[10000001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)// input task
    {
        int l, r;
        cin >> l >> r;
        da[l] += 1;
        da[r] -= 1;
    }
    int max = 0;
    for (int i = 1; i < 10000000; i++)
    {
        psa[i] = psa[i - 1] + da[i];
        if (psa[i] > max)
            max = psa[i];

    }
    cout << max << endl;
}
