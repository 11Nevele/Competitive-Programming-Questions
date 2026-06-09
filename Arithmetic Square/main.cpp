#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<vector<int>> grid(3, vector<int>(3));
vector<vector<bool>> boolGrid(3, vector<bool>(3));
bool valid()
{
    bool t = true;
    for (int i = 0; i < 3; i++)
    {
        if (boolGrid[i][2] && 2 * grid[i][1] - grid[i][0] != grid[i][2])
        {
            t = false;
            break;
        }
        if (boolGrid[2][i] && 2 * grid[1][i] - grid[0][i] != grid[2][i])
        {
            t = false;
            break;
        }
    }
    return t;
}
int main()
{
    for(int i  = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            string str;
            cin >> str;
            if (str != "X")
            {
                boolGrid[i][j] = true;
                grid[i][j] = stoi(str);
            }
        }
    bool dif = true;
    while (dif)
    {
        dif = false;
        for (int i = 0; i < 3; i++)
        {
            if (boolGrid[i][0] && boolGrid[i][1] && !boolGrid[i][2])
            {
                dif = true;
                boolGrid[i][2] = true;
                grid[i][2] = grid[i][1] * 2 - grid[i][0];
            }
            else if (boolGrid[i][1] && boolGrid[i][2] && !boolGrid[i][0])
            {
                dif = true;
                boolGrid[i][0] = true;
                grid[i][0] = grid[i][1] * 2 - grid[i][2];
            }
            else if (boolGrid[i][0] && boolGrid[i][2] && !boolGrid[i][1])
            {
                dif = true;
                boolGrid[i][1] = true;
                grid[i][1] = (grid[i][2] + grid[i][0]) / 2;
            }
            if (boolGrid[0][i] && boolGrid[1][i] &&!boolGrid[2][i])
            {
                dif = true;
                boolGrid[2][i] = true;
                grid[2][i] = grid[1][i] * 2 - grid[0][i];
            }
            else if (boolGrid[1][i] && boolGrid[2][i] && !boolGrid[0][i])
            {
                dif = true;
                boolGrid[0][i] = true;
                grid[0][i] = grid[1][i] * 2 - grid[2][i];
            }
            else if (boolGrid[0][i] && boolGrid[2][i] && !boolGrid[1][i])
            {
                dif = true;
                boolGrid[1][i] = true;
                grid[1][i] = (grid[2][i] + grid[0][i]) / 2;
            }
        }
    }
    while (!valid())
    {
        grid[0][1] = rand() % 1000;
        boolGrid[0][1] = true;
        dif = true;
        while (dif)
        {
            dif = false;
            for (int i = 0; i < 3; i++)
            {
                if (boolGrid[i][0] && boolGrid[i][1] && !boolGrid[i][2])
                {
                    dif = true;
                    boolGrid[i][2] = true;
                    grid[i][2] = grid[i][1] * 2 - grid[i][0];
                }
                else if (boolGrid[i][1] && boolGrid[i][2] && !boolGrid[i][0])
                {
                    dif = true;
                    boolGrid[i][0] = true;
                    grid[i][0] = grid[i][1] * 2 - grid[i][2];
                }
                else if (boolGrid[i][0] && boolGrid[i][2] && !boolGrid[i][1])
                {
                    dif = true;
                    boolGrid[i][1] = true;
                    grid[i][1] = (grid[i][2] + grid[i][0]) / 2;
                }
                if (boolGrid[0][i] && boolGrid[1][i] && !boolGrid[2][i])
                {
                    dif = true;
                    boolGrid[2][i] = true;
                    grid[2][i] = grid[1][i] * 2 - grid[0][i];
                }
                else if (boolGrid[1][i] && boolGrid[2][i] && !boolGrid[0][i])
                {
                    dif = true;
                    boolGrid[0][i] = true;
                    grid[0][i] = grid[1][i] * 2 - grid[2][i];
                }
                else if (boolGrid[0][i] && boolGrid[2][i] && !boolGrid[1][i])
                {
                    dif = true;
                    boolGrid[1][i] = true;
                    grid[1][i] = (grid[2][i] + grid[0][i]) / 2;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << grid[i][0] << " " << grid[i][1] << " " << grid[i][2] << endl;
    }
    
}
