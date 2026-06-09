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


void update(vector<int>& f, vector<int>& s, int ind, multiset<int,greater<int>> &set,
    multiset<int, greater<int>>& tp, multiset<int, greater<int>>& b)
{
	auto it = set.begin();
    f[ind] = *it;
	if (set.size() > 1)
	{
		++it;
		s[ind] = *it;
	}
	else
	{
		s[ind] = 0;
	}
    tp.insert(f[ind]);
    b.insert(s[ind]);
}
int main()
{
    int n = read(), m = read(), q = read();
    vector<multiset<int, greater<int>>> sets(m + 1);
	vector<pair<int, int>> pens(n + 1);
    for (int i = 1; i <= n; ++i)
    {

        int c = read(), p = read();
        pens[i] = { c, p };
		sets[c].insert(p);
    }
    multiset<int, greater<int>> tp, b;
    vector<int> f(m + 1), s(m + 1);
    LL sum = 0, secondMx = 0;
    for (int i = 1; i <= m; ++i)
    {
		auto it = sets[i].begin();
        if (sets[i].size() > 1)
        {
            ++it;
			secondMx = max(secondMx, (LL)*it);
        }
		sum += *sets[i].begin();
		update(f, s, i, sets[i], tp, b);
        
    }
    LL x = 0;
    if (b.size())
        x = *b.begin();
    LL t = max(sum, sum - *(--tp.end()) + x);
    write(t), putchar('\n');
    
    while (q--)
    {
        int op = read();
        if (op == 1)
        {
            int ind = read(), c = read();
            int oriC = pens[ind].first;
            tp.erase(tp.find(f[oriC]));
            tp.erase(tp.find(f[c]));
			b.erase(b.find(s[oriC]));
			b.erase(b.find(s[c]));

			sum -= *sets[pens[ind].first].begin();
            sum -= *sets[c].begin();

           
            sets[oriC].erase(sets[oriC].find(pens[ind].second));
            
			sets[c].insert(pens[ind].second);

            sum += *sets[oriC].begin();
            sum += *sets[c].begin();

            pens[ind].first = c;

			update(f, s, oriC, sets[oriC], tp, b);
			update(f, s, c, sets[c], tp, b);
        }
        else
        {
            int ind = read(), p = read();
            int c = pens[ind].first;

            tp.erase(tp.find(f[c]));
            b.erase(b.find(s[c]));

			sum -= *sets[c].begin();
			sets[c].erase(sets[c].find(pens[ind].second));
			pens[ind].second = p;
			sets[c].insert(pens[ind].second);
			sum += *sets[c].begin();

			update(f, s, c, sets[c], tp, b);
        }

        LL x = 0;
        if (b.size())
            x = *b.begin();
        LL t = max(sum, sum - *(--tp.end()) + x);
        write(t), putchar('\n');
    }

    return 0;
}