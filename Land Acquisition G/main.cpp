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
long double slope(double x1, double y1, double x2, double y2)
{
    return (y2 - y1)/(x2-x1);
}
double slope(pair<LL,LL>a,pair<LL,LL>b)
{
    return ((double)b.second - (double)a.second) / ((double)b.first - (double)a.first);
}
vector<LL> dp(100000, LL_MAX);
int main()
{
    int n = read();
    vector<pair<int,int>> arr(n);
    for (auto& i : arr)
        i.first = read(), i.second = read();
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int>b) -> bool
        {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        });
    int ind = 1;
    for (int i = 1; i < n; ++i)
        if (arr[i].second > arr[ind - 1].second)
            arr[ind++] = arr[i];
    arr.erase(arr.begin() + ind, arr.end());
    arr.push_back({ 0,0 });
    for (int i = arr.size() - 1; i > 0; --i)
        arr[i] = arr[i - 1];
    arr[0] = { 0,0 };
    arr.push_back({ 0,0 });

    ind = 0;
    dp[0] = 0;
    vector<pair<LL, LL>> s;
    //arr[j+1].first, dp[j]
    s.push_back({arr[1].first, 0});
    for (int i = 1; i < arr.size() - 1; ++i)
    {
        
        while (ind < s.size() - 1)
        {
            if (arr[i].second * s[ind].first + s[ind].second >= arr[i].second * s[ind + 1].first + s[ind + 1].second)
                ++ind;
            else
                break;
        }
        dp[i] = arr[i].second * s[ind].first + s[ind].second;
        if (i == arr.size() - 2)
        {
            cout << dp[i] << endl;
            break;
        }
            
        pair<LL, LL> newPair = { arr[i + 1].first, dp[i]};
        int temp = s.size() - 2;
        while (temp >= ind)
        {
            int cur = s.size() - 1, pre = s.size() - 2;
            if (slope(s[pre], s[cur]) <= slope(s[cur], newPair))
                s.pop_back();
            else
                break;
            temp = s.size()-2;
        }
        s.push_back(newPair);
    }
    //dp[i] = dp[j] - -arr[i].second * arr[i].first
    //b: dp[i]
    //y: dp[j] increasing
    //k: arr[i].second increasing
    //x: arr[j].first decreasing
}
