#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<vector<int>> arr(9, vector<int>(9, 100000000));
int dir[8][2]{ {1,2},{2,1},{-1, 2}, {-2, 1},{1,-2},{2,-1},{-1, -2}, {-2, -1} };
int tx, ty;
void solve(int x, int y, int s)
{
    arr[x][y] = s;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dir[i][0], yy = y + dir[i][1];
        if (xx > 0 && xx <= 8 && yy > 0 && yy <= 8 && s < arr[xx][yy])
        {
            solve(xx, yy, s + 1);
        }   
    }
}
int main()
{
    int x = redn(), y = redn();
    tx = redn(), ty = redn();
    solve(x, y, 0);
    cout << arr[tx][ty] << endl;
}
