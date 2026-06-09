#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<int> adj[100005];
int main()
{
    int n = redn();
    for (int i = 0; i < n - 1; i++)
    {
        int a = redn(), b = redn();
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    int ans = 0;
    for(int i = 1; i <=n; i++)
    {
        int s = adj[i].size();
        if (i != 1)
        {
            s--;
            if (s == 0) continue;
        }
        int t = ceil(log2(s));
        ans += t + s;
        if ((1 << t) - s == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
