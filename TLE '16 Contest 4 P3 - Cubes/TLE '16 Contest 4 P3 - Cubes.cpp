#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, u[105], v[105];
vector<int> perm = { 1, 2, 3, 4, 5, 6, 7, 8 };
vector<pair<int, int>> edges = { {1,2}, {2,3}, {3,4}, {4,1}, {5,6}, {6,7}, {7,8}, {8,5}, {1,5}, {2,6}, {3,7}, {4,8} };
bool adj[9][9];
bool check() 
{
    for (int i = 0; i < 12; i++) 
    {
        int x = perm[edges[i].first - 1], y = perm[edges[i].second - 1];
        if (!adj[x][y])  return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    
   
    do {
        if (check()) {
            cout << "Ja\n";
            return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << "Nej\n";
    return 0;
}