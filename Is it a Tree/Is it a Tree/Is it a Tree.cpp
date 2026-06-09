#include <iostream>
#include <vector>
#include <list>
using namespace std;
bool arr[4]{ 0,0,0,0 };

vector<vector<int>> v(4);
bool DFSUtil(int node, int parent)
{
    arr[node] = true;
    for (long unsigned int i = 0; i < v[node].size(); i++)
    {
        if (!arr[v[node][i]])
        {
            if (DFSUtil(v[node][i], node))
                return true;
        }
        else if (v[node][i] != parent)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int t;
            cin >> t;
            if (t)
            {
                v[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < 4; i++)
        if (!arr[i])
        {
            if (DFSUtil(i, -1))
            {
                cout << "No" << endl;
                return 0;
            }
        }
            
                

    cout << "Yes" << endl;
    return 0;
}
