#include <iostream>
#include <vector>
#include <queue>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<int> arr[100005];

bool bfs(int start, int target)
{
    queue<int> q;
    q.push(start);
    bool visited[100005];
    memset(visited, 0, sizeof(bool) * 100005);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < arr[node].size(); i++)
        {
            if (arr[node][i] == target)
                return true;
            if (!visited[arr[node][i]])
            {
                q.push(arr[node][i]);
                visited[arr[node][i]] = true;
            }
                
        }
    }
    return false;
}
int main()
{
    int n = redn(), m = redn();
    
    //cin >> n;
    for (int i = 0; i < m; i++)
    {
        int a = redn(), b = redn();
        arr[a].push_back(b);
        //arr[a].push_back(b);
    }
    int a = redn(), b = redn();
    if (bfs(a, b))
    {
        cout << "yes" << endl;
    }
    else if (bfs(b, a))
    {
        cout << "no" << endl;
    }
    else
        cout << "unknown" << endl;

}
