#include <iostream>
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int arr[105];
bool visited[100005];
int main()
{
    int n = redn();
    for (int i = 0; i < n; i++)
        arr[i] = redn();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            
        }
    }
}
