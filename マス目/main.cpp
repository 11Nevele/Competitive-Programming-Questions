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
vector<vector<int>> trans(4096);
const int mod = 1e9 + 7;

int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
bool connect(const vector<vector<int>>& map, int sr, int sc, int x)
{
    vector<vector<bool>> v(map.size(), vector<bool>(map[0].size()));
    queue<pair<int, int>> q;
    q.push({ sr, sc });
    v[sr][sc] = true;
    while (!q.empty())
    {
        int r = q.front().first, c = q.front().second;
        for (auto& i : dir)
        {
            int nr = r + i[0], nc = c + i[1];
            if (nr < 0 || nc < 0 || nr > map.size() || nc > 1)
                continue;
            if (v[nr][nc] || map[nr][nc] != x) continue;
            if (nc == 0)
                return true;
            q.push({ nr,nc });
        }
    }
    return false;
}

bool valid(int x)
{
    bool haveOne = false;
    int preN = -1, pre = 0;
    while (x != 0)
    {
        int cur = x % 4;
        x /= 4;
        switch (cur)
        {
        case 0: break;
        case 1: 
            if (preN != 1) return false;
            if( pre != 1 || pre != 0)

        default:
            break;
        }
    }
}
int main()
{
    int n = read(), m = read();
    const int mx = pow(4, n);
    
    for(int i = 0; i < mx; ++i)
    

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int k = 0;)
}
