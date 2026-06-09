#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807

int n,q;
vector<vector<int>> mp(1005, vector<int>(1005, -1));
//1 visited, 2 loop, 3 out
vector<vector<int>> ending(1005, vector<int>(1005,2));
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool isOut(int r, int c)
{
    if (mp[r][c] == -1)
        return true;
    int nr = r + dir[mp[r][c]][0], nc = c + dir[mp[r][c]][1];
    if (nr == 0 || nc == 0 || nr > n || nc > n)
        return true;
    return false;
}

void dfs(int r, int c, int &ans)
{
    if (r == 0 || c == 0 || r > n || c > n)
        return;
    ending[r][c] = 3;
    --ans;
    for (int i = 0; i < 4; ++i)
    {
        int t1 = r + dir[i][0], t2 = c + dir[i][1];
        int t = mp[t1][t2];
        if (ending[t1][t2] == 2 && (t == -1 || t1 + dir[t][0] == r && t2 + dir[t][1] == c))
            dfs(t1, t2, ans);

    }
}

int main()
{
    cin >> n >> q;
    vector<pair<int, int>> change(q);
    for (int i = 0; i < q; ++i)
    {
        int r, c;
        char t;
        cin >> r >> c;
        cin >> t;
        change[i] = { r,c };
        if (t == 'D')
            mp[r][c] = 0;
        else if(t == 'U')
            mp[r][c] = 1;
        else if (t == 'R')
            mp[r][c] = 2;
        else if (t == 'L')
            mp[r][c] = 3;
    }
    
    for (int i = 1; i <= n; ++i)
    {
        if (isOut(1, i))ending[1][i] = 1;
        if (isOut(i, 1))ending[i][1] = 1;
        if (isOut(n, i))ending[n][i] = 1;
        if (isOut(i, n)) ending[i][n] = 1;
    }

    int ans = n * n;
    for (int r = 1; r <= n; ++r)
        for (int c = 1; c <= n; ++c)
        {
            if (ending[r][c] == 1)
                dfs(r, c, ans);
        }
    vector<int> res;
    res.push_back(ans);
    for (int t = q - 1; t >= 0; -- t)
    {
        int r = change[t].first, c = change[t].second;
        mp[r][c] = -1;
        if (ending[r][c] == 3)
        {
            res.push_back(ans);
            continue;
        }
        for (int i = 0; i < 4; ++i)
        {
            int t1 = r + dir[i][0], t2 = c + dir[i][1];
            if (t1 == 0 || t2 == 0 || t1 > n || t2 > n)
                ending[r][c] = 3;
            ending[r][c] = max(ending[r][c], ending[t1][t2]);
        }
        if (ending[r][c] == 3)
            dfs(r, c, ans);
        res.push_back(ans);

    }
    for (int i = res.size() - 2; i >= 0; --i)
        cout << res[i] << endl;
    return 0;
}
