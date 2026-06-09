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
LL c[200005], r[200005], d[200005], s[200005];
int layover[200005], ind[200005];
vector<int> adj[200005];
vector<LL> ans(200005, -1);
class Com
{
public:
    bool operator ()(int a,  int b) const
    {
        return (s[a]) < (s[b]);
    }
};


int main()
{
    int n, m;
    n = read(), m = read();
    
    for (int i = 0; i < m; ++i)
    {
        c[i] = read(), r[i] = read(), d[i] = read(), s[i] = read();
        adj[c[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end(), [](int a, int b) {return r[a] > r[b]; });
    for (int i = 1; i <= n; ++i)
        layover[i] = read();
    queue<int> q;
    ans[1] = 0;
    for (int& i : adj[1])
        q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (ans[d[x]] == -1 || ans[d[x]] > s[x])
            ans[d[x]] = s[x];
        else
            continue;
        for (int j = ind[d[x]]; j < adj[d[x]].size(); ++j)
        {
            int i = adj[d[x]][j];
            if (r[i] >= s[x] + layover[d[x]])
            {
                q.push(i);
            }
            else
            {
                ind[d[x]] = j;
                break;
            } 
        }
    }
    for (int i = 1; i <= n; ++i)
        write(ans[i]), putchar('\n');
}
