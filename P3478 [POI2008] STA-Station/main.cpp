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
vector<vector<int>> adj;
vector<int> cnt;
LL init(vector<bool>& v, int x, int d)
{
    v[x] = true;
    LL sum = 0;
    for (int& i : adj[x])
        if (!v[i])
        {
            sum += init(v, i, d + 1);
            cnt[i] += 1;
            cnt[x] += cnt[i];
        }  
    return sum + d;
}
LL ans = 0, ansN = -1;
int n;
void solve(vector<bool>& v, int x, LL xSum)
{
    v[x] = true;
    for (int& i : adj[x])
    {
        if (!v[i])
        {
            LL t = xSum - cnt[i] + (n - cnt[i]);
            if (t > ans)
            {
                ans = t;
                ansN = i;
            }
            solve(v, i, t);
        }
    }
}
int main()
{
    n = read();
    adj.resize(n + 1), cnt.resize(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int a = read(), b = read();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = init(*new vector<bool>(n + 1), 1, 0);
    ansN = 1;
    cnt[1]++;
    solve(*new vector<bool>(n + 1), 1, ans);
    cout << ansN << endl;
}
