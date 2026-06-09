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


int main()
{
    string str;
    cin >> str;
    int q = read();
    vector<vector<int>>psa(3, vector<int>(str.size() + 1));
    for (int i = 1; i <= str.size(); i++)
    {
        switch (str[i-1])
        {
        case 'C':
            psa[0][i] += 1; break;
        case 'O':
            psa[1][i] += 1; break;
        case 'W':
            psa[2][i] += 1; break;
        }
        for (int j = 0; j < 3; j++)
            psa[j][i] += psa[j][i - 1];
    }
    while (q--)
    {
        int a = read(), b = read();
        vector<bool> bs(3);
        for(int i = 0; i < 3; i++)
            bs[i] = (psa[i][b] - psa[i][a - 1]) % 2;
        if ((bs[0] && !bs[1] && !bs[2]) || (!bs[0] && bs[1] && bs[2]))
            putchar('Y');
        else
            putchar('N');
        
    }
    putchar('\n');
}
