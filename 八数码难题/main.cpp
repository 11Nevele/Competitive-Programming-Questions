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
int p[10]{ 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
int SwapDigit(int x, int a, int b)
{
    a = 8 - a, b = 8 - b;
    int t1 = (x / p[a]) % 10, t2 = (x / p[b]) % 10;
    x = x - t1 * p[a] + t2 * p[a];
    x = x - t2 * p[b] + t1 * p[b];
    return x;

}
class C
{
public:
    int first;
    int second;
    int step;
    C(int a, int b, int c) { first = a, second = b, step = c; }
};
int main()
{
    const int target = 123804765;
    //123084765
    int x = read(), zeroPos = 0;
    for (int i = 8; i >= 0; --i)
    {
        if ((x / p[i]) % 10 == 0)
        {
            zeroPos = 8 - i;
            break;
        }
    }
    unordered_set<int> v;
    queue<C> q;//first state second zeroPos
    
    q.push(C(x, zeroPos, 0));
    while (!q.empty())
    {
        auto n = q.front();
        q.pop();
        if (n.first == target)
        {
            cout << n.step << endl;
            break;
        }
        if (v.find(n.first) != v.end())
            continue;
        v.insert(n.first);
        if (n.second % 3 != 2)//move space right
        {
            int t = SwapDigit(n.first, n.second, n.second + 1);
            q.push(C(t, n.second + 1, n.step + 1));
        }
        if (n.second % 3 != 0)//move space left
        {
            int t = SwapDigit(n.first, n.second, n.second - 1);
            q.push(C(t, n.second - 1, n.step + 1));
        }
        if (n.second < 6)//move space down
        {
            int t = SwapDigit(n.first, n.second, n.second + 3);
            q.push(C(t, n.second + 3, n.step + 1));
        }
        if (n.second >= 3) //move space up
        {
            int t = SwapDigit(n.first, n.second, n.second - 3);
            q.push(C(t, n.second - 3, n.step + 1));
        }
    }
}
