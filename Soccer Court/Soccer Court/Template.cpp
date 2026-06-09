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
LL Get(vector<vector<LL>>& psa, int r1,int c1, int r2, int c2)
{
	return psa[r2][c2] - psa[r1 - 1][c2] - psa[r2][c1 - 1] + psa[r1 - 1][c1 - 1];
}

int maxEqualRange(const vector<LL>& a, const vector<LL>& b) {
    unordered_map<LL, int> diffMap; // Stores first occurrence of prefix_sum_diff
    diffMap[0] = 0; // Base case for when the prefix sums are initially equal
    int maxLen = 0;
    LL prefixA = 0, prefixB = 0;

    for (int i = 0; i < a.size(); i++) {
        prefixA += a[i];
        prefixB += b[i];
        LL diff = prefixA - prefixB;

        if (diffMap.find(diff) != diffMap.end()) 
        {
            int length = i - diffMap[diff];
            if (length > maxLen) {
                maxLen = length;
            }
        }
        else {
            diffMap[diff] = i;
        }
    }

    return maxLen; // Returns (-1, -1) if no valid range is found
}
int main()
{
    int n = read(), m = read();
	vector<vector<LL>> psa(n + 1, vector<LL>(m + 1, 0)), arr(n + 1, vector<LL>(m + 1, 0));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
			arr[i][j] = read(), psa[i][j] = arr[i][j] + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
    int ans = 0;
    for (int i = 1; i < m; ++i)
    {
		vector<LL> a(n + 1, 0), b(n + 1, 0);
        for (int j = 1; i - j + 1 > 0 && i + j <= m; ++j)
        {
            int l = i - j + 1, r = i + j;
			for (int k = 1; k <= n; ++k)
				a[k] += arr[k][l], b[k] += arr[k][r];
			int t = maxEqualRange(a, b);
            ans = max(ans, (r - l + 1) * t);
        }
    }
    write(ans), putchar('\n');
    return 0;
}