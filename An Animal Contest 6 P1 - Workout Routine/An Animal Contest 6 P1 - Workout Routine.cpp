#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if (n % 2)
    {
        cout << k ;
        n--;
    }
    int base = k, base2 = 0;

    while (n > 0)
    {
        for (int i = 1; i <= (k / 2 - 1); i++)
        {
            int a = base - (i + base2);
            int b = base - a;
            cout << a << b;
            if (n == 2)
                cout << '\n';
            n -= 2;
            if (n <= 0)
                break;
        }
        base2 += k;
        base += (2 * k);
    }
}
