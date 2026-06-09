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
class DSU
{

public:
    std::vector<size_t> parent;
    std::vector<size_t> cnt;
    DSU(size_t size) :parent(size), cnt(size, 1)
    {
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }
    size_t Find(size_t x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    bool Unite(size_t a, size_t b)
    {
        int pa = parent[Find(a)], pb = parent[Find(b)];
        if (pa == pb)
            return false;
        if (pa > pb)
        {
            cnt[pa] += cnt[pb];
            parent[pb] = pa;
        }
        else
        {
            cnt[pb] += cnt[pa];
            parent[pa] = pb;
        }
        return true;
    }
};
LL GetSum(int n)
{
    //sum from 1 = n
	return (LL)n * (n + 1) / 2;
}
int main()
{
    int n = read(), m = read();
	DSU dsu(n + 1), dsu2(n + 1);
    string str;
    cin >> str;
    vector<vector<int>> adj(n + 1);
    vector<int> cnt(n + 1);
    while (m--)
    {
        int a = read(), b = read();
        if(b < a)
			swap(a, b);
		adj[a].push_back(b);
    }
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '0') 
            continue;
        for(int j : adj[i + 1])
			dsu.Unite(i + 1, j);
    }
    LL ans = 0;
	vector<LL> ansVec;
    for (int i = n; i; --i)
    {
        int t = dsu.Find(i);
		if(dsu2.Unite(t, i));
		    ans += (dsu2.cnt[dsu2.Find(i)] - 1);
        if (str[i - 1] == '0')
        {
            for (int j : adj[i])
            {
				int a = dsu2.Find(i), b = dsu2.Find(j);
                if (a != b)
                {
					ans -= GetSum(dsu2.cnt[a] - 1);
					ans -= GetSum(dsu2.cnt[b] - 1);
					dsu2.Unite(a, b);
					ans += GetSum(dsu2.cnt[dsu2.Find(a)] - 1);
                }
            }
        }
		ansVec.push_back(ans);
    }
    for (int i = n - 1; i >= 0; --i)
        write(ansVec[i]), putchar('\n');
    
    return 0;
}