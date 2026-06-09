#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
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
int arr[34] = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
long ans[34];
int main()
{
    int a= read(), b = read(), n = read();
    
    for (int i = 0; i < n; i++)
    {
        arr[i + 14] = read();
    }
    n += 14;
    sort(arr, arr + n);
    ans[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] - arr[j] >= a && arr[i] - arr[j] <= b) {
                ans[i] += ans[j];
            }
            else if (arr[i] - arr[j] > b) {
                break;
            }
        }
    }
    write(ans[n - 1]);
    return 0;
}
