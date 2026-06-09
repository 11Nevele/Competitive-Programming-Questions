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

LL getMx(vector<int>&arr, int w, bool b)
{
    LL ans = 0;
    int cur = w;
	int l = 0, r = arr.size() - 1;
	while (l <= r)
	{
		if (arr[l] > cur)
		{
			ans += abs(arr[l] - cur);
			cur = arr[l];
		}
		else if (arr[r] < cur)
		{
			ans += abs(arr[r] - cur);
			cur = arr[r];
		}
		else
		{
			ans += abs(arr[l] - cur);
			cur = arr[l];
		}
		l++;
		r--;
	}
	return ans;
}

int main()
{
    int n = read(), w = read(), wcnt = 0;
    multiset<int> s;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = read();
        s.insert(arr[i]);

    }
    sort(arr.begin(), arr.end());
    vector<int> arrr = arr;
	reverse(arrr.begin(), arrr.end());
    int cur = w, cur2 = w;
    LL mn1 = 0, mn2 = 0;
    bool larger = true, smaller = true;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] >= w && larger)
        {
            cur = w;
            larger = false;
        }
		mn1 += abs(arr[i] - cur);
        cur = arr[i];

        if (arrr[i] <= w && smaller)
        {
            cur2 = w;
            smaller = false;
        }
        mn2 += abs(arrr[i] - cur2);
        cur2 = arrr[i];
    }

    mn1 = min(mn1, mn2);

	LL mx = max(getMx(s, w, true ), getMx(s, w, false));

    
	cout << mn1 << " " << mx << endl;

    return 0;
}