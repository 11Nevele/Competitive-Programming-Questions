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



vector<vector<int>>adj(600005);
vector<bool> visited(600005);
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i : adj[x])
        {
            if (visited[i])
                continue;
            visited[i] = true;
            q.push(i);
        }
    }
}

unordered_map <LL, int> mp;
int cnt = 1;
void getID(LL t)
{
    if (!mp[t])
        mp[t] = ++cnt;
}
int main()
{
    int n = read(), k = read();
    vector < int> input(n + 1);
    
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i)
        t[i] = read(), getID(t[i]);

        
    priority_queue<LL, vector<LL>, greater<LL>> q;
    for (int i = 1; i <= k; ++i)
        q.push(t[i]);
    int cur = k + 1;//ind of next cow in line

    while (cur <= n)
    {
        LL time = q.top();
        while (cur <= n && time == q.top())
        {
            auto t1 = q.top();
            q.pop();
            LL nt = t1 + t[cur]; getID(nt);
            q.push(nt);
            adj[mp[nt]].push_back(mp[t1]);
            cur++;
            
        }
    }

    LL ans = q.top();
    bfs(mp[q.top()]);

    write(ans), putchar('\n');
    for (int i = 1; i <= k; ++i)
        if (visited[mp[t[i]]])
            putchar('1');
        else
            putchar('0');
    putchar('\n');
    return 0;
}