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
class node
{
public :
    int c;
    int l;
    int id;
    bool operator < (const node& other)const
    {
        return l < other.l;
    }
};

const int MAXM = 10005;
int main()
{
    int n = read(), v = read();
    vector<int> coins(n + 1), ans(v);
    for (int i = 1; i <= n; ++i)
        coins[i] = read();
    vector<node> quest(v);
    int mx = 0;
    for (int i = 0; i < v; ++i)
    {
        quest[i] = { read(), read(), i };
        mx = max(mx, quest[i].c);
    }
        
    sort(quest.begin(), quest.end());

    vector<int> dp1(MAXM, MAXM);
    dp1[0] = 0;
    int ind = 0;
    for (int i = 1; i <= n; ++i)
    {
            
        for (int j = 0; j <= mx; ++j)
        {
            if (j >= coins[i] && dp1[j - coins[i]] + 1 < dp1[j])
                dp1[j] = dp1[j - coins[i]] + 1;
            else
                dp1[j] = dp1[j];
        }
        while (ind < v && quest[ind].l == i)
        {
            ans[quest[ind].id] = dp1[quest[ind].c];
            ++ind;
        }
    }
    for (int i : ans)
    {
        write(i != MAXM ? i : -1);
        putchar('\n');
    }
    return 0;
}