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

int main()
{
    int n = read();
	vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = read();
    vector<vector<int>> stacks(n + 1);
    vector<int> base(n + 1, INT_MAX);
    int i = 0, cur = 0, first = 0;
    for (i; i < arr.size(); ++i)
    {
        if (arr[i] < cur)
            break;
        int l = first, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
			if (base[mid] < arr[i])
				l = mid + 1;
			else
				r = mid;
        }
        
        if (stacks[l].empty())
        {
            base[l] = arr[i];
			stacks[l].push_back(arr[i]);
        }
        else
        {
            
            if (stacks[l].back() < arr[i])
            {
                first = l;
                if (l > 0)
                    cur = max(cur, base[l - 1]);
                while (!stacks[l].empty() && stacks[first].back() < arr[i])
                    cur = stacks[l].back(), stacks[l].pop_back();
            }
            
            stacks[l].push_back(arr[i]);
        }
    }

    write(i), putchar('\n');
    return 0;
}