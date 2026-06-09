#include <iostream>
#include <string>
#include <queue>
using namespace std;
char map[105][105];
string str;
int arr[8][2]{ 1,1,1,-1,-1,-1,-1,1,1,0,0,-1,-1,0,0,1 };
int find(int r, int c, int i, int j, bool td)
{
    int ans = 0;
    int rr = r + arr[j][0];
    int cc = c + arr[j][1];
    if (rr >= 0 && cc >= 0 && map[rr][cc] == str[i])
    {
        if (i != str.size() - 1)
            ans += find(rr, cc, i + 1, j, td);
        else
        {
            ans++;
        }
            
    }
    if (!td)
    {
        int t;
        if (j < 4)
        {
            t = (j + 1) % 4;
        }
        else if (j + 1 > 7)
            t = 4;
        else
            t = j + 1;
        rr = r + arr[t][0];
        cc = c + arr[t][1];
        if (rr >= 0 && cc >= 0 && map[rr][cc] == str[i])
        {
            if (i != str.size() - 1)
                ans += find(rr, cc, i +1 , t, true);
            else
                ans++;
            
        }
    }
    if (!td)
    {
        int t;
        if (j < 4)
        {
            if (j - 1 < 0)
                 t = 3;
            else
                t = j -1;
        }
        else if (j - 1 < 4)
            t = 7;
        else
            t= j - 1;
        rr = r + arr[t][0];
        cc = c + arr[t][1];
        if (rr >= 0 && cc >= 0 && map[rr][cc] == str[i])
        {
            if (i != str.size() - 1)
                ans += find(rr, cc, i + 1, t, true);
            else
                ans++;
        }
    }
    return ans;
}
int main()
{
    
    cin >> str;
    int r, c;
    long ans = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> map[i][j];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(map[i][j] == str[0])
            for (int k = 0; k < 8; k++)
            {
                int rr = i + arr[k][0];
                int cc = j + arr[k][1];
                if (rr >= 0 && cc >= 0 && map[rr][cc] == str[1])
                {
                    if (str.size() > 2)
                        ans += find(rr, cc, 2, k, false);
                    else
                        ans++;
                }
            }
        }
    }
    cout << ans;
}
