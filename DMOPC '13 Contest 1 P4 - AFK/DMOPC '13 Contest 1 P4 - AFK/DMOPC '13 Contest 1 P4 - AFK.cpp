#include <iostream>
#include <queue>
using namespace std;
char map[55][55];
int arr[4][2]{ {1,0},{0,1},{-1,0}, {0,-1} };
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
    Node(){}
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
int main()
{
    int n, m, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        Node start, end;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'C')
                {
                    start = *new Node( i, j, 0 );
                    map[i][j] = 'X';
                }
                if (map[i][j] == 'W')
                {
                    end = *new Node(i, j, 0);
                }
                    
            }
        }
        queue<Node> l;
        l.push(start);
        int count = 0;
        bool a = false;
        while (!l.empty())
        {
            Node p = l.front();
            if (p.count == 60)
            {
                cout << "#notworth" << endl;
                break;
            }
            l.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = p.x + arr[i][0];
                int y = p.y + arr[i][1];
                if (Node(x, y) == end)
                {
                    cout << p.count+1 << endl;
                    a = true;
                    break;
                }
                if (map[x][y] == 'O' && x < m && y < n && x >= 0 && y >= 0)
                {
                    map[x][y] = 'X';
                    l.push(Node(x, y, p.count + 1));
                }
            }
            if (a)
                break;
        }

    }
}
