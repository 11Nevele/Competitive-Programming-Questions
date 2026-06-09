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

int main()
{
    int n = read(), mn = INT_MAX;
    vector<int> arr(n * 2), l(n), r(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = read();
        mn = min(mn, arr[i]);
        arr[i + n] = arr[i];
    }

    deque<int> q;
    for (int i = 0; i < n; ++i)
    {
        while (!q.empty() && arr[q.back()] >= arr[i])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = n; i < 2*n; ++i)
    {
        if(!q.empty() && q.front() <= i - n)
            q.pop_front();
        while (!q.empty() && arr[q.back()] >= arr[i])
            q.pop_back();
        if (q.empty())
            l[i - n] = i - n;
        else
            l[i - n] = q.back() >= n ? q.back() - n : q.back();
        q.push_back(i);
    }
    q.clear();
    for (int i = 2 * n - 1; i >= n; --i)
    {
        while (!q.empty() && arr[q.back()] > arr[i])
            q.pop_back();
        q.push_back(i);
    }
    for (int i = n-1; i >= 0; --i)
    {
        if (!q.empty() && q.front() >= i + n)
            q.pop_front();
        while (!q.empty() && arr[q.back()] > arr[i])
            q.pop_back();
        if (q.empty())
            r[i] = i;
        else
            r[i] = q.back() >= n ? q.back() - n : q.back();
        q.push_back(i);
    }

    vector<LL> psa(2 * n);
    for (int i = 0; i < n; ++i)
    {
        psa[0] += arr[i];
        int e1 = l[i] > i ? n - l[i] + i : i - l[i];
        int e2 = r[i] < i ? n - i + r[i] : r[i] - i;
        if (e1)
            psa[e1] -= arr[i];
        if (e2)
            psa[e2] -= arr[i];
        if (e1 && e2)
           psa[e1 + e2] += arr[i];
    }
    for (int t = 0; t < 2; ++t)
        for (int i = 1; i <= n; ++i)
            psa[i] += psa[i - 1];
    for (int i = 1; i < n; ++i)
        write(psa[i]), putchar('\n');
    write((LL)mn * n), putchar('\n');
    return 0;

}