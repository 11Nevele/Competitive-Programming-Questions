#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;


long long MOD = 1e9 + 7;
long long fac[2005], ifac[2005];
long long powm(long long a, long long b, long long mod)
{
    long long res = 1 % mod;
    while (b)
    {
        if (b & 1)res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
long long inv(long long a, long long mod)
{
	return powm(a, mod - 2, mod);
}

long long C(long long n, long long m, long long mod)
{
	return (fac[n] * ((ifac[m] * ifac[n - m]) % mod)) % mod;
}
int main()
{
    for (int i = 1; i <= 2000; ++i)
    {
        fac[i] = (fac[i - 1] * i) % MOD;
		ifac[i] = inv(fac[i], MOD);
    }
		
    

    int n, m;
    cin >> n;
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> m;
    for (int i = 0; i < n; ++i)
    {
        long long ans = arr[i];
        for (int j = 0; j < i; ++j)
        {
            ans += C(m - 2, )
        }
    }
}