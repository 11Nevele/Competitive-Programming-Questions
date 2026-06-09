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
//binary search for the averge
//*minus every element by average
//*remove the largest subarray using kadane
//if the reaming sum is smaller than zero, means average is lower, else higher

bool check(vector<LL>& arr, LL avg)
{
    LL sum = 0, maxSum = -INT_MAX, tot = 0, mx = -INT_MAX;
	for (int i = 0; i < arr.size(); i++)
 		arr[i] -= avg, tot += arr[i];
    for (int i = 1; i < arr.size() - 1; i++)
	{
        sum += arr[i];
        mx = max(mx, arr[i]);
		if (sum < 0)
			sum = 0;
        else
		    maxSum = max(maxSum, sum);
	}
    if(maxSum == -INT_MAX)
		maxSum = mx;
    for (int i = 0; i < arr.size(); i++)
        arr[i] += avg;
    if (tot - maxSum <= 0)
        return true;
    else
        return false;
	
}
int main()
{
    int n = read();
	vector<LL> arr(n);
	for (int i = 0; i < n; i++)
		arr[i] = (LL)read() * 100000;
    int l = 0, r = 1000000000;
    while (l < r)
    {
        //find first true
		int mid = (l + r) / 2;
  		bool b = check(arr, mid);
        if(b)
			r = mid;
		else
			l = mid + 1;
    }
	cout << fixed << setprecision(3) << (double)l / 100000 << endl;
    return 0;
}