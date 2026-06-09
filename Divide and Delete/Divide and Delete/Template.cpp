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
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline long long readLL()
{
    long long ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
vector<int> primes;
void findPrimes(int n) {
    vector<bool> isPrime(n, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            int cur = i;
            while (cur < n)
            {
                isPrime[cur] = false;
                cur += i;
            }
        }

    }

}
int GetMnFactor(int x)
{
    for (int i = 0; i < primes.size(); ++i)
    {
        while (x % primes[i] == 0)
            x /= primes[i];
        if (x == 1)
            return primes[i];
    }
    return 1;
}
int main()
{
    int n = read();
    vector<int> arr(n), f(n);

    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        arr[i] = read();
        mx = max(mx, arr[i]);

    }
    findPrimes(mx + 1);
    vector<int> mp(1000000);
    for (int i = 0; i < n; ++i)
    {
        if (mp[arr[i]] != 0)
        {
            f[i] = mp[arr[i]];
            continue;
        }
			
        if (arr[i] == 1)
            f[i] = 1;
        else
            f[i] = GetMnFactor(arr[i]);
		mp[arr[i]] = f[i];
    }
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i)
    {
        if (f[i] > 1)
            p.push_back({ i - f[i] + 2, i });
    }
    sort(p.begin(), p.end());
    LL ans = 0;
    int ind = 0;
    set<int> s;

    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && (*s.begin()) < i)
            s.erase(s.begin());
        while (ind < p.size() && p[ind].first <= i)
        {
            s.insert(p[ind].second);
            ++ind;
        }
        ans += s.empty() ? n - i : (*s.begin()) - i;

    }

    write(ans), putchar('\n');
    return 0;
}