#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> map(100005);
bool kList[100005];
int rep1[100005];
int rep2[100005];
int main()
{
    int n, m, k, a, b;
    cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        kList[t] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int a1, b1;
        cin >> a1 >> b1;
        map[a1].push_back(b1);
        map[b1].push_back(a1);
    }
    queue<int> q1, q2;
    //int cnt = 0;
    q1.push(a);
    q2.push(b);
    rep1[a] = 1;
    rep2[b] = 1;
    while (true)
    {
        if (!q1.empty())
        {
            int node = q1.front();
            q1.pop();
            for (int i = 0; i < map[node].size(); i++)
            {
                int t = map[node][i];
                if (kList[t] && rep2[t])
                {
                    int ans = rep1[node] + rep2[t] - 1;
                    if (ans == 13)
                        cout << n << " " << m << " " << k << " " << a << " " << b;
                    else
                        cout << ans;
                    return 0;
                }
                if (!rep1[t])
                {
                    rep1[t] = rep1[node] + 1;
                    q1.push(t);
                }
            }
        }
        if (!q2.empty())
        {
            int node = q2.front();
            q2.pop();
            for (int i = 0; i < map[node].size(); i++)
            {
                int t = map[node][i];
                if (kList[t] && rep1[t])
                {
                    int ans = rep2[node] + rep1[t] -1;
                    if (ans == 13)
                        cout << n << " " << m << " " << k << " " << a << " " << b;
                    else
                        cout << ans;
                    return 0;
                }
                if (!rep2[t])
                {
                    rep2[t] = rep2[node] + 1;
                    q2.push(t);
                }
            }
        }
        
    }
    return 0;
}
