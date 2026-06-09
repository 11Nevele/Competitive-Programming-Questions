#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[5];
int main()
{
    for (int i = 0; i < 4; i++)
    {
        bool a = false;
        for (int j = 0; j < 4; j++)
        {
            int t;
            cin >> t;
            if (t && j >= i)
            {
                if (a)
                {
                    cout << "NO" << endl;
                    return 0;
                }
                else
                    a = true;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
