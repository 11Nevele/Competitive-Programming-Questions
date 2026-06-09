#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807

int st[11][11][1005][1005];
int R, C;
void init(std::vector<std::vector<int>> arr)
{
    
    R = arr.size(), C = arr[0].size();
    for(int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            st[0][0][i][j] = arr[i][j];
        }
    int curLength = 2;
    for (int t = 1; t <= 10; ++t)
    {
        int half = curLength / 2;
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
            {
                half = (i + half) >= R ? R - half - 1 : half;
                st[t][0][i][j] = min(st[t - 1][0][i][j], st[t - 1][0][i+half][j]);
            }
        curLength *= 2;
    }
    //for (int t = 1; t <= 10; ++t)
    //{
    //    int half = curLength / 2;
    //    for (int i = 0; i < R; ++i)
    //        for (int j = 0; j < C; ++j)
    //        {
    //            half = (j + half) >= C ? C - half - 1 : half;
    //            st[0][t][i][j] = min(st[0][t - 1][i][j], st[0][t - 1][i][j + half]);
    //        }
    //    curLength *= 2;
    //}
    for (int t = 0; t <= 10; ++t)
    {
        int l2 = 2;
        for (int y = 1; y <= 10; ++y)
        {
            int h2 = l2 / 2;
            for (int i = 0; i < R; ++i)
                for (int j = 0; j < C; ++j)
                {
                    int tmp = (j + h2) >= C ? C - h2 - 1 : h2;
                    st[t][y][i][j] = min(st[t][y - 1][i][j], st[t][y-1][i][j+tmp]);
                }
            l2 *= 2;
        }
    }
}

int query(int a, int b, int c, int d)
{
    int w = b - a + 1, h = d - c + 1;
    int t = log2(w), y = log2(h);
    int wDif = w - pow(2, t), hDif = h - pow(2, y);
    if (a + wDif >= R)
        wDif = R - a - 1;
    if (c + hDif >= C)
        hDif = C - c - 1;
    return min(min(st[t][y][a][c], st[t][y][a + wDif][c + hDif]),
        min(st[t][y][a + wDif][c], st[t][y][a][c + hDif]));

}

int main()
{
    //init({ {1, 2, 3}, {4,5,6},{7,8,9} });
    //cout << query(0, 1, 0, 1) << endl;
    //cout << query(1, 1, 0, 1) << endl;
    //cout << query(0, 0, 1, 1) << endl;
    return 0;
}