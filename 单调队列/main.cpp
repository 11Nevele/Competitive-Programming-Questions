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
#include <deque>
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
void DequeSolve(int n, int k, const vector<int>& arr)
{
    deque<int> ma, mi;
    vector<int> maAns(n - k + 1), miAns(n - k + 1);
    for (int i = 0; i < k; i++)
    {
            while (!ma.empty() && arr[i] > arr[ma.back()])
                ma.pop_back();
            ma.push_back(i);
            while (!mi.empty() && arr[i] < arr[mi.back()])
                mi.pop_back();
            mi.push_back(i);
    }
    maAns[0] = ma.front();
    miAns[0] = mi.front();
    for (int i = k; i < n; i++)
    {
        int t = i - k;
        
        if (t >= ma.front()) 
            ma.pop_front();
        if (t >= mi.front()) 
            mi.pop_front();
            while (!ma.empty() && arr[i] > arr[ma.back()])
                ma.pop_back();
            ma.push_back(i);
            while (!mi.empty() && arr[i] < arr[mi.back()])
                mi.pop_back();
            mi.push_back(i);
        maAns[t + 1] = ma.front();
        miAns[t + 1] = mi.front();
    }
    for (int i : miAns)
    {
        write(arr[i]);
        putchar(' ');
    }
    putchar('\n');
    for (int i : maAns)
    {
        write(arr[i]);
        putchar(' ');
    }
    putchar('\n');
}
void STSolve(int n, int k, const vector<int>& arr)
{
    int size = log2(k);
    vector<vector<int>> st(size + 1, vector<int>(n));
    vector<vector<int>> stmi(size + 1, vector<int>(n));
    st[0] = arr;
    stmi[0] = arr;
    int pow = 1;
    for (int i = 1; i <= size; i++)
    {
        
        for (int j = 0; j < n; j++)
        {
            st[i][j] = max(st[i - 1][j], st[i - 1][(j + pow) >= n ? n - 1 : (j + pow)]);
            stmi[i][j] = min(stmi[i - 1][j], stmi[i - 1][(j + pow) >= n ? n - 1 : (j + pow)]);
        }
        pow = pow << 1;
    }
    vector<int> maAns(n - k + 1), miAns(n - k + 1);
    for (int i = 0, ind = k - pow; i < n - k + 1; i++, ind++)
    {
        if (ind >= n)
            ind = n - 1;
        maAns[i] = max(st[size][i], st[size][ind]);
        miAns[i] = min(stmi[size][i], stmi[size][ind]);
    }
    for (int i : miAns)
    {
        write(i);
        putchar(' ');
    }
    putchar('\n');
    for (int i : maAns)
    {
        write(i);
        putchar(' ');
    }
    putchar('\n');
}
int main()
{
    int n = read(), k = read();
    vector<int> arr(n);
    for (int& i : arr)
        i = read();
    STSolve(n,k,arr);
}
