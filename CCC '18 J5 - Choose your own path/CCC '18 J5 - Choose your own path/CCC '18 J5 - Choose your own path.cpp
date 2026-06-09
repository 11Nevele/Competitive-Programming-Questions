#include <stdio.h>
#include <string.h>
char buf[1 << 23], * p1 = buf, * p2 = buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read()
{
    int s = 0;
    char ch = getchar(), last = 0;
    while (ch < '0' || ch >'9') last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return last == '-' ? -s : s;
}
int num[100];
inline void write(int x)
{
    if (x < 0) putchar('-'), x = -x;
    int len = 0;
    do num[len++] = x % 10; while (x /= 10);
    while (len--) putchar(num[len] + '0');
}
#include <queue>
#define MAX 999999
using namespace std;
int adj[10005][1000];
int recarr[10005];
int totalPage = 1;
int main()
{
    int n = read(), ans = MAX;
    for (int i = 1; i <= n; i++)
    {
        int m = read();
        for (int j = 0; j < m; j++)
        {
            adj[i][j] = read();
        }
    }
    queue<int> q, s;
    recarr[1] = true;
    q.push(1); s.push(1);
    while (!q.empty())
    {
        int node = q.front(), step = s.front();
        q.pop(); s.pop();
        if (adj[node][0])
            for (int i = 0; adj[node][i]; i++)
            {
                if (recarr[adj[node][i]])
                    continue;
                recarr[adj[node][i]] = true;
                q.push(adj[node][i]); s.push(step + 1);
                totalPage++;
            }
        else
            ans = ans < step ? ans : step;
    }
    char c = totalPage == n ? 'Y' : 'N';
    putchar(c); putchar('\n');
    write(ans);
    return 0;
}
