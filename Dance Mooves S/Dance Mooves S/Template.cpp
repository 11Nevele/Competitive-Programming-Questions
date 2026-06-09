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

vector<unordered_set<int>> mp(100005);
int main()
{
    int n = read(), k = read();
    vector<pair<int, int>> swaps(k);
    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = i;
        mp[i].insert(i);
    }
        
    
    for (auto& i : swaps)
    {
        i.first = read(), i.second = read();
        swap(arr[i.first], arr[i.second]);
        mp[arr[i.first]].insert(i.second);
        mp[arr[i.second]].insert(i.first);
    }
        
    for (int i = 1; i <= n; ++i)
    {
        pos[arr[i]] = i;
    }

    vector<int> v(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        unordered_set<int> t;
        int cur = i;
        while (!v[cur])
        {
            v[cur] = i;
            for (auto &i : mp[cur])
                t.insert(i);
            cur = pos[cur];
        }
        ans[i] = t.size();
    }
    for (int i = 1; i <= n; ++i)
    {
        write(ans[v[i]]), putchar('\n');
    }
    return 0;
}