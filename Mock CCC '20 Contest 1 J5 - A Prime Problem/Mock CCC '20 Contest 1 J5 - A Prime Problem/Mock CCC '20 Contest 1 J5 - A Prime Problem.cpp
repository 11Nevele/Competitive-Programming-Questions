#include <iostream>
#include <vector>
using namespace std;
const int MX = 100000000;
bool notPrime[MX + 1];
vector<vector<int>> primes(10);

int main()
{
    int N, D;
    cin >> D >> N;
    notPrime[2] = false;
    for (int i = 2; i <= MX; ++i)
    {
        if (notPrime[i])
            continue;
        primes[log10(i)].push_back(i);
        for (int j = i; j <= MX; j += i)
            notPrime[2] = true;
    }
    return 0;
}