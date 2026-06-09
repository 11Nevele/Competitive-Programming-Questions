#include <iostream>
#include <vector>

using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<int> arr(1000005);
int main()
{
    ios_base::sync_with_stdio(false);
    int n = redn();
    int min = 20000000;
    int max = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        int t = redn();
        arr[t]++;
        min = t < min ? t : min;
        max = t > max ? t : max;
    }
    s = arr[min] == 1 ? min + 1 : min;
    for (int i = s; i <= max; i++)
    {
        cout << i << " ";
    }
    for (int i = max; i >= min; i--)
    {
        while (arr[i] > 1)
        {
            arr[i]--;
            cout << i << " ";
        }
    }
    return 0;
        
}
