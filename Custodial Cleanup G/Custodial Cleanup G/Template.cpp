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
vector<int> c, s, f;
vector<vector<int>> adj;
vector<bool> v1, v2;
void check1()
{
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> keys;
    queue<int> q;
    vector<bool> v(c.size());
    q.push(1);
    v[1] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        v1[x] = true;
        if (keys.find(s[x]) == keys.end())
        {
            for (int t : mp[s[x]])
            {
                q.push(t);
            }
        }
        keys[s[x]]++;
        for (int i : adj[x])
        {
            if (v[i])
                continue;
            v[i] = true;
            if (keys.find(c[i]) == keys.end())
            {
                mp[c[i]].push_back(i);
                continue;
            }
            q.push(i);
        }
    }
}


void check2()
{
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> keys;
    queue<int> q;
    vector<bool> v(c.size());
    q.push(1);
    v[1] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        v2[x] = true;
        if (keys.find(f[x]) == keys.end())
        {
            for (int t : mp[f[x]])
            {
                q.push(t);
            }
        }
        keys[f[x]]++;
        for (int i : adj[x])
        {
            if (v[i] || !v1[i])
                continue;
            v[i] = true;
            
            if (keys.find(c[i]) == keys.end() && c[i] != f[i] )
            {
                mp[c[i]].push_back(i);
                continue;
            }
            q.push(i);
        }
    }
}

int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), m = read();
        c.clear(), s.clear(), f.clear();
        adj.clear();
        v1.clear(), v2.clear();
        v1.resize(n + 1), v2.resize(n + 1);
        adj.resize(n + 1);
        c.resize(n + 1), f.resize(n + 1), s.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            c[i] = read();
        for (int i = 1; i <= n; ++i)
            s[i] = read();
        for (int i = 1; i <= n; ++i)
            f[i] = read();
        
        while (m--)
        {
            int a = read(), b = read();
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        check1();
        check2();
        bool t = true;
        for (int i = 1; i <= n; ++i)
        {
            if ((!v1[i] || !v2[i]) && s[i] != f[i])
            {
                t = false;
            }

        }

        if (t)
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}