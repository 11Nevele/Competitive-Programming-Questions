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
void swap(set<int>** a, set<int>** b) {
    set<int>* temp = *a;
    *a = *b;
    *b = temp;
}
void emerge(set<int>* from, set<int>* to)
{
    if (from->size() > to->size())
    {
        swap(from, to);
    }
    for (int i : *from)
        to->insert(i);
}

int main()
{
    int n = read(), m = read();
    
    vector<set<int>*> adj(n + 1);
    for (int i = 0; i < n + 1; ++i)
        adj[i] = new set<int>();
    vector<pair<int, int>> sides;
    for (int i = 0; i < m; ++i)
    {
        int a = read(), b = read();
        if (a > b)
            swap(a, b);
        if (a == b)
            continue;
        sides.push_back({ a,b });
        adj[a]->insert(b);
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (adj[i]->size() == 0)
            continue;
        int c = *(adj[i]->begin());
        adj[i]->erase(c);
        ans += adj[i]->size() + 1;
        if (adj[i]->size() > adj[c]->size())
        {
            swap(adj[i], adj[c]);
        }
        for (int i : *adj[i])
            adj[c]->insert(i);
        
    }
    
    write(ans), putchar('\n');

    return 0;
}