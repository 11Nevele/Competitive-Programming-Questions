#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n, k;
vector <vector<int>> graph(100005);
vector <vector<long long>> dp(100005, vector<long long>(3, 1));


const int mod = 1000000007;
void dfs(int a, int p) {
    int l = graph[a].size();

    for (int i = 0; i < l; i++) 
    {
        if (graph[a][i] == p)
            continue;
        dfs(graph[a][i], a);
    }

    for (int i = 0; i < l; i++) 
    {
        if (graph[a][i] == p)
            continue;
        dp[a][0] = (dp[a][0] * (dp[graph[a][i]][1] + dp[graph[a][i]][2])) % mod;
        dp[a][1] = (dp[a][1] * (dp[graph[a][i]][2] + dp[graph[a][i]][0])) % mod;
        dp[a][2] = (dp[a][2] * (dp[graph[a][i]][0] + dp[graph[a][i]][1])) % mod;
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        y = y % 3;
        dp[x][y] = 1;
        dp[x][(y + 1) % 3] = 0;
        dp[x][(y + 2) % 3] = 0;
    }

    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1] + dp[1][2])%mod;
}