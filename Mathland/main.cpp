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
int dir[4][2]{ {1,0},{-1,0},{0,-1},{0,1} };
pair<int, int> rotate(int n, int r, int c)
{
    pair<int, int> t;
    t.first = n - c - 1;
    t.second = r;
    return t;
}
int main()
{
    int n = redn(), k = redn();
    vector<vector<char>> map(n, vector<char>(n));
    vector<vector<bool>> v(n, vector<bool>(n));
    int sr, sc;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = getchar();
            if (map[i][j] == 'E')
            {
                sr = i;
                sc = j;
            }
        }
        getchar();
    }
    queue<pair<int, int>> q;
    queue<int> qs;
    q.push({ sr,sc });
    qs.push(0);
    int ans = -1;
    while (!qs.empty())
    {
        int r = q.front().first, c = q.front().second, step = qs.front();
        q.pop();
        qs.pop();
        if (step != 0 && step % k == 0)
        {
            auto temp = rotate(n, r, c);
            r = temp.first;
            c = temp.second;
        }
        if (r < 0 || r >= n || c < 0 || c >= n || map[r][c] == 'W' || v[r][c])
        {
            continue;
        }
        v[r][c] = true;
        if (map[r][c] == 'X')
        {
            ans = step;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int tr = r + dir[i][0], tc = c + dir[i][1];
            q.push({ tr,tc });
            qs.push(step + 1);
        }
        //q.push({ r,c });
        //qs.push(step + 1);
    }
    if (false)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                putchar(map[i][j]);
            putchar('\n');
        }
    }
    cout << ans << endl;
}
