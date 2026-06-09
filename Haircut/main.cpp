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
#include <fstream>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807
inline int read() {
    int t;
    ifstream fin("haircut.in");
    fin >> t;
    return t;
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
    ofstream fout("haircut.out");
    fout << x << endl;
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void write(long long x)
{
    ofstream fout("haircut.out");
    fout << x << endl;
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int lowbit(int x) { return x & -x; }
LL SumTo(vector<long long> &arr, int target)
{
    long long ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
void Add(vector<LL>& arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int main()
{
    ifstream fin("haircut.in");
    ofstream fout("haircut.out");
    int n;
    fin >> n;
    vector<long long>ta(n + 2),  ans(n + 2);
    
    for (int i = 0; i < n; ++i)
    {
        int t;
        fin >> t;
        ans[t + 1] += (i - SumTo(ta, t + 1));
        Add(ta, t + 1, 1);
    }
    long long ansSum = 0;
    for (int i = 0; i < n; ++i)
    {
        ansSum += ans[i];
        fout << ansSum << endl;
    }
}
