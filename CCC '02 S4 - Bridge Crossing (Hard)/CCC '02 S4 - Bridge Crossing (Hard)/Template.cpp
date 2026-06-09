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
#include <fstream>
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

vector<vector<int>> st(20, vector<int>(1000005));
void StInit(int n, const vector<int>& arr)
{
    int size = log2(n);

    st[0] = arr;
    int pow = 1;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            st[i][j] = max(st[i - 1][j], st[i - 1][(j + pow) >= n ? n - 1 : (j + pow)]);
        }
        pow = pow << 1;
    }

}
LL GetSt(int s, int e)
{
    int dif = e - s + 1, level = log2(dif), remain = dif - pow(2, level);
    return max(st[level][s], st[level][s + remain]);
}
vector<int> arr(1000005);
vector<int> dp(1000005);
vector<int> pre(1000005);
vector<string> names(1000005);
int main()
{
    int k = read(), n =read();
    int day = ceil((double)n / k), mxDelay = day * k - n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> names[i];
        arr[i] = read();
    }
        

    
    for (int i = 1; i <= n; ++i)
    {
        dp1[i] = INT_MAX;
        for (int j = max(0, i - k); j < i; ++j)
        {
            if (dp1[j] + GetSt(j + 1, i) < dp1[i])
                dp1[i] = dp1[j] + GetSt(j + 1, i), pre1[i] = j;
        }
            
    }

    LL mn = dp[day][mxDelay], ind = mxDelay;

    vector<int> range;
    for (int i = day; i > 0; --i)
    {
        range.push_back(k * i - ind);
        ind = pre[i][ind];
    }
    cout << "Total Time: " << mn << "\n";
    for (int i = 1; i <= n; ++i)
    {
        if (!range.empty() && i > range.back())
        {
            range.pop_back();
            putchar('\n');
        }
        cout << names[i] << " ";
    }
        
    
    return 0;
}
/*
3 26
a 46
b 44
c 67 
d 45 
e 38 
f 90 
g 53 
h 39 
i 21 
j 24 
k 75 
l 54 
m 28 
n 2 
o 99 
p 26 
q 95 
r 25 
s 102 
t 76 
u 78
v 32 
w 32 
x 34 
y 16 
z 59

3 11
a 11 
b 7
c 2 
d 5
e 10
f 2
g 4
h 1
i 9
j 1
k 8

*/