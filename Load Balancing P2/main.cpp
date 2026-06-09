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
int lowbit(int n) { return n & -n; }
void Add(vector<int>& arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int Sum(vector<int>& arr, int target)
{
    int ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
vector<int> bit(1000005), xpsa(1000005), ypsa(1000005);
vector<vector<int>> coordy(1000005);
int n;
int get(int x, int y, int a)
{

    int bl = Sum(bit, x) + a, br = ypsa[y] - bl;
    int ul = xpsa[x] - bl, ur = n - bl - br - ul;
    return max(max(bl, br), max(ul, ur));
}
int main()
{
    n = read();
    vector<pair<int, int>> coords(n);
    for (auto& i : coords)
    {
        i.first = read(), i.second = read();
        coordy[i.second].push_back(i.first);
        xpsa[i.first]++;
        ypsa[i.second]++;
    }
    for (int i = 1; i <= 1000000; ++i)
        xpsa[i] += xpsa[i - 1], ypsa[i] += ypsa[i - 1];

    sort(coords.begin(), coords.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        }
    );
    for (int i = 1; i <= 1000000; ++i)
        sort(coordy[i].begin(), coordy[i].end());

    int ans = INT_MAX;
    for (int y =1;y<=1000000;++y)
    {
        for (int i = 0; i < coordy[y].size(); ++i)
        {
            int x = coordy[y][i];
            int ul = get(x - 1, y + 1, i), ur = get(x + 1, y + 1, i + 1);
            int bl = get(x - 1, y - 1, 0), br = get(x + 1, y - 1, 0);
            ans = min(ans, min(min(ur, ul), min(bl, br)));
        }
        for (int i : coordy[y])
            Add(bit, i, 1);
    }
    write(ans), putchar('\n');
}