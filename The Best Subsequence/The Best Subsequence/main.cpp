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
typedef long long ll;
const ll MOD = 1000000007;

// Fast modular exponentiation.
ll modexp(ll base, ll exp, ll mod = MOD) {
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// We'll compress coordinates. We need to include boundaries from updates and queries.
vector<ll> comp; // sorted unique coordinates

// --- SEGMENT TREE FOR RANGE FLIP UPDATES ---
// Our final array will be stored on the compressed segments. Each leaf i represents the interval
// [comp[i], comp[i+1]-1] of the original indices. (Its "length" is comp[i+1]-comp[i].)
// Initially all values are 0.
struct Node {
    int l, r; // index range in the compressed array [l, r]
    ll ones;  // total number of ones in this segment (weighted by the length of each compressed block)
    ll totLen; // total length in original coordinates (sum of comp[i+1]-comp[i])
    bool allSame; // if the entire segment is uniform
    int allVal;    // if uniform, value (0 or 1)
    bool flip;     // lazy flip flag
};

vector<Node> segTree; // 4 * n

int n; // number of leaves (n = comp.size()-1)

// Build the segment tree over the array (initially all 0)
void buildTree(int idx, int L, int R) {
    segTree[idx].l = L; segTree[idx].r = R;
    segTree[idx].flip = false;
    if (L == R) {
        segTree[idx].totLen = comp[L + 1] - comp[L];
        // initial value = 0
        segTree[idx].ones = 0;
        segTree[idx].allSame = true;
        segTree[idx].allVal = 0;
        return;
    }
    int mid = (L + R) / 2;
    buildTree(idx * 2, L, mid);
    buildTree(idx * 2 + 1, mid + 1, R);
    segTree[idx].totLen = segTree[idx * 2].totLen + segTree[idx * 2 + 1].totLen;
    segTree[idx].ones = segTree[idx * 2].ones + segTree[idx * 2 + 1].ones;
    segTree[idx].allSame = false;
    if (segTree[idx * 2].allSame && segTree[idx * 2 + 1].allSame && segTree[idx * 2].allVal == segTree[idx * 2 + 1].allVal) {
        segTree[idx].allSame = true;
        segTree[idx].allVal = segTree[idx * 2].allVal;
    }
}

// Push lazy flip flag down.
void pushDown(int idx) {
    if (segTree[idx].flip) {
        for (int child = idx * 2; child <= idx * 2 + 1; child++) {
            segTree[child].flip = !segTree[child].flip;
            // flip ones: ones becomes totLen - ones
            segTree[child].ones = segTree[child].totLen - segTree[child].ones;
            if (segTree[child].allSame) {
                segTree[child].allVal = 1 - segTree[child].allVal;
            }
        }
        segTree[idx].flip = false;
    }
}

// Merge children nodes.
void pullUp(int idx) {
    segTree[idx].ones = segTree[idx * 2].ones + segTree[idx * 2 + 1].ones;
    segTree[idx].allSame = false;
    if (segTree[idx * 2].allSame && segTree[idx * 2 + 1].allSame && segTree[idx * 2].allVal == segTree[idx * 2 + 1].allVal) {
        segTree[idx].allSame = true;
        segTree[idx].allVal = segTree[idx * 2].allVal;
    }
}

// Range update: flip bits in [qL, qR] in the leaves (these indices are in the compressed array indices).
void updateTree(int idx, int qL, int qR) {
    int L = segTree[idx].l, R = segTree[idx].r;
    if (qR < L || R < qL) return;
    if (qL <= L && R <= qR) {
        segTree[idx].flip = !segTree[idx].flip;
        segTree[idx].ones = segTree[idx].totLen - segTree[idx].ones;
        if (segTree[idx].allSame)
            segTree[idx].allVal = 1 - segTree[idx].allVal;
        return;
    }
    pushDown(idx);
    updateTree(idx * 2, qL, qR);
    updateTree(idx * 2 + 1, qL, qR);
    pullUp(idx);
}

// Query the final value on the compressed array in [qL, qR].
// We want to “push” all lazy flags so that we can later extract the final intervals.
void queryTree(int idx, int qL, int qR, vector<int>& idxs) {
    int L = segTree[idx].l, R = segTree[idx].r;
    if (qR < L || R < qL) return;
    if (qL <= L && R <= qR && segTree[idx].allSame) {
        idxs.push_back(idx);
        return;
    }
    if (L == R) {
        idxs.push_back(idx);
        return;
    }
    pushDown(idx);
    queryTree(idx * 2, qL, qR, idxs);
    queryTree(idx * 2 + 1, qL, qR, idxs);
}

// After all updates, we want to obtain the final array (over the compressed segments).
// We do a DFS that “pushes” lazy updates.
void pushAll(int idx, vector<int>& leaves) {
    if (segTree[idx].l == segTree[idx].r) {
        leaves.push_back(idx);
        return;
    }
    pushDown(idx);
    pushAll(idx * 2, leaves);
    pushAll(idx * 2 + 1, leaves);
}

// --- INTERVALS OF FINAL ARRAY ---
// We define an interval structure representing a contiguous block [s, e] (in original coordinates)
// with value val.
struct Interval {
    ll s, e;
    int val;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, Q;
    ll N;
    cin >> N >> M >> Q;

    // Collect coordinates for compression.
    // We add boundaries 1 and N+1.
    comp.push_back(1);
    comp.push_back(N + 1);
    vector<tuple<ll, ll>> updates;
    for (int i = 0; i < M; i++) {
        ll L, R;
        cin >> L >> R;
        updates.push_back({ L, R });
        comp.push_back(L);
        comp.push_back(R + 1);
    }
    // Also add query boundaries.
    vector<tuple<ll, ll, ll>> queries;
    for (int i = 0; i < Q; i++) {
        ll L, R, k;
        cin >> L >> R >> k;
        queries.push_back({ L, R, k });
        comp.push_back(L);
        comp.push_back(R + 1);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    // n = number of leaves = comp.size()-1
    n = comp.size() - 1;

    // Build segment tree array.
    segTree.resize(4 * n);
    buildTree(1, 0, n - 1);

    // Process updates.
    // For each update [L, R], convert to indices in the compressed array.
    auto getIndex = [&](ll x) -> int {
        // returns index i such that comp[i] == x
        return int(lower_bound(comp.begin(), comp.end(), x) - comp.begin());
        };
    for (auto& up : updates) {
        ll L, R;
        tie(L, R) = up;
        int iL = getIndex(L);
        int iR = getIndex(R + 1) - 1; // since update covers intervals [L, R]
        if (iL <= iR)
            updateTree(1, iL, iR);
    }

    // Push all lazy flags to get the final array.
    vector<int> leafIdx;
    pushAll(1, leafIdx);
    // Build final intervals from leaves.
    vector<Interval> finalIntervals;
    for (int idx : leafIdx) {
        int i = segTree[idx].l; // leaf index
        ll s = comp[i], e = comp[i + 1] - 1; // interval in original coordinates
        int val = segTree[idx].allVal; // final value (0 or 1)
        // We only keep intervals with nonzero length.
        if (s <= e) {
            // Merge with previous if same value.
            if (!finalIntervals.empty() && finalIntervals.back().val == val && finalIntervals.back().e + 1 == s) {
                finalIntervals.back().e = e;
            }
            else {
                finalIntervals.push_back({ s, e, val });
            }
        }
    }

    // For answering queries we need to quickly find all intervals that intersect [L, R].
    // They are sorted by s.

    // Function to process one query.
    auto processQuery = [&](ll L, ll R, ll k) -> ll {
        ll Lq = R - L + 1; // query substring length
        // We will collect the intervals (of ones) that intersect [L,R].
        vector<pair<ll, ll>> onesIntervals; // each: (relative_start, length)
        // Binary search in finalIntervals.
        int lo = 0, hi = finalIntervals.size() - 1, pos = finalIntervals.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (finalIntervals[mid].e >= L) {
                pos = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        for (int i = pos; i < finalIntervals.size(); i++) {
            if (finalIntervals[i].s > R) break;
            if (finalIntervals[i].val == 1) {
                ll s_int = max(finalIntervals[i].s, L);
                ll e_int = min(finalIntervals[i].e, R);
                // relative position in the query substring: [s_int - L, e_int - L]
                ll relStart = s_int - L;
                ll len = e_int - s_int + 1;
                onesIntervals.push_back({ relStart, len });
            }
        }
        // Merge adjacent ones intervals if they are contiguous in the query substring.
        vector<pair<ll, ll>> merged;
        for (auto& pr : onesIntervals) {
            if (merged.empty()) merged.push_back(pr);
            else {
                // If the next block's start is exactly (previous.start + previous.length), merge.
                if (merged.back().first + merged.back().second == pr.first) {
                    merged.back().second += pr.second;
                }
                else {
                    merged.push_back(pr);
                }
            }
        }
        // Compute total ones count.
        ll totOnes = 0;
        for (auto& pr : merged) totOnes += pr.second;
        // If totOnes >= k then answer is k ones: value = 2^k - 1 mod MOD.
        if (totOnes >= k) {
            ll ans = (modexp(2, k, MOD) - 1) % MOD;
            if (ans < 0) ans += MOD;
            return ans;
        }
        // Otherwise, simulate the greedy assignment.
        // The greedy rule (after re–basin the query so that its positions are 0..Lq-1)
        // assigns each one at a relative position p to subsequence position:
        // candidate = max(cur+1, p + A)  with A = k - Lq + 1, and initial cur = 0.
        ll A = k - Lq + 1;
        ll cur = 0;
        ll ans = 0;
        // For each merged ones block in increasing order:
        for (auto& pr : merged) {
            ll blockStart = pr.first; // relative position of first one in block
            ll blockLen = pr.second;
            // The earliest this block can “raise” a one is:
            ll candidate = max(cur + 1, blockStart + A);
            // Once we assign the first one from this block at candidate, the block gives ones at positions candidate, candidate+1, …, candidate+blockLen-1.
            // Their contribution is: sum_{i=0}^{blockLen-1} 2^(k - (candidate + i))
            // = (2^(k - candidate + 1) - 2^(k - candidate - blockLen + 1)) mod MOD.
            ll term1 = modexp(2, k - candidate + 1, MOD);
            ll term2 = modexp(2, k - candidate - blockLen + 1, MOD);
            ll blockSum = (term1 - term2) % MOD;
            if (blockSum < 0) blockSum += MOD;
            ans = (ans + blockSum) % MOD;
            cur = candidate + blockLen - 1;
        }
        return ans % MOD;
        };

    // Process queries.
    for (auto& q : queries) {
        ll L, R, k;
        tie(L, R, k) = q;
        ll res = processQuery(L, R, k);
        cout << res % MOD << "\n";
    }
    return 0;
}
