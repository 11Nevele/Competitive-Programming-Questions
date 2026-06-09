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
int a, b;
int dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool>& v, int n, int &head, bool &bb)
{
    v[n] = true;
    int ans = 1;
    for (const int i : adj[n])
    {
        if (!v[i])
            ans += dfs(adj, v, i, head, bb);
        if (i == n)
            bb = true;
    }
    if (adj[n].size() == 1)
        head = n;
    return ans;
}
void Next(unordered_map<int, vector<int>>& adj, unordered_map<int, int>& map, int n);
void Set(unordered_map<int, vector<int>>& adj, unordered_map<int, int>& map, int n)
{
    int next;
    if (adj[n].size() == 1)
        next = adj[n][0];
    else if(adj[n][0] == 0 && adj[n][1] == 0)
        next = adj[n][0] == n ? adj[n][1] : adj[n][0];
    else
        next = map[adj[n][0]] == 0 ? adj[n][0] : adj[n][1];
    if (n + next == a)
    {
        map[n] = -1;
        map[next] = -1;
    }
    else
    {
        map[n] = 1;
        map[next] = 1;
    }
    if (n == next)
        return;
    Next(adj, map, next);
}
void Next(unordered_map<int, vector<int>>& adj, unordered_map<int, int>& map, int n)
{
    if (adj[n].size() == 1 || adj[n][0] == n || adj[n][1] == n)
        return;
    int next = map[adj[n][0]] == 0 ? adj[n][0] : adj[n][1];
    Set(adj, map, next);
}
int main()
{
    int n = read();
    a = read(), b = read();
    unordered_map<int, int>map;
    unordered_map<int, bool> v;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = read();
        map[arr[i]] = 0;
        v[arr[i]] = false;
    }
    unordered_map<int, vector<int>> adj;
    if (a == b)
        b = -1;
    for (int i : arr)
    {
        if (map.find(a - i) != map.end())
        {
            adj[i].push_back(a - i);
        }
        if (map.find(b - i) != map.end())
        {
            adj[i].push_back(b - i);
        }
    }
    for (int i : arr)
    {
        if (!v[i])
        {
            if (adj.find(i) == adj.end())
            {
                cout << "NO\n";
                return 0;
            }
            int head = -1;
            bool bb = false;
            int temp = dfs(adj, v, i, head, bb);
            if (temp % 2 == 0 || bb)
            {
                Set(adj, map, head);
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i : arr)
    {
        if (map[i] < 0)
            putchar('0');
        else
            putchar('1');
        putchar(' ');
    }
    putchar('\n');
}
