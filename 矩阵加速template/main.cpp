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

using matrix = vector<vector<LL>>;
const LL mod = 1e9 + 7;
matrix MultiplyMatrix(const matrix& a, const matrix& b)
{
    if (a.empty() || b.empty() || a[0].size() != b.size())
    {
        cout << "error\n";
        return matrix();
    }
    int r = a.size(), c = b[0].size(), x = b.size();
    matrix result(r, vector<LL>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            for (int k = 0; k < x; ++k)
                result[i][j] =  (result[i][j] + a[i][k] * b[k][j]) % mod;
    return result;
}

void addTo(matrix& a, const matrix& b)
{
    if (a.size() != b.size() || a[0].size() != b[0].size())
    {
        cout << "error while adding\n";
        return;
    }
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a[0].size(); ++j)
            a[i][j] += b[i][j];
}
matrix qPower(matrix a, int n)
{
    matrix sum = a;
    --n;
    while (n > 0)
    {
        if (n & 1)
            sum = MultiplyMatrix(a, sum);
        a = MultiplyMatrix(a, a);
        n = n >> 1;
    }
    return sum;
}

int main()
{
    int t = read();
    while (t--)
    {
        int n = read();
        matrix v1{ {1}, {1}, {1} };
        matrix v2{
            {0,1,0},
            {0,0,1},
            {1,0,1}
        };
        v2 = qPower(v2, n - 1);
        v1 = MultiplyMatrix(v2, v1);
        write(v1[0][0]), putchar('\n');
    }
    

}
/*
0 1 0
0 0 1
1 0 1

1 1 1
1 1 2
2 1 3
*/