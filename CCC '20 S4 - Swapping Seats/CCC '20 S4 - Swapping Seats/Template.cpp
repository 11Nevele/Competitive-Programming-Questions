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
vector<int> str;
int n;
vector<int> cnt(3);

int GetSwaps(vector<vector<int>> amt)
{
    int swaps = 0;
    swaps += amt[1][0];
    if (amt[1][0] > amt[0][1])
    {
        int t = (amt[1][0] - amt[0][1]);
        amt[1][2] += t;
        amt[0][2] -= t;
        amt[1][0] -= t;
        amt[0][0] += t;
    }
    amt[0][1] -= amt[1][0];
    amt[1][1] += amt[1][0];
    amt[0][0] += amt[1][0];
    amt[1][0] -= amt[1][0];
    
    
    
    swaps += amt[2][0];
    if (amt[2][0] > amt[0][2])
    {
        int t = (amt[2][0] - amt[0][2]);
        amt[2][1] += t;
        amt[0][1] -= t;
        amt[2][0] -= t;
        amt[0][0] += t;
    }
    amt[0][2] -= amt[2][0];
    amt[2][2] += amt[2][0];
    amt[0][0] += amt[2][0];
    amt[2][0] -= amt[2][0];

    swaps += amt[1][2];
    return swaps;
    
}
int Sequence(vector<int> arr)
{
    int first = 1;
    vector<vector<int>> amt(3, vector<int>(3));
    vector<int> indOf(3);
    for (int i = 0; i < 3; ++i)
        indOf[arr[i]] = i;
    for (int i = 1; i <= n; ++i)
    {       
        int cur = 0;
        for (int j = 0; j < 3; ++j)
        {
            cur += cnt[arr[j]];
            if (i <= cur)
            {
                amt[j][indOf[str[i]]]++;
                break;
            }
        }
    }
    int ans = GetSwaps(amt);
    for (int i = 2; i <= n; ++i)
    {
        int cur = 0;
        for (int j = 0; j < 3; ++j)
        {
            int oldInd = i + cur - 1;
            cur += cnt[arr[j]];
            int newInd = i + cur - 1;
            amt[j][indOf[str[oldInd]]]--;
            amt[j][indOf[str[newInd]]]++;
        }
        ans = min(ans, GetSwaps(amt));
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    n = s.size();
    str.resize(n * 2 + 5);
    for (int i = 1; i <= n; ++i)
    {
        str[i] = str[n + i] = s[i - 1] - 'A';
        cnt[str[i]]++;
    }
    int ans = INT_MAX;
    ans = min(ans, Sequence({ 0,1,2 }));
    ans = min(ans, Sequence({ 0,2,1 }));
    write(ans);
    putchar('\n');
    return 0;
}