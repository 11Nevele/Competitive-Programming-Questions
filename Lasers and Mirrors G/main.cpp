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

unordered_map<int, vector<int>> h, v;
int main()
{
    int n = read();
    vector<pair<int,int>> arr(n + 2);
    pair<int, int> s, e;
    s.first = read(), s.second = read(), e.first = read(), e.second = read();
    arr[0] = s, arr[n + 1] = e;
    h[e.second].push_back(n + 1);
    v[e.first].push_back( n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x = read(), y = read();
        arr[i] = { x,y };
        h[y].push_back(i);
        v[x].push_back(i);
    }
    queue<int> qID, qHV, qStep;
    vector<vector<bool>> visited(n + 2, vector<bool>(2));
    visited[0][0] = visited[0][1] = true;
    //0 for horizontal, 1 for verticle
    qID.push(0), qID.push(0), qHV.push(0), qHV.push(1), qStep.push(0), qStep.push(0);

    while (!qID.empty())
    {
        int id = qID.front(), hv = qHV.front(), step = qStep.front();
        qID.pop(), qHV.pop(), qStep.pop();

        pair<int, int> coord = arr[id];
        if (hv == 0)
        {
            for (int i : v[coord.first])
            {
                if (i == id || visited[i][1])
                    continue;
                if (i == n + 1)
                {
                    cout << step << endl;
                    return 0;
                }
                visited[i][1] = true;
                qID.push(i), qHV.push(1), qStep.push(step + 1);
            }
        }
        else
        {
            for (int i : h[coord.second])
            {
                if (i == id || visited[i][0])
                    continue;
                if (i == n + 1)
                {
                    cout << step << endl;
                    return 0;
                }
                visited[i][0] = true;
                qID.push(i), qHV.push(0), qStep.push(step + 1);
            }
        }
    }
    cout << -1 << endl;
}
