#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
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
#define MAX 1000000
int main()
{
    int n = read(), max = 0;
    vector<long long>psa(MAX + 5);
    for (int i = 0; i < n; ++i)
    {
        int t = read();
        max = std::max(max, t);
        ++psa[t];
    }
    for (int i = 1; i <= MAX; ++i)
        psa[i] += psa[i - 1];
    long long ans = 0;
    
    for (int i = max; i > 0; --i)
    {
        vector<int> cnt(1);
        for (int j = 1; (j) * i <= max; ++j)
        {
            int t = (j + 1) * i - 1;
            if (t > MAX)
                t = MAX;
            cnt.push_back(psa[t] - psa[j * i - 1]);
        }
        vector<pair<int,int>> odd;
        for (int j = 1; j < cnt.size(); ++j)
        {
            if (cnt[j] % 2)
                odd.push_back({j, cnt[j]});
        }
        if (odd.size() == 1 && odd[0].first == 1)
        {
            ans += odd[0].second;
        }
        else if (odd.size() == 2 && abs(odd[0].first - odd[1].first) == 1)
        {
            if (odd[0].first > odd[1].first)
            {
                ans += odd[0].second;
            }
            else
            {
                ans += odd[1].second;
            }
        }


    }
    cout << ans << endl;
}
