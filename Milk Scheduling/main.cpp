#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int main()
{
    ifstream fin("msched.in");
    ofstream fout("msched.out");
    int n, m;
    fin >> n >> m;
    vector<int> arr(n + 1);
    vector<long long> v(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++)
        fin >> arr[i];
    while (m--)
    {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for (int j : adj[t])
            {
                if (v[t] + arr[t] > v[j])
                {
                    v[j] = v[t] + arr[t];
                    ans = max(ans, v[j] + arr[j]);
                    q.push(j);
                }
            }
        }
    }
    fout << ans << endl;
    cout << ans << endl;
}
