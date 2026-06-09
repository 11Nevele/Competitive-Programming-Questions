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
#include <iomanip>
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
double slope(pair<double,double> a, pair<double, double> b)
{
    if (b.first == a.first)
        return INT_MAX;
    return (b.second - a.second) / (b.first - a.first);
}
double distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
int main()
{
    int n = read();
    vector<pair<double, double>> coords(n);
    for (auto& i : coords)
        cin >> i.first >> i.second;
    sort(coords.begin(), coords.end(), [](pair<double, double> a, pair<double, double> b) -> bool
        {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first < b.first; 
    });
    
    double ans = 0;
    for (int condition = 0; condition < 2; ++condition)
    {
        vector<int> s;
        for (int i = 0; i < n; ++i)
        {
            while (s.size() > 1)
            {
                int cur = s[s.size() - 1], pre = s[s.size() - 2];
                if ((slope(coords[cur], coords[pre]) > slope(coords[i], coords[cur])) == condition)
                    break;
                else
                    s.pop_back();
            }
            s.push_back(i);
        }
        for (int i = 1; i < s.size(); ++i)
        {
            ans += distance(coords[s[i]], coords[s[i - 1]]);
        }
    }
    cout << fixed << setprecision(2) <<ans << endl;
}
