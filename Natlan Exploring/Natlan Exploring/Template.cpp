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

const int MOD = 998244353;

// Function to compute all divisors of a number
vector<int> getDivisors(int num) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            divisors.push_back(i);
            if (i != num / i) {
                divisors.push_back(num / i);
            }
        }
    }
    return divisors;
}

// Main function to count distinct paths
int countPaths(int n, vector<int>& a) {
    // Step 1: Group cities by divisors
    unordered_map<int, vector<int>> divMap;
    for (int i = 0; i < n; ++i) {
        vector<int> divisors = getDivisors(a[i]);
        for (int d : divisors) {
            divMap[d].push_back(i);
        }
    }

    // Step 2: Build the graph
    vector<vector<int>> graph(n);
    for (auto& i : divMap) 
    {
        int divisor = i.first;
        auto& indices = i.second;
        int size = indices.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (indices[i] < indices[j]) {
                    graph[indices[i]].push_back(indices[j]);
                }
            }
        }
    }

    // Step 3: Dynamic Programming
    vector<int> dp(n, 0);
    dp[0] = 1; // Start from City 1

    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    // Step 4: Return result for City n
    return dp[n - 1];
}

int main() {
    int n = 5;
    vector<int> a = { 2, 3, 3, 4, 6 }; // Example attractiveness ratings

    cout << countPaths(n, a) << endl;
    return 0;
}
