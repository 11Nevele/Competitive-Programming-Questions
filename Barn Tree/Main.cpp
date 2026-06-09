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
vector<int> adj[200005];
int arr[200005];
bool visited[200005];
int main()
{
    int n = redn();
    long long avg = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = redn();
        avg += arr[i];
    }
    avg /= n;
    for (int i = 0; i < n - 1; i++)
    {
        int a = redn(), b = redn();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i] - avg;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < adj[i].size(); i++)
        {

        }
    }

}
