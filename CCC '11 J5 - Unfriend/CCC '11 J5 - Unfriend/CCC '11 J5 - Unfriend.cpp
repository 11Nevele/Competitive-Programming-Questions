#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[10];
int dfs(int x)
{
    if (adj[x].size() == 0)
        return 1;
    int tot = 1;
    for (int i : adj[x])
        tot *= dfs(i) + 1;
    return tot;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
	}
    cout << dfs(n) << endl;
}
