#include <iostream>
#include <vector>
#include <queue>
#define DIF 1000
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<vector<bool>> map(3000, vector<bool>(3000)), addMap(3000, vector<bool>(3000));
int dir[4][2]{ {1,0},{-1,0},{0,1},{0,-1} };
int dir2[5][2]{ {1,0},{-1,0},{0,1},{0,-1},{0,0} };
int GetCount(int &r, int &c)
{
    int cnt = 0;
    int ar = 0, ac = 0;
    for (auto& t : dir)
    {
        int tr = t[0] + r, tc = t[1] + c;
        if (map[tr][tc] || addMap[tr][tc])
            cnt++;
        else
        {
            ar = tr;
            ac = tc;
        }
    }
    if (cnt == 3)
    {
        r = ar;
        c = ac;
    }
    return cnt;
}
int main()
{
    int q = redn();
    int cnt = 0;
    while (q--)
    {
        int r = redn(), c = redn();
        r += DIF; c += DIF;
        if (addMap[r][c])
        {
            addMap[r][c] = false;
            cnt--;
            
        }
        map[r][c] = true;
        queue<pair<int, int>>q;
        q.push({ r,c });

        while (!q.empty())
        {
            int tr = q.front().first, tc = q.front().second;
            q.pop();
            for (auto& t : dir2)
            {
                int ttr = t[0] + tr, ttc = t[1] + tc;
                if (map[ttr][ttc] || addMap[ttr][ttc])
                {
                    if (GetCount(ttr, ttc) == 3)
                    {
                        addMap[ttr][ttc] = true;
                        cnt++;
                        q.push({ ttr,ttc });
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}
