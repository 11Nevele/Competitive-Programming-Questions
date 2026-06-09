// Island Perimeter.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
public:
    int x;
    int y;
    void operator = (Node t)
    {
        x = t.x;
        y = t.y;
    }
};
int dir[4][2]{ {1,0},{0,1},{-1,0},{0,-1} };
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<Node>q;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            bool a = false;
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    a = true;

                    q.push({ i,j });
                    break;
                }

            }
            if (a)
                break;
        }
        while (!q.empty())
        {
            Node temp = q.front();
            for (int i = 0; i < 4; i++)
            {
                
                int xx = temp.x;
                int yy = temp.y;
                xx += dir[i][0];
                yy += dir[i][1];
                if (xx < 0 || yy < 0 || xx > grid.size() - 1 || yy > grid[0].size() - 1)
                    ans++;
                else if (grid[xx][yy] == 0)
                    ans++;
                else if (grid[xx][yy] == 1)
                {
                    q.push({ xx, yy });
                    grid[xx] [yy] = 2;
                }
            }
            grid[temp.x][temp.y] = 2;
            q.pop();
        }
        return ans;
    }
int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
    cout << islandPerimeter(v) << endl;
    return 0;
}
