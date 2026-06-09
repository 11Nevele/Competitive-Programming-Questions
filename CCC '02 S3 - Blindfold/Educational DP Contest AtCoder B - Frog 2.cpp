#include <iostream>
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
char map[400][100];
char input[30005];
int t, n, m;
int dirArr[4][2]{ {1,0},{0,-1},{-1,0},{0,1} };
bool search(int i, int j)
{
    int ci = i, cj = j;
    int dirI = 1, dirJ = 0;
    int index;
    for (int k = 0; k < 4; k++)
    {
        i = ci;
        j = cj;
        index = k;
        bool valid = true;
        if (map[i][j] == 'X' || i < 1 || i > n || j < 1 || j > m)
            continue;
        for (int x = 0; x < t; x++)
        {
            dirI = dirArr[index][0];
            dirJ = dirArr[index][1];
            
                
            switch (input[x])
            {
            case 'F': 
                i += dirI;
                j += dirJ;
                break;
            case 'L':
                index--;
                break;
            case 'R':
                index++;
                break;
            }
            index = index % 4;
            if (index < 0)
                index = 3;
            if (map[i][j] == 'X' || i < 1 || i > n || j < 1 || j > m)
            {
                valid = false;
                break;
            }
        }
        if(valid)
            map[i][j] = '*';
    }
    
    
    return true;
}
int main()
{
    n = redn(), m = redn();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            map[i][j] = getchar();
            //getchar();
        }
        getchar();
    }
        
            
    t = redn();
    for (int i = 0; i < t; i++)
    {
        input[i] = getchar();
        getchar();
    }
        
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            search(i, j);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            putchar(map[i][j]);
        }
        putchar(map[i][m]);
        putchar('\n');
    }
        
}
