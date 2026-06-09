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

int main()
{
    int n = read();
    vector<pair<int, int>> arr(n), nodes,seg;
    unordered_map<int, int> mp;
    vector<LL> psa(200005);
    for (int i = 0; i < n; ++i)
    {
        int a = read(), b = read();
        arr[i].first = a, arr[i].second = b;
        nodes.push_back({ a, 1 });
        nodes.push_back({ b,-1 });
    }
    sort(nodes.begin(), nodes.end());
    
    int pre = nodes[0].first, cnt = 0, ind = 0, c = 0;
    mp[nodes[0].first] = seg.size();
    while (ind < nodes.size() - 1 && nodes[ind].first == nodes[ind + 1].first)
    {
        cnt += nodes[ind].second;
        ++ind;
    }
    cnt += nodes[ind].second;
    ++ind;
    
    while(ind < nodes.size())
    {
        seg.push_back({ cnt, nodes[ind].first - pre});
        mp[nodes[ind].first] = seg.size();
        
        pre = nodes[ind].first;
        while (ind < nodes.size() - 1 && nodes[ind].first == nodes[ind + 1].first)
        {
            cnt += nodes[ind].second;
            ++ind;
        }
        cnt += nodes[ind].second;
        ++ind;
    }
    int sum = 0;
    for (int i = 0; i < seg.size(); ++i)
    {
        if (seg[i].first > 0)
            sum += seg[i].second;
        if (seg[i].first == 1)
            psa[i] = seg[i].second;
    }
    for (int i = 1; i < psa.size(); ++i)
        psa[i] += psa[i - 1];
    int mx = 0;
    for (const auto &i:arr)
    {
        int t = psa[mp[i.second] - 1];
        if (mp[i.first] > 0)
            t -= psa[mp[i.first] - 1];
        mx = max(mx, sum - t);
    }
    write(mx), putchar('\n');
    return 0;
}