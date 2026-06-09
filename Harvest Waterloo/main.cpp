#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}

long long ans = 0;
int r, c;
int dir[4][2]{ {1,0},{0,1},{-1,0},{0,-1} };
void f(vector<vector<bool>>& v, vector<vector<char>>& map, int rr, int cc)
{
    if (rr < 0 || rr >= r || cc < 0 || cc >= c || map[rr][cc] == '*' || v[rr][cc])
        return;
    v[rr][cc] = true;
    switch (map[rr][cc])
    {
    case 'L': ans += 10; break;
    case 'M': ans += 5; break;
    case 'S': ans += 1; break;
    default:
        break;
    }
    for (int i = 0; i < 4; i++)
    {
        int tr = rr + dir[i][0], tc = cc + dir[i][1];
        f(v, map, tr, tc);
    }
}
int main()
{
    r = redn(), c = redn();
    vector<vector<bool>> v(r, vector<bool>(c));
    
    vector<vector<char>> map(r, vector<char>(c));
    for (auto& i : map)
    {
        for (auto& j : i)
            j = getchar();
        getchar();
    }
    int sr = redn(), sc = redn();
    f(v, map, sr, sc);
    cout << ans << endl;

    
}
