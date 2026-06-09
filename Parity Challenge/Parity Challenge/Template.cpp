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

class SegTree
{
public:
    vector<bool> parity;
    vector<bool> op;
    vector<pair<int, int>> range;
    const int size;
    void build(int x, int l, int r, const vector<bool>& np, const vector<bool>& no)
    {
        range[x].first = l;
        range[x].second = r;
        if (l == r)
        {
				parity[x] = np[l];
				op[x] = no[l];
            return;
        }

        int mid = (l + r) >> 1;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        build(lChild, l, mid, np,no), build(rChild, mid + 1, r, np,no);
        op[x] = op[lChild];
        if(op[rChild])
		{
			parity[x] = parity[lChild] ^ parity[rChild];
		}
		else
		{
			parity[x] = parity[lChild] & parity[rChild];
		}
    }
    SegTree(int newSize, const vector<bool>& np, const vector<bool>& no)
        : size(newSize), parity(4 * newSize), op(4 * newSize), range(4 * newSize)
    {
        build(0, 1, size, np,no);
    }
    void ChangeNum(int x, const int l, const int r, bool isNum)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
			if (isNum)
                parity[x] = !parity[x];
            else
				op[x] = !op[x];
            return;
        }
        if (r < range[x].first || l > range[x].second)
            return;
        int lChild = (x << 1) + 1, rChild = (x << 1) + 2;
        ChangeNum(lChild, l, r, isNum), ChangeNum(rChild, l, r, isNum);
        op[x] = op[lChild];
        if (op[rChild])
        {
            parity[x] = parity[lChild] ^ parity[rChild];
        }
        else
        {
            parity[x] = parity[lChild] & parity[rChild];
        }
    }
    pair<bool,bool> GetRange(int x, int l, int r)
    {
        if (l <= range[x].first && r >= range[x].second)
        {
			return { op[x],parity[x] };
        }
        if (r < range[x].first || l > range[x].second)
        {
            return { 0, 0 };
        }
		pair<bool, bool> lChild = GetRange((x << 1) + 1, l, r), rChild = GetRange((x << 1) + 2, l, r);
        pair<bool, bool> ans;
		ans.first = lChild.first;
        if (rChild.first)
        {
            ans.second = lChild.second ^ rChild.second;
        }
        else
        {
            ans.second = lChild.second & rChild.second;
        }
        return ans;
    }

};
int main()
{
    int n = read(), q = read();
	vector<bool> parity(n + 1), op(n + 1);
	for (int i = 1; i <= n; i++)
	{
        parity[i] = read() & 1;
	}
	for (int i = 2; i <= n; i++)
	{
        char c;
        cin >> c;
        if (c == '+')
            op[i] = 0;
        else
            op[i] = 1;
	}
	SegTree segTree(n, parity, op);
    while (q--)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case 'V':
            int i = read();
			segTree.ChangeNum(0, i, i, true);
            break;
        case 'O':
            int i = read()
            break;
        case 'Q':
            break;
        }
    }

    return 0;
}