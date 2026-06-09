#include <iostream>
using namespace std;

long long getNumberOfEndingZero(long long x)
{
    long long ans = 0;
    for (long long i = 1, j = 5; j <= x; ++i, j *= 5)
    {
        ans += x / j;
    }
    return ans;
}
int main()
{
    getNumberOfEndingZero(25);
    long long a, b;
    cin >> a >> b;
    long long l = 1, r = ((long long)1 << 62) - 1;
    long long first = 0, last = 0;
    while (l < r)
    {
        long long mid = (l + r) / 2;
        long long numberOfEndingZero = getNumberOfEndingZero(mid);
        if (numberOfEndingZero < a)
            l = mid + 1;
        else
            r = mid;
    }
    first = l;
    l = 1, r = ((long long)1 << 62) - 1;
    while (l < r)
    {
        long long mid = (l + r + 1) / 2;
        long long numberOfEndingZero = getNumberOfEndingZero(mid);
        if (numberOfEndingZero > b)
            r = mid - 1;
        else
            l = mid;
    }
    last = r;
    cout << max(last - first + 1, (long long)0) << endl;
}
