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
int start, end;
bool CycleDetect(const vector<const vector<pair<int,int>>>& adj, vector<int>& v, int n, int p)
{

}
void ShorestPath(const vector<const vector<pair<int, int>>>& adj, vector<int> &shorest, vector<int> &parent)
{

}
pair<int,int> FindAnswer(const vector<const vector<pair<int, int>>>& adj)
int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), m = read();
        vector<vector<int>> adj(n + 1);
        vector<bool> v(n + 1);
        vector<int> shortest(n + 1), parent(n + 1);
        while (m--)
        {
            int a = read(), b = read();
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

    }
}
