#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool map[65][65];
int arr[4][2]{ {1,0},{0,1},{-1, 0}, {0,-1} };
bool c(int a, int b)
{
    return a > b;
}
int main()
{
    int t, m, n;
    cin >> t >> m >> n;
    vector<int> v;

    for(int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            char a;
            cin >> a;
            map[i][j] = (a == '.');
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (map[i][j])
            {
                queue<pair<int, int>> q;
                q.push({ i,j });
                map[i][j] = false;
                int cnt = 0;
                while (!q.empty())
                {
                    cnt++;
                    auto p = q.front();

                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int x = p.first + arr[i][0], y = p.second + arr[i][1];
                        if (x < m && x >= 0 && y < n && y >= 0 && map[x][y])
                        {
                            map[x][y] = false;
                            q.push({ x,y });
                        }
                    }
                }
                v.push_back(cnt);
            }
        }
    sort(v.begin(), v.end(), c);
    int i;
    for (i =0; i < v.size(); i++)
    {
        if (t - v[i] < 0)
        {
            break;
        }
        t -= v[i];
    }
    if (i == 1)
    {
        cout << i << " room, " << t << " square metre(s) left over" << endl;
    }
    else
        cout << i << " rooms, " << t << " square metre(s) left over" << endl;
}
