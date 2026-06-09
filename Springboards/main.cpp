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
#include <fstream>
using namespace std;
#define INT_MAX 1047483647
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
vector<int> bit(100005);//first cost, second index

int lowbit(int x) { return x & -x; }
int MinTo(int target)
{
    int mi = 0;
    while(target > 0)
    {
        mi = max(mi, bit[target]);
        target -= lowbit(target);
    }
    return mi;
}
void Change(int target, int value)
{
    while (target < bit.size())
    {
        if (value > bit[target])
        {
            bit[target] = value;
        }
        target += lowbit(target);
    }

}
class node
{
public:
    long long x, y, id;
};
vector<node> s, e, ss, ee;
vector<pair<long long, long long>> pe;
bool ComN(const node& a, const node& b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
bool ComY(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
bool ComX(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ifstream fin("boards.in");
    ofstream fout("boards.out");
    long long n, p;
    cin >> n >> p;
    s.resize(p), e.resize(p), pe.resize(p);
    for (int i = 0; i < p; ++i)
    {

        cin >> s[i].x >> s[i].y >> e[i].x >> e[i].y;
        
        s[i].id = i, e[i].id = i;
        pe[i] = { e[i].x, e[i].y };
    }
    ss = s, ee = e;
    sort(pe.begin(), pe.end(), ComX);
    sort(ss.begin(), ss.end(), ComN);
    sort(ee.begin(), ee.end(), ComN);
    int ind = 1;
    vector<int>v;
    v.push_back(-1);
    v.push_back(pe[0].first);
    for (int i = 0; i < p; ++i)
    {
        bool b = false;
        if (i != p - 1 && pe[i].first != pe[i + 1].first)
        {
            b = true;
            v.push_back(pe[i + 1].first);
        }
        pe[i].first = ind;
        if (b)++ind;
    }
    sort(pe.begin(), pe.end(), ComY);
    vector<long long> ans(p);
    long long a = 0;
    ind = 0;
    for (int i = 0; i < p; ++i)
    {
        while (ind < p && ee[ind].id != ss[i].id && ee[ind].y <= ss[i].y)
        {
            int t = ee[ind].id;
            Change(pe[ind].first, ans[t]);
            ++ind;
        }
        int target = upper_bound(v.begin(), v.end(), ss[i].x) - v.begin() - 1;
        int ma = MinTo(target);
        int t = ss[i].id;
        ans[t] = max(ans[t], ma + e[t].x + e[t].y - s[t].x - s[t].y);
        a = max(ans[t], a);
    }
    //fout << n * 2 - MinTo(upper_bound(v.begin(), v.end(), n) - v.begin() - 1) << endl;
    //cout << n << endl;
    cout << n * 2 - a << endl;
}
