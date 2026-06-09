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
bool check(vector<int> & arr, int mnInd, int n)
{
    for (int i = mnInd + 1; i < mnInd + n; ++i)
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    return true;
}
int main()
{
    int n = read(), q = read();
    vector<int> arr(n * 2 + 5);
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = read();
    }
    arr[0] = arr[n];
    set<int> s;
    for (int i = 1; i <= n; ++i)
        if (arr[i] < arr[i - 1])
            s.insert(i);
    while (q--)
    {
        int a = read(), b = read();
        if (a == n)
        {
            arr[a] = b, arr[0] = b;
            if (arr[a] < arr[a - 1])
            {
                s.insert(a);
            }
            else if (s.find(a) != s.end())
            {
                s.erase(a);
            }
            if (arr[1] < arr[0])
            {
                s.insert(1);
            }
            else if (s.find(1) != s.end())
            {
                s.erase(1);
            }
        }
        else
        {
            arr[a] = b;
            if (arr[a] < arr[a - 1])
            {
                s.insert(a);
            }
            else if (s.find(a) != s.end())
            {
                s.erase(a);
            }
            if (arr[a + 1] < arr[a])
            {
                    s.insert(a + 1);
            }
            else if (s.find(a + 1) != s.end())
            {
                s.erase(a + 1);
            }
        }
        
        if (s.size() == 0)
        {
            write(0);
        }
        else if (s.size() == 1)
        {
            int t = *s.begin();
            write(min(t - 1, n - t + 1));
        }
        else
            write(-1);
        putchar('\n');
    }

        

    return 0;
}