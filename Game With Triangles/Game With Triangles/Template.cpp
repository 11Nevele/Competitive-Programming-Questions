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
//return
//-1: aInd too large
//0 valid
//1 bInd too large
int checkValid(int n, int m, int aInd, int bInd)
{
    if (aInd * 2 > (n - bInd))
        return -1;
    else if (bInd * 2 > (m - aInd))
        return 1;
    return 0;
}
void solve()
{
    int n = read(), m = read();
    vector<int> a(n), b(m);
    int kmax = (n + m) / 3;
    int aMx = n / 2, bMx = m / 2;
    vector<LL> fa(kmax + 1), fb(kmax + 1);
    for (int& i : a)
        i = read();
    for (int& i : b)
        i = read();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 1; i < fa.size(); ++i)
    {
        fa[i] = fa[i - 1];
        if (i <= n / 2)
            fa[i] += (LL)a[a.size() - i] - a[i - 1];
    }
    for (int i = 1; i < fb.size(); ++i)
    {
        fb[i] = fb[i - 1];
        if (i <= m / 2)
            fb[i] += (LL)b[b.size() - i] - b[i - 1];
    }
    vector<LL> ans;
    for (int i = 1; i <= (n + m) / 3; ++i)
    {
        int l = 0, r = i;
        while (l < r)
        {
			int aInd = (l + r) / 2, bInd = i - aInd;
			int check = checkValid(n, m, aInd, bInd);
            if (check == -1)
                r = aInd - 1;
            else if (check == 1)
                l = aInd + 1;
            else
            {
				int check2 = checkValid(n, m, aInd + 1, i - aInd - 1);
                if (check2 != 0)
                    r = aInd;
                else
                {
					bool b = fa[aInd] + fb[bInd] >= fa[aInd + 1] + fb[bInd - 1];
                    if (b)
                        r = aInd;
                    else
                        l = aInd + 1;
                }
            }
        }
        if (checkValid(n, m, l, i - l) == 0)
            ans.push_back(fa[l] + fb[i - l]);
        else
            break;
    }
    write((int)ans.size()),putchar('\n');
    for (LL& i : ans)
        write(i), putchar(' ');
    putchar('\n');
}

int main()
{
    int t = read();
    while (t--)
        solve();
    return 0;
}