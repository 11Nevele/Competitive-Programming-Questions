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
public:
    int target;
    int dis;
    bool operator <(const node& other) const
    {
        //return dis < other.dis  large first
        if(dis == other.dis)
            return target < other.target;
        return dis < other.dis;
    }
};
void Topological(const vector<vector<pair<int, int>>>& adj, vector<int>& arr)
{
    vector<int> in(adj.size());
    for (int i = 0; i < adj.size(); ++i)
        for (auto j : adj[i])
            ++in[j.first];
    set<node> s;
    for (int i = 1; i < in.size(); ++i)
        s.insert({ i, in[i] });
    queue<node> q;
    while (!s.empty())
    {
        int x = s.begin()->target;
        s.erase(s.begin());
        in[x] = -1;
        arr.push_back(x);
        for (auto i : adj[x])
        {
            int t = i.first;
            if (in[t] < 0)
                continue;
            auto tmp = s.lower_bound({ t,in[t] });
            s.erase(tmp);
            in[t]--;
            s.insert({ t,in[t] });
        }
    }
}
int main()
{
    int n = read(), m = read();
    vector<vector<pair<int,int>>> adj(m + 1);
    vector<pair<int, int>> cow(n + 1);
    vector<bool> v(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        int a = read(), b = read();
        cow[i] = { a,b };
        adj[a].push_back({ b,i });
    }
        
    vector<int> order;
    Topological(adj, order);
    int ans = 0;
    vector<int> seq;
    for (int i : order)
    {
        for (auto& t : adj[i])
        {
            if (!v[cow[t.second].first])
                v[cow[t.second].first] = true;
            else if (!v[cow[t.second].second])
                v[cow[t.second].second] = true;
            else
                ++ans;
            seq.push_back(t.second);
        }
    }
    write(ans), putchar('\n');
    for (int i : seq)
        write(i), putchar('\n');
    return 0;
}