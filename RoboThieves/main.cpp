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
int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
int main()
{
    int n = redn(), m = redn();
    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<bool>> v(n, vector<bool>(m));
    int sr, sc;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = getchar();
            if (map[i][j] == 'S')
            {
                sr = i;
                sc = j;
            }
            else if (map[i][j] == 'W')
            {
                v[i][j] = true;
            }
        }
        getchar();
    }
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'C')
            {
                v[i][j] = true;
                for (int k = 0; k < 4; k++)
                {
                    int r = i, c = j;
                    while (map[r][c] != 'W')
                    {
                        if(map[r][c] == '.' || map[r][c] == 'S')
                            v[r][c] = true;
                        r += dir[k][0];
                        c += dir[k][1];
                    }
                }
                
            }
        }
    vector<vector<int>> ans(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    queue<int> qs;
    q.push({ sr,sc });
    qs.push(0);
    while (!q.empty())
    {
        int r = q.front().first, c = q.front().second;
        int step = qs.front();
        q.pop();
        qs.pop();
        if (v[r][c] || (ans[r][c] != -1  && step >= ans[r][c]))
            continue;
        ans[r][c] = step;
        if (map[r][c] == 'U' || map[r][c] == 'D' || map[r][c] == 'L' || map[r][c] == 'R')
        {
            switch (map[r][c])
            {
            case 'U':r -= 1;  break;
            case 'D':r += 1; break;
            case 'L':c -= 1; break;
            case 'R':c += 1; break;
            }
                q.push({ r,c }); qs.push(step);
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int tr = r + dir[i][0], tc = c + dir[i][1];
                q.push({ tr,tc });
                qs.push(step + 1);
                
        }
        
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '.')
            {
                cout << ans[i][j] << '\n';
            }
        }
    
}
