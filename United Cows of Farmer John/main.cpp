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
class HJT
{
public:
    vector<int> left, right, roots;
    vector<size_t> value;
    int maxSize;
    int originalSize;
    int size = 0;
    HJT(const vector<int> &arr)
    {
        originalSize = arr.size() - 1;
        maxSize = arr.size() * (1 << 5) + 10;
        left.resize(maxSize);
        right.resize(maxSize);
        value.resize(maxSize);
        roots.push_back(0);
        Build(arr, 0, arr.size() - 1);
    }
    HJT(int newSize)
    {
        originalSize = newSize;
        maxSize = newSize * (1 << 5) + 10;
        left.resize(maxSize);
        right.resize(maxSize);
        value.resize(maxSize);
        roots.push_back(0);
        EmptyBuild(0, newSize);
    }
    int EmptyBuild(int l, int r)
    {
        int n = size++;
        if (l == r) return n;
        int mid = l + r >> 1;
        left[n] = EmptyBuild(l, mid);
        right[n] = EmptyBuild(mid + 1, r);
        return n;
    }
    int Build(const vector<int>& arr, int l, int r)
    {
        int n = size++;
        if (l == r)
        {
            value[n] = arr[l];
            return n;
        }      
        int mid = (l + r) >> 1;
        left[n] = Build(arr, l, mid);
        right[n] = Build(arr, mid + 1, r);
        value[n] = value[left[n]] + value[right[n]];
        return n;
    }
    void Update(int target, int v)
    {
        roots.push_back(size);
        Change(target, v, roots[roots.size() - 2], 0, originalSize);
    }
    int Change(int target, int v, int preRoot, int l, int r)
    {
        int n = size++;
        int mid = (l + r) >> 1;
        value[n] = value[preRoot] + v;
        if (l == r)
            return n;
        if (target <= mid)
        {
            left[n] = Change(target, v, left[preRoot], l, mid);
            right[n] = right[preRoot];
        }
        else
        {
            right[n] = Change(target, v, right[preRoot], mid + 1, r);
            left[n] = left[preRoot];
        }
        return n;
    }
    long long Query(int rootIndex, int l, int r)
    {
        return Find(roots[rootIndex], l, r, 0, originalSize);
    }
    long long Find(int n, int targetL, int targetR, int l, int r)
    {
        if (l >= targetL && r <= targetR)
            return value[n];
        if (r < targetL || l > targetR)
            return 0;
        int mid = (l + r) >> 1;
        
        return Find(left[n], targetL, targetR, l, mid) +
            Find(right[n], targetL, targetR, mid + 1, r);


    }
};
void Solve1(int n, const vector<int> &pre, const vector<int> &next)
{
    HJT hjt(n + 1);
    long long ans = 0;
    hjt.Update(next[0], 1);
    for (int i = 1; i < n; i++)
    {
        int preInd = pre[i];
        ans += hjt.Query(i, i + 1, n + 1) - hjt.Query(preInd + 1, i + 1, n + 1);
        hjt.Update(next[i], 1);
    }
    cout << ans << endl;
}
class BIT
{
public:
    vector<long long> arr;
    int size;
    BIT(int s)
    {
        size = s;
        arr.resize(size);
    }
    int lowbit(int x) { return x & -x; }
    void Change(int target, int value)
    {
        while (target < size)
        {
            arr[target] += value;
            target += lowbit(target);
        }
    }
    long long Sum(int target)
    {
        long long sum = 0;
        while (target > 0)
        {
            sum += arr[target];
            target -= lowbit(target);
        }
        return sum;
    }
};

void Solve2(int n, const vector<int>& pre, const vector<int>& next)
{
    BIT bit(n + 2);
    long long ans = 0;
    vector<int> temp(n);
    
    for (int i = 0; i < n; ++i)
    {
        temp[i] = bit.Sum(n + 1) - bit.Sum(next[i]);
        ans += bit.Sum(n + 1) - bit.Sum(i) - (pre[i] < 0 ? 0 : temp[pre[i]]);
        bit.Change(next[i], 1);
    }
    cout << ans << endl;
}
int main()
{
    int n = read();
    vector<int> arr(n), v(200005, -1), pre(n, -1), next(n, n +1);
    for (int& i : arr)
    {
        i = read();
    }     
    for (int i = 0; i < n; i++)
    {
        if (v[arr[i]] != -1)
        {
            next[v[arr[i]]] = i;
            pre[i] = v[arr[i]];
        }
        v[arr[i]] = i;
    }
    Solve2(n, pre, next);
    return 0;
}
