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
using namespace std;
typedef long long ll;

const ll NEG_INF = -1000000000000000000LL; // A very low value for "empty" segments

//----- Segment Tree for Scheduling -----//

// Each node stores:
//   T: total processing time in the segment
//   M: maximum waiting value in the segment
struct Node {
    ll T; // total processing time
    ll M; // maximum waiting value
};

// When merging two segments L and R (with all tasks in L coming before those in R):
//   Combined total processing time: T_comb = T_L + T_R
//   Combined waiting value: M_comb = max( M_L, M_R - T_L )
inline Node mergeNode(const Node& L, const Node& R) {
    Node res;
    res.T = L.T + R.T;
    res.M = max(L.M, R.M - L.T);
    return res;
}

struct SegmentTree {
    int n;
    int size;
    vector<Node> tree;

    // Our leaves correspond to possible release times [0, MOD-1]
    SegmentTree(int n_) : n(n_) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, { 0, NEG_INF });
    }

    // At leaf index corresponding to release time "idx", add (or subtract) processing time delta.
    // (s_val is used so that if there’s at least one task at that release time, we store s_val.)
    void update(int idx, ll delta, int s_val) {
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

//----- Fenwick Tree (Binary Indexed Tree) for Active Assignments -----//

// This Fenwick tree will be built over the list of assignments (in insertion order).
// At the time of addition we mark an assignment with value 1, and when it is deleted we subtract 1.
// This allows us to quickly find the k-th active assignment.
struct Fenw {
    int n;
    vector<int> fenw;

    Fenw(int n) : n(n), fenw(n + 1, 0) {}

    // Update position idx (0-indexed) by delta.
    void update(int idx, int delta) {
        for (++idx; idx <= n; idx += idx & -idx)
            fenw[idx] += delta;
    }

    // Return prefix sum [0, idx].
    int sum(int idx) {
        int res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res += fenw[idx];
        return res;
    }

    // Find the smallest index such that the prefix sum is at least k.
    // (Returns a 0-indexed position in the assignments array.)
    int findKth(int k) {
        int pos = 0;
        // 2^20 is enough since Q ≤ 10^6.
        for (int i = 1 << 20; i; i >>= 1) {
            if (pos + i <= n && fenw[pos + i] < k) {
                k -= fenw[pos + i];
                pos += i;
            }
        }
        return pos;
    }
};

//----- Structure to store each assignment -----//
struct Assignment {
    int s;      // release time
    int t;      // processing time
    bool active;
};

//
// Main
//
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    const int MOD = 1000003; // 10^6+3

    // Build the segment tree over release times [0, MOD-1]
    SegmentTree seg(MOD);

    // Fenwick tree for tracking active assignments.
    // Maximum number of assignments added will be at most Q.
    Fenw fenw(Q);

    // Store assignments in order of addition.
    vector<Assignment> assignments;
    assignments.reserve(Q);

    ll ans = 0; // "ans" is used for decryption; initially 0.
    int totalAssignments = 0; // counts the total number added (also used as index into assignments)

    for (int q = 0; q < Q; q++) {
        char type;
        cin >> type;
        if (type == 'A') {
            int s_prime, t_prime;
            cin >> s_prime >> t_prime;
            // Decrypt the values.
            int s = (s_prime + ans) % MOD;
            int t = (t_prime + ans) % MOD;

            // Add the assignment.
            Assignment ass;
            ass.s = s;
            ass.t = t;
            ass.active = true;
            assignments.push_back(ass);

            // Mark this assignment as active in the Fenwick tree.
            fenw.update(totalAssignments, 1);
            totalAssignments++;

            // Update the segment tree: add processing time t at release time s.
            seg.update(s, t, s);
        }
        else { // 'D' deletion update.
            int i_prime;
            cin >> i_prime;
            // Decrypt deletion index.
            // (We assume the decrypted index is 0-indexed. If your problem is 1-indexed, subtract 1.)
            int i = (i_prime + ans) % MOD;
            // Use the Fenwick tree to find the index (in the assignments vector) of the i-th active assignment.
            // Since our Fenw "findKth" expects a 1-indexed order statistic, we search for (i+1)-th active assignment.
            int activeIndex = fenw.findKth(i + 1);

            // Remove that assignment (it is guaranteed to be active).
            if (assignments[activeIndex].active) {
                assignments[activeIndex].active = false;
                int s = assignments[activeIndex].s;
                int t = assignments[activeIndex].t;
                // Remove its processing time from the segment tree.
                seg.update(s, -t, s);
                // Mark it as inactive in the Fenwick tree.
                fenw.update(activeIndex, -1);
            }
        }

        // After each update, query the segment tree.
        Node root = seg.query();
        ll totalT = root.T;
        // The earliest finishing time is: total processing time + max(0, waiting value)
        ll finishTime = totalT + max(0LL, root.M);
        ans = finishTime; // update "ans" for decryption of future queries.
        --ans;
        cout << ans << "\n";
    }

    return 0;
}
