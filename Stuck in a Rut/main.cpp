#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
class cow
{
public:
    int x;
    int y;
    int id;
    cow(int nid, int nx, int ny) { id = nid; x = nx; y = ny; }
};
bool hcompare(const cow& a, const cow& b) { return a.y < b.y; }
bool vcompare(const cow& a, const cow& b) { return a.x < b.x; }
vector<int> dp(1005);
vector<vector<int>> adj(1005);
int f(int i)
{
    if (dp[i] > 0)
        return dp[i];
    for (int id : adj[i])
    {
        dp[i] += f(id) + 1;
    }
    return dp[i];
}
int main() //first is x, second is y
{
    int n = redn();
    vector<cow> h, v;
    for (int i = 0; i < n; i++)
    {
        char t = getchar();
        int x = redn(), y = redn();
        if (t == 'E')
            h.push_back(cow(i+1, x, y));
        else
            v.push_back(cow(i + 1, x, y));
    }
    std::sort(h.begin(), h.end(), hcompare);
    std::sort(v.begin(), v.end(), vcompare);
    vector<bool> stop(n + 1);
    for (const auto& c1 : h)
    {
        for (const auto& c2 : v)
        {
            if (c1.x > c2.x || c2.y > c1.y)
                continue;
            if (stop[c1.id] || stop[c2.id])
                continue;
            int temp = (c2.x - c1.x) - (c1.y - c2.y);
            if (temp == 0)
                continue;
            else if (temp < 0)
            {
                adj[c1.id].push_back(c2.id);
                stop[c2.id] = true;
            }
            else
            {
                stop[c1.id] = true;
                adj[c2.id].push_back(c1.id);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << f(i) << endl;
    }
}
