// 527飞跃原野.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
class Node
{
public:
    int x;
    int y;
    int step;
};
class ddata
{
public:
    char x;
    char y;
};
int arr[8][2]{ {1,0},{0,1},{-1, 0}, {0, -1},{1,1 },{-1,-1},{1,-1},{-1,1} };
ddata map[130][130]{0};

int n, m;
bool hit(int tx, int ty)
{
    //map[tx][ty] = '.';
    for (int i = 0; i < 8; i++)
    {
        int xx = tx;
        int yy = ty;
        while (xx <= n && yy <= m && xx > 0 && yy > 0 && map[xx][yy].x != '.')
        {
            map[xx][yy].x = '.';
            xx += arr[i][0];
            yy += arr[i][1];
        }
    }
    return false;
}
int main()
{
    
    cin >> n >> m;
    int x1, y1, x2, y2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j].x;
            map[i][j].y = map[i][j].x;
        }
    }
    bool a;
    while (true)
    {
        queue <Node> line;
        bool find = false;
        cin >> x2 >> y2 >> x1 >> y1;
        if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
            break;
        hit(x2, y2);
        line.push({ x1, y1, 0 });
        a = false;
        while (!line.empty())
        {
            Node temp = line.front();
            line.pop();
            for (int i = 0; i < 4; i++)
            {
                if (map[temp.x][temp.y].x == '.')
                {
                    cout << temp.step << endl;
                    find = true;
                    a = true;
                    break;
                }
                int xx = temp.x + arr[i][0];
                int yy = temp.y + arr[i][1];
                if (map[xx][yy] .x== 'O' || map[xx][yy] .x== '.')
                {
                    line.push({ xx, yy, temp.step + 1 });
                }
            }
            map[temp.x][temp.y] .x= 'X';
            if (a)
            {
                break;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                map[i][j].x = map[i][j].y;
        if (!find)
        {
            cout << "Impossible!" << endl;
        }
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
