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
class com
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

void ShortestPath(const vector<int>& arr, vector<LL>& dis, LL mx)
{
    priority_queue<LL, vector<LL>, greater<LL>> q;
    fill(dis.begin(), dis.end(), LL_MAX);
    vector<bool> visited(500005);
    q.push(0);
    dis[0] = 0;
    while (!q.empty())
    {
        LL x = q.top();
        q.pop();
        if (visited[x % arr[0]])
            continue;
        visited[x % arr[0]] = true;
        for (int i = 1; i < arr.size(); ++i)
        {
            LL t = x + arr[i];
            if (t > mx || dis[t % arr[0]] <= t)
                continue;
            dis[t % arr[0]] = t;
            q.push(t);
        }
    }
}
int main()
{
    int n = read();
    LL l = readLL(), r = readLL();
    vector<int> arr(n);
    vector<LL> ans(500005);
    for (auto& i : arr)
        i = read();
    ShortestPath(arr, ans, r);
    LL cnt = 0;
    for (int i = 0; i < arr[0]; ++i)
    {
        if (ans[i] == LL_MAX)
            continue;
        if(ans[i] >= l)
            cnt += (r - ans[i]) / arr[0] + 1;
        else
        {
            cnt += (r - ans[i]) / arr[0] - (l - ans[i] - 1) / arr[0];
        }
    }
    write(cnt);
    putchar('\n');
}
//7 13
//4
//4 7 10 13
//4
