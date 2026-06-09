#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int x;
    long long d;
    bool operator < (const node& other) const
    {
        return d > other.d;
    }
};
void ShortestPath(const vector<vector<pair<int, long long>>>& adj, vector<long long>& dis,
    vector<int>& pre, const vector<int>& s)
{
    vector<bool> v(adj.size());
    priority_queue<node> q;
    for (int i : s)
        q.push({ i, 0 }), dis[i] = 0;
    while (!q.empty())
    {
        int x = q.top().x;
        long long d = q.top().d;
        q.pop();
        if (v[x])
            continue;
        v[x] = true;
        for (auto& t : adj[x])
        {
            int j = t.first;
            if (v[j])
                continue;
            long long w = t.second;
            if (d + w < dis[j])
            {
                pre[j] = x;
                dis[j] = d + w;
                q.push({ j, dis[j] });
            }
        }
    }
}
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b,w;
        cin >> a >> b >> w;
        adj[a].push_back({ b,w });
        //adj[b].push_back({ a,w });
    }
    vector<long long> dis(n + 1, 2147483647);
    vector<int> pre(n + 1);
    ShortestPath(adj, dis, pre, {s});
    for (int i = 1; i <= n; ++i)
        cout << dis[i] << " ";
    cout << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
