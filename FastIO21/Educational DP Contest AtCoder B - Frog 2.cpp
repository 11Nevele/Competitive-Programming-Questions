#include <iostream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int arr[2005][2005];
int main()
{
    int n = redn(), p = redn();
    long long max = n * n;
    int min = 1;
    arr[0][0] = max;
    max--;
    for (int j = 1; j < n; j++)
    {
        arr[j][0] = min;
        min++;
    }
    int t = (n - p);
    for (int j = 1; j < n; j++)
    {
        if(j <= t)
            arr[0][j] = max--;
        else
            arr[0][j] = min++;
    }
    for (int i = 1; i < n; i++)
    {
        arr[i][i] = max;
        max--;
        for (int j = i + 1; j < n; j++)
        {
            arr[j][i] = min;
            min++;
            arr[i][j] = min;
            min++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            write(arr[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}