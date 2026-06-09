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



void GetDepth(const vector<vector<int>>& adj, vector<vector<int>>& depth, int x, int l)
{
    depth[l].push_back(x);
    for (int i : adj[x])
        GetDepth(adj, depth, i, l + 1);
}
vector<vector<int>> adj, depth;
vector<int> parent1, parent2;
vector<bool> destroyed;
vector <vector<bool>>dp;
int main()
{
    int t = read();
    while (t--)
    {
        int n1 = read();
        adj.clear(), depth.clear(), parent1.clear(), parent2.clear(), destroyed.clear(),dp.clear();
        adj.resize(n1 + 1), depth.resize(n1 + 1), parent1.resize(n1 + 1), parent2.resize(n1 + 1), destroyed.resize(n1 + 1, true);
        dp.resize(n1 + 1, vector<bool>(n1 + 1));
        
        int root = 1;
        for (int i = 1; i < n1; ++i)
        {
            int a = read(), b = read();
            parent1[a] = b;
            adj[b].push_back(a);
        }
        
        
        int n2 = read();
        for (int i = 1; i < n2; ++i)
        {
            int a = read(), b = read();
            destroyed[a] = false;
            destroyed[b] = false;
            parent2[a] = b;
        }
        while (parent1[root]) ++root;
        GetDepth(adj, depth, root, 0);

        for (int d = n1; d > 0; --d)
        {
            sort(depth[d].begin(), depth[d].end());

            for (int i = 0; i < ((int)depth[d].size()); ++i)
            {
                int a = depth[d][i];
                if (!destroyed[a])
                {
                    dp[a][a] = true;
                    continue;
                }
                
                for (int j = i; j < depth[d].size(); ++j)
                {
                    int b = depth[d][j];
                    if (destroyed[b])
                        continue;
                    dp[a][b] = true;
                    
                    for (int t1 : adj[a])
                    {
                        bool found = false;
                        for (int t2 = 1; t2 <= n1; t2++) {
                            if (parent2[t2] == b && dp[t1][t2]) {
                                found = true;
                                break;
                            }
                        }
                        dp[a][b] = dp[a][b] & found;
                    }

                }
            }
        }

        
        vector<pair<int, int>> ans;
        vector<int> r(n1 + 1);
        r[root] = root;
        write(n1 - n2), putchar('\n');
        for (int d = 0; d < n1; ++d)
        {
            for (int i = 0; i < ((int)depth[d].size()); ++i)
            {
                int a = depth[d][i];
                for (int j = 0; j < depth[d].size(); ++j)
                {
                    int b = depth[d][j];
                    if (dp[a][b] && r[parent1[a]] == parent2[b])
                    {
                        r[a] = b;
                    }   
                }
                if (r[a] != a)
                    write(a), putchar(' '), write(r[a]), putchar('\n');
            }
                
        }
        
        //fout << ans.size() << endl;
        
    }
    return 0;
}