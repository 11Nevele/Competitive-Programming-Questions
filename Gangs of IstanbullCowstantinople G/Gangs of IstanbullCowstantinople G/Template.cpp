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
struct cmp
{
    bool operator ()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

int solve(priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>& s)
{
    while (s.size() > 1)
    {
        pair<int, int> a = s.top();
        s.pop();
        pair<int, int> b = s.top();
        s.pop();
        if (a.first != 1)
            s.push({ a.first - 1, a.second });
        if (b.first != 1)
            s.push({ b.first - 1, b.second });
    }
    if (s.size() == 1)
    {
		return s.top().first;
    }
    else
        return 0;
}
int GetMxInd(vector<int>& arr)
{
	int mx = 0, ind = 0;
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i] > mx)
			mx = arr[i], ind = i;
	}
	return ind;
}
int main()
{
	int n = read(), m = read();
    vector<int> arr(m + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> s;
    int Cnt1 = read();
	arr[1] = Cnt1;
    for (int i = 2; i <= m; ++i)
    {
        int t = read();
        arr[i] = t;
        s.push({ t, i });

    }
		
	int remain = solve(s);
    if (remain >= Cnt1)
    {
		cout << "NO\n";
        return 0;
    }
	Cnt1 -= remain;
	cout << "YES\n";
    write(Cnt1), putchar('\n');
    n -= arr[1];
    arr[1] = 0;
    int cur = 0, curAmt = 0, f = 2, mxInd = GetMxInd(arr);
    if (remain > 0)
    {
        cur = 1, curAmt = remain;
        for(int i = 0; i < remain; ++i)
			write(1), putchar('\n');
    }
        
    
    
    while (n > 0)
    {
        if (curAmt == 0)
        {
            cur = f;
			curAmt = arr[f];
            n -= arr[f];
            while(arr[f])
				write(f), putchar('\n'), arr[f]--;
        }
        else
        {
            if (arr[mxInd] > (n + curAmt - arr[mxInd]) - 2)
            {
				write(mxInd), putchar('\n');
                --arr[mxInd];
				--curAmt;
				--n;
            }
            else
            {
				write(f), putchar('\n');
				--arr[f];
				--curAmt;
				--n;
            }
        }
        while (f < arr.size() && arr[f] == 0)
            f++;
		mxInd = GetMxInd(arr);
    }
	for (int i = 0; i < Cnt1; ++i)
		write(1), putchar('\n');
	
    return 0;
}