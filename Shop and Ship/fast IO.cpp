#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <queue>
#include <cstring>
#include <ctype.h>
#include <iostream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<pair<int, int>> adj[5005];
vector<pair<int, int>> shop(5000);
long long visited[5005];
queue<int> q;
int main()
{
    std::ios::sync_with_stdio(false);
    memset(visited, 1, sizeof(long long) * 5005);
    int n = redn(), t = redn(), k, d;
    for (int i = 0; i < t; i++)
    {
        int a = redn(), b = redn(), c = redn();
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    k = redn();
    for (int i = 0; i < k; i++)
    {
        shop[i].first = redn(), shop[i].second = redn();
        q.push(shop[i].first);
        visited[shop[i].first] = shop[i].second;
    }
    d = redn();
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (visited[node] + adj[node][i].second < visited[adj[node][i].first])
            {
                visited[adj[node][i].first] = visited[node] + adj[node][i].second;
                q.push(adj[node][i].first);
            }
        }
    }

    cout << visited[d] << '\n';

}