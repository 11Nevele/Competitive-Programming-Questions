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

LL check(const vector<LL>&arr, const LL k){
    LL cur = k, sum = cur;
    bool last = false;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (sum <= arr[i])
        {
            sum += --cur;
        }
        if (i == arr.size() - 1)
            return (k + 1) * k / 2;
        if (cur <= 0)
            break;
    }
    return arr[arr.size()-1];
}

int main()
{
    int t = read();

    while (t--)
    {
        LL n = read();
        vector<LL> arr(n + 1);
        for (int i = 1; i <= n;++i)
            arr[i] = readLL();
        if (n == 1)
        {
            write(1), putchar('\n');
            continue;
        }
        sort(arr.begin(), arr.end());
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            bool rising = check(arr, mid) < check(arr, mid + 1);
            if (rising)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        write(check(arr, l)), putchar('\n');
    }

    return 0;
}