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
vector<int> arr(200005), indOf(200005);


//first demension number, store position
vector<int> adj[2][200005];
int parent[2][200005], ind[2][200005];


map<int, bool> mp;
int ans = 0;
void Modify(int ind, bool isHigh, int isAdd)
{
    auto post = mp.upper_bound(ind), pre = mp.lower_bound(ind);
    bool noPreHigh = true;
    if (pre != mp.begin())
    {
        pre--;
        if ((*pre).second == true)
            noPreHigh = false;
    }
    if (isHigh)
    {      
        if (post != mp.end() && (*post).second == false && noPreHigh)
            ans += isAdd;
    }
    else
    {
        if (!noPreHigh && (post == mp.end() || (*post).second == true))
            ans += isAdd;
    }
    if (isAdd > 0)
        mp[ind] = isHigh;
    else
        mp.erase(ind);
    
}

void ModifyTree(int x, bool isHigh, int isAdd)
{
    Modify(indOf[x], isHigh, isAdd);
    if (ind[isHigh][x] < adj[isHigh][x].size())
        ModifyTree(adj[isHigh][x][ind[isHigh][x]], isHigh, isAdd);
}

int main()
{
    int n = read();
    for (int i = 1; i <= n; ++i)
        arr[i] = read(), indOf[arr[i]] = i;
    set<int> s;
    s.insert(INT_MAX);
    for (int i = 1; i <= n; ++i)
    {
        int t = *s.upper_bound(arr[i]);
        if (t == INT_MAX)
        {
            adj[1][0].push_back(arr[i]);
            parent[1][arr[i]] = 0;
        }
        else
        {
            adj[1][t].push_back(arr[i]);
            parent[1][arr[i]] = t;
        }
        s.insert(arr[i]);
    }
    s.clear();
    s.insert(0);
    for (int i = 1; i <= n; ++i)
    {
        auto it = s.lower_bound(arr[i]);
        it--;
        int t = *it;

            adj[0][t].push_back(arr[i]);
            parent[0][arr[i]] = t;
        s.insert(arr[i]);
    }
    for (int i = 0; i <= n; ++i)
        ind[0][i] = adj[0][i].size();

    ModifyTree(adj[1][0][0], true, 1);
    write(ans), putchar('\n');
    for (int i = 1; i <= n; ++i)
    {
        //modify high
        int p = parent[1][i];
        ModifyTree(adj[1][p][ind[1][p]], 1, -1);
        ++ind[1][p];
        if(ind[1][p] < adj[1][p].size())
            ModifyTree(adj[1][p][ind[1][p]], 1, 1);

        //modify low
        p = parent[0][i];
        if (ind[0][p] < adj[0][p].size())
            ModifyTree(adj[0][p][ind[0][p]], 0, -1);
        --ind[0][p];
        ModifyTree(adj[0][p][ind[0][p]], 0, 1);

        write(ans), putchar('\n');
    }
    return 0;
}