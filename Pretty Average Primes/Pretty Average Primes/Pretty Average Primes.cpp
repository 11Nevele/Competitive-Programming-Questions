#include <iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
    if (!(n % 2))
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (!(n % i))
            return false;
    }
    return true;
}
void func(int n)
{
    for (int a = 2; a <= n; a++)
    {
        int b = 2 * n - a;
        if (isPrime(a) && isPrime(b))
        {
            cout << a << " " << b << endl;
            break;
        }
    }
}
int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        func(n);
    }
}
