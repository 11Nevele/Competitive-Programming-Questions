#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#define MAXN 200005
struct node
{
    long long val;
    long long lazy;
    int l;
    int r;
    long long size() { return r - l + 1; }
};
vector<node> seg(4 * MAXN);
void Push(vector<node>& seg, int x)
{
	int lc = x * 2 + 1, rc = x * 2 + 2;
    seg[lc].val += seg[x].lazy * seg[lc].size();
    seg[rc].val += seg[x].lazy * seg[rc].size();
    seg[lc].lazy += seg[x].lazy;
    seg[rc].lazy += seg[x].lazy;
    seg[x].lazy = 0;
}
void Build(vector<node>& seg, vector<long long>& arr, int x, int l, int r)
{
    seg[x].l = l, seg[x].r = r;
    if (l == r)
    {
        seg[x].val = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    int lc = x * 2 + 1, rc = x * 2 + 2;
    Build(seg, arr, lc, l, mid);
    Build(seg, arr, rc, mid + 1, r);
    seg[x].val = seg[x * 2 + 1].val + seg[x * 2 + 2].val;
}
void Change(vector<node>& seg, int x, int tl, int tr, long long v)
{
    if (tl > seg[x].r || tr < seg[x].l) return;
    int lc = x * 2 + 1, rc = x * 2 + 2;
    if (tl <= seg[x].l && seg[x].r <= tr)
    {
        seg[x].val += (v) * seg[x].size();
        seg[x].lazy += v;
        return;
    }
    Push(seg, x);
    Change(seg, lc, tl, tr, v);
    Change(seg, rc, tl, tr, v);
    seg[x].val = seg[lc].val + seg[rc].val;
}
long long Get(vector<node>& seg, int x, int tl, int tr)
{
    if (tl > seg[x].r || tr < seg[x].l) return 0 ;
    int lc = x * 2 + 1, rc = x * 2 + 2;
    if (tl <= seg[x].l && seg[x].r <= tr)
    {
        return seg[x].val;
    }
    Push(seg, x);
    return Get(seg, lc, tl, tr) + Get(seg, rc, tl, tr);
}

int main()
{
    //fast io
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    Build(seg, arr, 0, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            Change(seg, 0, l, r, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << Get(seg, 0, l, r) << endl;
        }
    }
}
