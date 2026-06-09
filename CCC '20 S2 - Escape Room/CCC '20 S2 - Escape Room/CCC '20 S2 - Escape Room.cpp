#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
bool arr[1010][1010];
int v[1010][1010];
unordered_map <int, vector<pair<int, int>>> map;
class Node
{
public :
    int x;
    int y;
    Node(int a, int b)
    {
        this->x = a;
        this->y = b;
    }
};
queue <pair<int, int>> l;
int main()
{
    int m, n;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            v[i][j] = a;
            map[a].push_back({ i, j });
        }
    }
    l.push({m,n});
    arr[m][n] = true;;
    do
    {
        if (arr[1][1])
        {
            cout << "yes" << endl;
            return 0;
        }
        auto p = l.front();
        l.pop();
        int value = p.first*p.second;
        for (int i = 0; i < map[value].size(); i++)
        {
            auto t = map[value][i];
            if (!arr[t.first][t.second])
            {
                arr[t.first][t.second] = true;
                l.push(t);
            }
        }
    } while (!l.empty());
    cout << "no" << endl;
    return 0;
}

