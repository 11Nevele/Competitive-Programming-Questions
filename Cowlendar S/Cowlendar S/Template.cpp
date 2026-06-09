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

bool check(const vector<LL>& arr, LL l)
{
    int cnt = 0;
    unordered_map<LL, bool> mp;
    for (LL i : arr)
    {
        LL mod = i % l;
        if (!mp[mod])
        {
            mp[mod] = true;
            ++cnt;
            if (cnt > 3)
                return false;
        }
    }
    return true;
}

int main()
{
    int n = read();
    vector<LL> arr(n);
    
    for (LL& i : arr)
        i = readLL();
    sort(arr.begin(), arr.end());

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    LL mx = arr[0] / 4, sum = 0;
    if (arr.size() < 4)
    {
        write((1 + mx) * mx / 2), putchar('\n');
        return 0;
    }
    unordered_map<LL, bool> mp;
    for(int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            LL num = abs(arr[i] - arr[j]);

            for (LL l = 1; l * l <= num && l <= mx; ++l)
            {
                if (num % l) continue;
                
                sum += !mp[l] * l * check(arr, l);
                mp[l] = true;
                sum += !mp[num / l] * (num / l)* check(arr, num / l) * (num / l <= mx);
                mp[num / l] = true;
            }
        }

    write(sum), putchar('\n');

    return 0;
}