#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<pair<int, int>> adj[5005];
vector<pair<int, int>> shop(5000);
long long visited[5005];
queue<int> q;
int main()
{
    cin.tie(NULL);
    memset(visited, 1, sizeof(long long) * 5005);
    int n, t, k, d;
    cin >> n >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &shop[i].first, &shop[i].second);
        q.push(shop[i].first);
        visited[shop[i].first] = shop[i].second;
    }
    cin >> d;
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

    std::cout << visited[d] << endl;

}