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
    vector<int> a(n), b(n), cnt1(4), cnt2(4);
	for (int i = 0; i < n; i++)
	{
		a[i] = getchar() - 'A';
	}
    getchar();
    for (int i = 0; i < n; i++)
    {
		b[i] = getchar() - 'A';
    }
    for (int i = 0; i < 4; ++i)
        cnt2[i] = read();
    int ans = 0;
    int tot = 0;
	for (int i = 0; i < n; i++)
	{
        if(b[i] >= 0)
			cnt2[b[i]]--;
		if (a[i] == b[i])
		{
			ans++;
		}
		else if(b[i] < 0)
		{
			cnt1[a[i]]++;
            ++tot;
		}
	}
    
    /*for (int i = 0; i < 4; ++i)
    {
        int cnt = 0;
        while(cnt2[i] > 0 && cnt < 3)
        {
            ++cnt;
            int mx = -INT_MAX, ind = -1;
            for (int j = 0; j < 4; ++j)
            {
                if (i == j)
                    continue;
                if(cnt1[j] != 0 && cnt2[j] - cnt1[j] > mx)
				{
					mx = cnt2[j] - cnt1[j];
					ind = j;
				}
            }
            int tmp = min(cnt2[i], cnt1[ind]);
            cnt2[i] -= tmp;
            cnt1[ind] -= tmp;
        }
        
        if(cnt2[i] > 0)
			ans += cnt2[i];
    }*/
	for (int i = 0; i < 4; ++i)
	{
		ans += max(0, cnt1[i] + cnt2[i] - tot);
	}
	write(ans), putchar('\n');

    return 0;
}