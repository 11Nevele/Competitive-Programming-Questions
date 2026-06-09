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
    int n, m;
    cin >> n >> m;
    stack<int> l;
    queue<int> r;

    int curRow = 0, ind = 1;
	vector<int> arr(n * m * 2);
    for (int& i : arr)
        i = read();
    for (int j = 0; j < m; ++j)
        l.push(ind++);
	for (int j = 0; j < m; ++j)
		r.push(ind++);
	for (int i = 0; i < n * m * 2; ++i)
	{
        int x = arr[i];
        if (!l.empty() && x == l.top())
            l.pop();
        else if (!r.empty() && x == r.front())
            r.pop();
        else
        {
            cout << "no" << endl;
            return 0;
        }
        if (l.empty() && r.empty())
        {
            for (int j = 0; j < m; ++j)
                l.push(ind++);
            for (int j = 0; j < m; ++j)
                r.push(ind++);
            curRow++;
        }
			

	}
	cout << "yes" << endl;
    return 0;
}