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
    LL t;
    int a;
    int b;
    bool operator <(const node& other) const
    {
        return t > other.t;
    }
};
LL GetTime(const vector<LL>& arr, const vector<LL>& s, int a, int b)
{
    LL t = (arr[b] - arr[a] - 1) / (s[a] + s[b]) + 1;
    if (a % 2)
        t *= 2;
    else
        t = t * 2 - 1;
    return t;
}
int main()
{
    int t = read();
    while (t--)
    {
        int n = read();
        vector<LL> arr(n), s(n);
        vector<LL> ans(n, 0);
        set<int> st;
        for (int i = 0; i < n; ++i)
            arr[i] = readLL();
        for (int i = 0; i < n; ++i)
            s[i] = read(), st.insert(i);
        priority_queue<node> q;
        
        for (int i = 0; i < n - 1; ++i)
        { 
            q.push({ GetTime(arr, s, i, i + 1), i, i + 1});
        }
        while (!q.empty())
        {
            node t = q.top();
            q.pop();
            if (ans[t.a] || ans[t.b])
                continue;
            ans[t.a] = ans[t.b] = t.t;
            st.erase(t.a), st.erase(t.b);
            auto it1 = st.lower_bound(t.a), it2 = st.upper_bound(t.b);
            if (it1 == st.begin() || it2 == st.end())
                continue;
            --it1;
            q.push({ GetTime(arr,s, *it1, *it2), *it1, *it2 });
        }

        for (int i = 0; i < n; ++i)
            write(ans[i]), putchar(' ');
        putchar('\n');
    }
    

    return 0;
}