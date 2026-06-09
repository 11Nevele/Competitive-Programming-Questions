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
LL Solve(multiset<pair<int,int>> &s)
{
	LL ans = 0;
	for (auto i = s.begin(); i != s.end(); i++)
	{
        if (i->first <= ans)
            ans += i->second;
        else
			ans = i->first + i->second - 1;
	}
	return ans;
}
typedef long long ll;

const ll NEG_INF = -1000000000000000000LL;
struct Node {
    ll T;
    ll M;
};
inline Node mergeNode(const Node& L, const Node& R) 
{
    Node res;
    res.T = L.T + R.T;
    res.M = max(L.M, R.M - L.T);
    return res;
}


struct SegmentTree 
{
    int n;
    int size;
    vector<Node> tree;

    SegmentTree(int n_) : n(n_) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(4 * size, { 0, NEG_INF });
    }

    void update(int idx, ll delta, int s_val) 
    {
        int pos = idx + size;
        tree[pos].T += delta;
        if (tree[pos].T > 0)
            tree[pos].M = s_val;
        else
            tree[pos].M = NEG_INF;
        for (pos /= 2; pos >= 1; pos /= 2) {
            tree[pos] = mergeNode(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    Node query() {
        return tree[1];
    }
};
void solve2(int Q)
{
    const int MOD = 1000003;

    SegmentTree seg(MOD);

    vector<pair<int, int>> assignments;
    assignments.reserve(Q);

    ll ans = 0;
    for (int q = 0; q < Q; q++) {
        char type;
        cin >> type;
        if (type == 'A') {
            int s_prime, t_prime;
            cin >> s_prime >> t_prime;
            int s = (s_prime + ans) % MOD;
            int t = (t_prime + ans) % MOD;
            assignments.push_back({ s, t });
            seg.update(s, t, s);
        }
        else 
        {
            int i_prime;
            cin >> i_prime;
            int delIndex = (i_prime + ans) % MOD;
            auto pr = assignments[delIndex - 1];
            int s = pr.first;
            int t = pr.second;
            seg.update(s, -t, s);
        }

        Node root = seg.query();
        ll totalT = root.T;
        ll finishTime = totalT + max(0LL, root.M);
        ans = finishTime;
        --ans;
        cout << ans << "\n";
    }
}
int main()
{
    vector<pair<int, int>> p;
    multiset<pair<int, int>> st;
    int q = read();
    if (q > 3000)
    {
		solve2(q);
		return 0;
    }
    const int mod = 1e6 + 3;
    LL ans = 0;
    while (q--)
    {
        char c = getchar();
        if (c == 'A')
        {
			int s = (readLL() +ans ) %mod, t = (readLL()+ans) % mod;
			p.push_back({ s,t });
			st.insert({ s,t });
		}
		else if (c == 'D')
		{
            int x = (readLL() + ans) % mod;
			st.erase(st.find(p[x - 1]));
        }
		ans  = Solve(st);
		write(ans),putchar('\n');
    }

    return 0;
}