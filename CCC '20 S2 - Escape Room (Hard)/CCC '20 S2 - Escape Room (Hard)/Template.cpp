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
vector<vector<int>> adj(4000000);
vector<bool> v(4000005);
vector<int> pos(16000005, -1);
vector<bool> has(16000006);

constexpr bool contain(int i)
{

}

bool can_escape(int M, int N, vector<std::vector<int>> mp)
{
    int mx = max(M, N);
    for (int i = 1; i <= 4000; i += 1)
    {
        for (int j = i; j <= 4000; ++j)
        {
            has[i * j] = true;
        }
    }
    int ind = 0;
    for (int i = 0; i < 16000005; ++i)
        if (has[i])
            pos[i] = ind++;
    
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
        {
            if(pos[mp[i][j]] != -1)
                adj[pos[i * j]].push_back(pos[mp[i][j]]);
        }
            
    queue<int>q;
    v[pos[1]] = true;   
    if (pos[mp[1][1]] != -1)
    {
        q.push(pos[mp[1][1]]);
        v[pos[mp[1][1]]] = true;
    }
        
    while (!q.empty())
    {
        int value = q.front();
        q.pop();
        for (int t : adj[value])
        {
            if (t == pos[N * M])
                return true;

            if (!v[t])
            {
                v[t] = true;
                q.push(t);
            }
        }
        /*for (int i = 1; i * i <= value; ++i)
        {
            if (value % i)
                continue;
            int j = value / i;
            if (i <= M && j <= N)
            {
                int t = mp[i][j];
                if (t == N * M)
                    return true;
                if (!v[t])
                {
                    v[t] = true;
                    q.push(t);
                }
            }
            
            if (j <= M && i <= N)
            {
                int t = mp[j][i];
                if (t == N * M)
                    return true;
                if (!v[t])
                {
                    v[t] = true;
                    q.push(t);
                }
            }
            
        }
        */
    } 
    return false;
}

int main()
{
    int m = read(), n = read();
    vector<vector<int>> mp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            mp[i][j] = read();
    cout << can_escape(m, n, mp);
    

    return 0;
}
/*
4 3
3 10 8 1
1 11 12 12
6 2 3 9
*/