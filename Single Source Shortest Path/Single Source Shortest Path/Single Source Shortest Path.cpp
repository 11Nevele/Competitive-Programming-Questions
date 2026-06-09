#include <iostream>
#include<vector>
#include <queue>
using namespace std;
vector<vector<pair<int,int>>> v(1005);
int arr[1005];
int main()
{
    int n, m;
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        v[a].push_back({ b, k });
        v[b].push_back({a, k});
    }
    for (int i = 2; i <= n; i++)
        arr[i] = -1;
    queue <int> q;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < v[node].size(); i++)
        {
            int t = v[node][i].first, value = v[node][i].second;
            if (arr[t] == -1 || arr[node] + value < arr[t])
            {
                arr[t] = arr[node] + value;
                q.push(t);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << '\n';
    }
}
