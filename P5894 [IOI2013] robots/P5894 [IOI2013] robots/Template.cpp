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
class node
{
public:
    int x;
    int y;
    int id;
};

    bool cmpy(const node& a, const node& b)
    {
        if (a.y == b.y)
            return a.x > b.x;
        return a.y < b.y;
    }

    bool cmpx(const node& a, const node& b)
    {
        if (a.x == b.x)
            return a.y > b.y;
        return a.x < b.x;
    }
vector<int> A, B;
vector<node> ty, tx;
bool check(int target)
{
    int cnt = 0;
    vector<bool> v(tx.size());
    priority_queue < pair<int, int>> q;

    int ind = 0;
    for (int i : A)
    {
        while (ind < tx.size() && tx[ind].x < i)
            q.push({ tx[ind].y, tx[ind].id }), ++ind;
        for(int j = 0; j < target; ++j)
        {
            if (q.empty())
                break;
            auto t = q.top();
            q.pop();
            ++cnt;
            v[t.second] = true;
        }
        if (cnt == v.size())
            return true;
    }
    while (!q.empty())
        q.pop();
    ind = 0;
    for (int i : B)
    {
        while (ind < ty.size() && ty[ind].y < i)
        {
            
            if (!v[ty[ind].id])
                q.push({ ty[ind].x, ty[ind].id });
            ++ind;
        }
            
        for (int j = 0; j < target; ++j)
        {
            if (q.empty())
                break;
            auto t = q.top();
            q.pop();
            ++cnt;
            v[t.second] = true;
        }
        if (cnt == v.size())
            return true;
    }
    return false;
}
int main()
{
    int a = read(), b = read(), t = read();
    A.resize(a), B.resize(b);
    tx.resize(t), ty.resize(t);
    for (int& i : A)
        i = read();
    for (int &i : B)
        i = read();
    for (int i = 0; i < t; ++i)
        ty[i] = { read(), read(), i };
    tx = ty;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(tx.begin(), tx.end(), cmpx);
    sort(ty.begin(), ty.end(), cmpy);

    if (!check(t))
    {
        write(-1), putchar('\n');
        return 0;
    }

    int l = 1, r = t;
    while (l < r)
    {
        int mid = (l + r) / 2;
        bool valid = check(mid);
        if (valid)
            r = mid;
        else
            l = mid + 1;
    }

    write(l), putchar('\n');

    return 0;
}