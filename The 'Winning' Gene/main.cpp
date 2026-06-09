#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <string_view>
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
string_view com(string_view a, string_view b)
{
    int ind = 0;
    while (ind < a.size() &&a[ind] == b[ind])
        ++ind;
    if (ind >= a.size())
        return a;
    return a[ind] < b[ind] ? a : b;
}
int main()
{
    int n = read();
    vector<vector<int>> minPos(n);
    string str;
    cin >> str;
    for (int i = 1; i <= str.size(); ++i)
    {
        string minStr = "ZZZ";
        for (int j = 0; j < str.size() - i; j++)
        {
            string tempStr = str.substr(j, i);
            minStr = min(minStr, tempStr);
        }
        for (int j = 0; j < str.size() - i; j++)
        {
            string tempStr = str.substr(j, i);
            if (tempStr == minStr)
            {
                minPos[i].push_back(j);
            }
        }
    }
    vector<int> cntArr(str.size() + 1);
    for (int i = 1; i < str.size(); ++i)//k
    {
        
        for (int j = 1; j <= i; ++j)//l
        {
            int cnt = n - i + 1;
            int ind = 0;
            auto& arr = minPos[j];
            for (int t : arr)
            {
                int e = t + i - 1, s = t + j - i;
                if (e >= str.size()) e = str.size() - 1;
                if (s < 0) s = 0;
                if (t > e)
                    continue;
                s = max(ind, s);
                cnt -= (e - s + 1) - i ;
                ind = t + 1;
            }
            cntArr[cnt]++;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << cntArr[i] << "\n";
}
