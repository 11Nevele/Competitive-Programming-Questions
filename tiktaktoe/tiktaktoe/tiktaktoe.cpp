#include <iostream>
using namespace std;


/*
go in the middle

player's turn
if check if player have two pieces in one row or column and there is a empty space in that row or column
    go in the empty space
else if have empty conner space
    go in the conner
else
    go in any remainning space

go to palyer's turn
*/



int grid[3][3];

void output()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == 0)
            {
                putchar('.'), putchar(' ');
            }
            else if (grid[i][j] == 1)
            {
                putchar('x'), putchar(' ');
            }
            else if (grid[i][j] == 2)
            {
                putchar('o'), putchar(' ');
            }
        }
        putchar('\n');
    }
}

void PlayerTurn()
{
    int r = -1, c = -1;
    while (r < 0 || r > 2 || c < 0 || c > 2 || grid[r][c])
    {
        cout << "Player Turn: ";
        cin >> r >> c;
    }
    grid[r][c] = 2;
}

pair<int, int> checkWin()
{
    for (int i = 0; i < 3; ++i)
    {
        int hPlayerCnt = 0, vPlayerCnt = 0;
        int hEmpty = -1, vEmpty = -1;
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == 0)
                hEmpty = j;
            else if (grid[i][j] == 2)
                hPlayerCnt++;
            if (grid[j][i] == 0)
                vEmpty = j;
            else if (grid[j][i] == 2)
                vPlayerCnt++;
        }
        if (hPlayerCnt == 2 && hEmpty != -1)
            return { i, hEmpty };
        if (vPlayerCnt == 2 && vEmpty != -1)
            return {vEmpty, i};
    }

    return { -1,-1 };
}
int order[8][2]{ {0,0},{0,2},{2,0},{2,2},{0,1},{1,0},{1,2},{2,1} };
void MachineTurn()
{
    cout << "Machine Turn\n";
    pair<int, int> res = checkWin();
    if (res.first != -1)
    {
        grid[res.first][res.second] = 1;
        return;
    }
        
    for (int i = 0; i < 8; ++i)
    {
        int r = order[i][0], c = order[i][1];
        if (!grid[r][c])
        {
            grid[r][c] = 1;
            break;
        }
    }
}


int main()
{
    grid[1][1] = 1;
    output();
    int stepCnt = 1;
    while (stepCnt < 9)
    {
        if (stepCnt % 2)
            PlayerTurn();
        else
            MachineTurn();
        ++stepCnt;
        output();
    }

}
