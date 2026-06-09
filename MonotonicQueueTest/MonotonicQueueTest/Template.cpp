#include <iostream>
#include <vector>
#include <deque>
using namespace std;


struct Line {
    long long m, b;  // y = m * x + b
    int idx;

    long long eval(int x) const {
        return m * x + b;
    }

    // Return true if l2 is worse than l1 and new
    static bool isBad(const Line& l1, const Line& l2, const Line& l3) {
        return (l3.b - l1.b) * (l1.m - l2.m) <= (l2.b - l1.b) * (l1.m - l3.m);
    }
};

vector<long long> solve(const vector<int>& arr) {
    int n = arr.size();
    vector<long long> res(n);
    deque<Line> dq;

    for (int j = 0; j < n; ++j) {
        long long m = -2LL * j;
        long long b = (long long)arr[j] + 1LL * (j + 1) * (j + 1);
        Line newLine = { m, b, j };

        // Maintain convex hull: remove back if new line makes it obsolete
        while (dq.size() >= 2 && Line::isBad(dq[dq.size() - 2], dq[dq.size() - 1], newLine)) {
            dq.pop_back();
        }
        dq.push_back(newLine);

        // Query best line at x = i = j
        int x = j + 1;
        while (dq.size() >= 2 && dq[0].eval(x) <= dq[1].eval(x)) {
            dq.pop_front();
        }

        res[j] = 1LL * x * x + dq[0].eval(x);
    }

    return res;
}

int main() {
    vector<int> arr = { 1,1,1,1,1,1, 50, 1, 1, 1, 1, 1, 1,1,1,1 };
    vector<long long> res = solve(arr);

    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}