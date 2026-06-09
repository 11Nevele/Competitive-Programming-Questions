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


bool solve(vector<int>& arr, int g, int k)
{
    vector<LL> dp(arr.size(), LL_MAX);
    dp[0] = -LL_MAX;
    int curInd = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == -1)
        {
            ++curInd;
            for (int j = curInd; j > 0; --j)
                dp[j] = dp[j - 1] + g;
            dp[1] = -LL_MAX;
        }
        else
        {
            auto it = upper_bound(dp.begin(), dp.end(), arr[i] - g);
            if (it == dp.begin())
                continue;
            --it;
			int ind = it - dp.begin();
			dp[ind + 1] = arr[i];
			if (ind + 1 > curInd)
				curInd = ind + 1;
        }
		if (curInd >= k)
			return true;
    }
    return false;
}
int main()
{
    int n = read(), k = read();
	vector<int> arr(n + 1);
    int negCnt = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = read();
		if (arr[i] == -1)
			++negCnt;
    }
    if (negCnt >= k - 1)
    {
        cout << "Infinity\n";
        return 0;
    }
    if (!solve(arr, 0, k))
    {
        cout << -1 << endl;
        return 0;
    }
    int l = 0, r = 1e9;
    while (l < r)
    {
		int mid = (l + r + 1) / 2;
        if (solve(arr, mid, k))
            l = mid;
        else
			r = mid - 1;
    }
	cout << l << endl;
		
    
    return 0;
}