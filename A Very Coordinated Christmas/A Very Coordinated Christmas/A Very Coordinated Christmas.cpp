#include <iostream>
#include <queue>
using namespace std;
bool map[1005][1005];
bool map2[1005][1005];
int arr[4][2]{ {1,0},{0,1},{-1,0},{0,-1} };
int n, m;
class Node
{
public:
    int x;
    int y;
    int count;
    bool operator ==(Node n)
    {
        return this->x == n.x && this->y == n.y;
    }
    void operator =(Node n)
    {
        x = n.x;
        y = n.y;
        count = n.count;
    }
    Node() {}
    Node(int nx, int ny, int nc)
    {
        x = nx;
        y = ny;
        count = nc;
    }
    Node(int nx, int ny)
    {
        x = nx;
        y = ny;
    }
};
int BFS(Node start, Node end)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            map2[i][j] = map[i][j];
    queue<Node> q;
    q.push(start);
    map2[start.x][start.y] = false;
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = node.x + arr[i][0], y = node.y + arr[i][1];
            if (Node(x, y) == end)
                return node.count + 1;
            if (map2[x][y] && x >= 0 && x < m && y >= 0 && y < n)
            {
                map2[x][y] = false;
                q.push(Node(x, y, node.count + 1));
            }
        }
    }
    return -1;
}
int main()
{
    
    cin >> m >> n;
    Node start, present, end;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char t;
            cin >> t;
            map[i][j] = true;
            switch (t)
            {
            case 'O': start = *new Node(i, j, 0); break;
            case 'P': present = *new Node(i, j, 0); break;
            case 'X': end = *new Node(i, j); break;
            case'#': map[i][j] = false; break;
            }
        }
    }
    int r1 = BFS(start, present);
    if (r1 == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    int r2 = BFS(present, end);
    if (r2 == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << r1 + r2 << endl;
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
