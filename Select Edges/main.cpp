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
vector<int> d, visited;
vector<vector<pair<int,int>>> adj;
bool com(const pair<LL, LL>& a, const pair<LL, LL>& b)
{
    return (a.first - a.second) > (b.first - b.second);
}
pair<LL,LL> solve(int n)
{
    visited[n] = true;
    vector<pair<LL,LL>> arr;
    LL sum = 0;
    for (auto& i : adj[n])
    {
        if (!visited[i.first])
        {
            auto t = solve(i.first);
            if (d[i.first] > 0)
                t.first += i.second;
            
            sum += t.second;
            arr.push_back(t);
        }
    }
    sort(arr.begin(), arr.end(), com);
    int t = d[n];
    pair<LL, LL> ans;
    ans.first = sum;
    for (int i = 0; i < t - 1 && i < arr.size(); ++i)
    {
        sum = sum - arr[i].second + arr[i].first;
        ans.first = max(ans.first,sum);
    }
    if (t != 0 && (t) <= (arr.size()))
        ans.second = max(ans.first, sum - arr[t - 1].second + arr[t - 1].first);
    else
        ans.second = max(ans.second, ans.first);
    return ans;
}
int main()
{
    int n = read();
    d.resize(n + 1), adj.resize(n + 1), visited.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        d[i] = read();
    for (int i = 0; i < n - 1; ++i)
    {
        int a = read(), b = read(), c = read();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    auto ans = solve(1);
    cout << max(ans.first, ans.second) << endl;
}
