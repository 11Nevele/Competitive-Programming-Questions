#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int b(vector<int>& a, int s, int t)
{
    int preS = -1, preT = -1;
    int ans = 9999999;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == s)
        {
            preS = i;
            if(preT != -1)
            {
                int tt = abs(preS - preT);
                ans = ans < tt ? ans : tt;
            }
            
        }
        else if (a[i] == t)
        {
            preT = i;
            if (preS != -1)
            {
                int tt = abs(preS - preT);
                ans = ans < tt ? ans : tt;
            }
            
        }
       
    }
    return ans;
}
int main()
{
    int t = redn();
    while (t--)
    {
        int n = redn(), m = redn();
        int cnt = 0;
        vector<int> v(n + 1);
        vector<int>* adj = new vector<int> [n + 1];
        for (int j = 0; j < m; j++)
        {
            int a = redn(), b = redn();
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!v[i])
            {
                queue<int> q;
                q.push(i);
                cnt++;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    v[node] = cnt;
                    for (int j : adj[node])
                    {
                        if (!v[j])
                            q.push(j);
                    }
                }
            }
        }
        vector<int> ans(cnt + 1);
        for (int j = 0; j < 2; j++)
        {
            int target;
            if (j == 0)
                target = 1;
            else
                target = v[n];
            for (int i = 2; i < cnt; i++)
            {
                ans[i] += pow(b(v, target, i), 2);
            }
        }
        int min = 1000000000;
        for (int i = 2; i < cnt; i++)
        {
            min = min < ans[i] ? min : ans[i];
        }

        int tt = pow(b(v, 1, v[n]), 2);
        if(min != 0) 
            tt = (min < tt) ? min : tt;
        cout << tt << "\n";
    }
}
