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
class CMP
{
public:
    bool operator ()(const pair<double, double>& a, const pair<double, double>& b)
    {
        return (a.first + 1) / (a.second + 1) - (a.first / a.second) < (b.first + 1) / (b.second + 1) - (b.first / b.second);
    }
};

int main()
{
    int n = read(), k = read();
    vector<pair<double, double>> grades(n);
    for (auto& i : grades)
        i.first = read();
    for (auto& i : grades)
        i.second = read();
    priority_queue<pair<double, double>, vector<pair<double,double>>, CMP> s;
    for (auto& i : grades)
        s.push(i);
    while (k--)
    {
        auto t = s.top();
        s.pop();
        s.push({ t.first + 1, t.second + 1 });

    }
    double tot = 0;
    while (!s.empty())
    {
        auto t = s.top();
        s.pop();
        tot += t.first / t.second;
    }
    cout << fixed << tot / n * 100 << endl;
    return 0;
}