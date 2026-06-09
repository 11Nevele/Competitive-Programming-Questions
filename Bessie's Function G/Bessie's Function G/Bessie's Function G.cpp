#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
vector<vector<int>> adj2(MAXN);
vector<long long> c(MAXN);
vector<int> adj1(MAXN);
vector<vector<long long>> dp(MAXN, vector<long long>(2));
vector<vector<long long>> dp1(MAXN, vector<long long>(2));
vector<int> v(MAXN);

int loopPoint(int x, int s)
{
    if (v[x] == s)
        return x;
    if (v[x] != 0 && v[x] != s)
        return -1;
    v[x] = s;
    return loopPoint(adj1[x], s);
}

void getCost(int x, int no)
{
    if(adj1[x] != x)
        dp[x][1] += c[x];
    for (int i : adj2[x])
        if (i != no)
        {
            getCost(i, no);
            dp[x][1] += min(dp[i][0], dp[i][1]);
            dp[x][0] += dp[i][1];
        }
            
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        adj1[i] =t;
        adj2[t].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    long long res = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t = loopPoint(i, i);
        if (t == -1)
            continue;

        vector<int> arr;
        arr.push_back(t);
        int x = adj1[t];
        while (x != t)
        {
            getCost(x, arr.back());
            arr.push_back(x);
            x = adj1[x];
        }
        getCost(x, arr.back());
        
        long long sum = 0;
        vector<vector<long long>> ans(arr.size(), vector<long long>(2));
        ans[arr.size() - 1][1] = dp[arr.back()][1];
        ans[arr.size() - 1][0] = dp[arr.back()][1];
        for (int i = arr.size() - 2; i >= 0; --i)
        {
            int x = arr[i];
            ans[i][0] = dp[x][0] + ans[i + 1][1];
            ans[i][1] = dp[x][1] + min(ans[i + 1][0], ans[i + 1][1]);
        }
        sum = min(ans[0][0], ans[0][1]);

        if (arr.size() > 1)
        {
            ans[arr.size() - 2][1] = dp[arr[arr.size() - 2]][1];
            ans[arr.size() - 2][0] = dp[arr[arr.size() - 2]][1];
            for (int i = arr.size() - 3; i >= 0; --i)
            {
                int x = arr[i];
                ans[i][0] = dp[x][0] + ans[i + 1][1];
                ans[i][1] = dp[x][1] + min(ans[i + 1][0], ans[i + 1][1]);
            }
            ans[arr.size() - 1][0] = dp[arr.back()][0] + ans[0][1];
            ans[arr.size() - 1][1] = dp[arr.back()][1] + min(ans[0][0], ans[0][1]);
            sum = min(sum, min(ans.back()[0], ans.back()[1]));
        }

        res += sum;
        


    }
    cout << res << endl;

}