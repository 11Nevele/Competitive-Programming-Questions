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

class node
{
public:
    int l;
    int r;
    int k;
    int ind;
    bool operator < (const node& other) const
    {
        return k > other.k;
    }
};
bool comLength(const node& a, const node& b)
{
    return (a.r - a.l) < (b.r - b.l);
}

unordered_map<int, int> mp;
vector<int> bitL(800005), bitR(800005);
int lowbit(int n) { return n & -n; }
void ChangeL(vector<int>& arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int SumL(vector<int>& arr, int target)
{
    int ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}

void ChangeR(vector<int>& arr, int target, int value)
{
    while (target > 0)
    {
        arr[target] += value;
        target -= lowbit(target);
    }
}
int SumR(vector<int>& arr, int target)
{
    int ans = 0;
    while (target < arr.size())
    {
        ans += arr[target];
        target += lowbit(target);
    }
    return ans;
}
int main()
{
    int n = read();
    vector<node> arr(n), arr2(n);
    vector<int> ans(n), coords;
    for (int i = 0; i < n; ++i)
    {
        arr[i] = { read(), read(), read(), i };
        coords.push_back(arr[i].l);
        coords.push_back(arr[i].r);
        coords.push_back(arr[i].l + arr[i].k - 1);
        coords.push_back(arr[i].r - arr[i].k + 1);
    }
    sort(coords.begin(), coords.end());
    mp[coords[0]] = 1;
    int cnt = 1;
    for (int i = 1; i < coords.size(); ++i)
        if(coords[i] != coords[i - 1])
        mp[coords[i]] = ++cnt;



    arr2 = arr;
    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end(), comLength);
    
    for (auto& i : arr)
    {
        while (!arr2.empty() && (arr2.back().r - arr2.back().l) >= i.k)
        {
            ChangeL(bitL, mp[arr2.back().r], 1);
            ChangeR(bitR, mp[arr2.back().l], 1);
            arr2.pop_back();
        }
        if (i.r - i.l + 1 < i.k)
            continue;

        ans[i.ind] = n - arr2.size();
        ans[i.ind] -= (SumL(bitL, mp[i.l + i.k - 1])
            + SumR(bitR, mp[i.r - i.k + 1]));
        --ans[i.ind];
    }
    for (int i = 0; i < n; ++i)
        write(ans[i]), putchar('\n');
    return 0;
}