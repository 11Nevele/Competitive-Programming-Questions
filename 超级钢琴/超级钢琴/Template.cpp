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
vector<vector<LL>> st;
vector<LL> psa;
void StInit(int n, const vector<LL>& arr)
{
    int size = log2(n);
    st.resize(size + 1, vector<LL>(arr.size()));
    for (int i = 0; i < st[0].size(); ++i)
        st[0][i] = i;
    int pow = 1;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int a=st[i - 1][j], b = st[i - 1][(j + pow) >= n ? n : (j + pow)];
            if (psa[a] > psa[b])
                st[i][j] = a;
            else
                st[i][j] = b;
        }
        pow = pow << 1;
    }

}
int GetSt(int s, int e)
{
    int dif = e - s + 1, level = log2(dif), remain = dif - pow(2, level);
    int a = st[level][s], b = st[level][s + remain];
    if (psa[a] > psa[b])
        return a;
    return b;

}
class node
{
public:
    int l;
    int s;
    int e;
    int mxInd;
    bool operator < (const node& other) const
    {
        return psa[mxInd] - psa[l - 1] < psa[other.mxInd] - psa[other.l - 1];
    }
};
int main()
{
    int n = read(), k = read(), l = read(), r = read();
    psa.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        psa[i] = read() + psa[i - 1];
    StInit(n, psa);
    priority_queue<node> q;
    for (int i = 1; i <= n; ++i)
    {
        int s = i + l - 1, e = i + r - 1;
        if (s > n)
            break;
        if (e > n)
            e = n;
        q.push({ i, s, e, GetSt(s,e) });
    }
    LL ans = 0;
    while (k--)
    {
        node t = q.top();
        q.pop();
        ans += psa[t.mxInd] - psa[t.l - 1];
        int ne = t.mxInd - 1, nl = t.mxInd + 1;
        if (t.s <= ne)
            q.push({ t.l, t.s, ne, GetSt(t.s, ne) });
        if (nl <= t.e)
            q.push({ t.l,nl,t.e,GetSt(nl,t.e) });
    }
    write(ans), putchar('\n');

    return 0;
}