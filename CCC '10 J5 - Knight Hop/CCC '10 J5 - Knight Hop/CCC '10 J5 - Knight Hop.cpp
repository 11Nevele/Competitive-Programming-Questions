#include <iostream>
#include <list>
using namespace std;
bool arr[9][9];
int dir[8][2]{ {1,2},{2,1},{-1, 2}, {-2, 1},{1,-2},{2,-1},{-1, -2}, {-2, -1} };
class Node
{
    public:
    int x;
    int y;
    int level;
    Node(int a, int b)
    {
        this->x = a;
        this->y = b;
    }
    Node(){}
    bool operator == (Node n)
    {
        if (this->x == n.x && this->y == n.y)
            return true;
        else
            return false;
    }
};
int main()
{
    Node a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    a.level = 0;
    list <Node> l;
    l.push_back(a);
    while (!l.empty())
    {
        Node node = l.front();
        if (node == b)
        {
            cout << node.level << endl;
            break;
        }
        arr[node.x][node.y] = true;
        l.pop_front();
        
        for (int i = 0; i < 8; i++)
        {
            Node t(node.x + dir[i][0], node.y + dir[i][1]);
            t.level = node.level + 1;
            if (!arr[t.x][t.y] && t.x > 0 && t.x< 9 && t.y > 0 && t.y < 9)
            {
                l.push_back(t);
            }
        }

    }
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
