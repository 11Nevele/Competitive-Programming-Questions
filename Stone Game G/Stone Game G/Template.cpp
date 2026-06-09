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
    int n = read();
    vector<int> arr(n), psa(2000005);
    for (int& i : arr)
        i = read(), psa[i]++;
    for (int i = 1; i <= 2000000; ++i)
        psa[i] += psa[i - 1];
    vector<int> x(1000005);
    LL sum = 0;
    for (int i = 1; i <= 1000000; ++i)
    {
        int mx = 1000000 / i;
        int oddCnt = 0, adjOdd = -1;
        for (int j = 1; j <= mx; ++j)
        {
            x[j] = psa[(j + 1) * i - 1] - psa[j * i - 1];
            if (x[j] & 1)
            {
                ++oddCnt;
                if (x[j - 1] & 1)
                    adjOdd = j;
            }
                

        }

        if (oddCnt == 1)
        {
            if (x[1] & 1)
                sum += x[1];
        }
        else if(oddCnt == 2)
        {
            if (adjOdd != -1)
                sum += x[adjOdd];
        }
            
    }
    write(sum), putchar('\n');
    return 0;
}