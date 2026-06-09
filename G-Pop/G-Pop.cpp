#include <iostream>
#include <unordered_map>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int arr[500005];
unordered_map<int, bool> map;
int main()
{
    std::ios::sync_with_stdio(0);
    int n = redn(), q =redn(), max = 1;
    for (int i = 1; i <= n; i++)
        arr[i] = 1;
    while (q--)
    {
        int l = redn(), r = redn();
        map.clear();
        for (int i = l; i <= r; i++)
        {
            if (map.find(arr[i]) == map.end())
            {
                map[arr[i]] = true;
            }
            else
            {
                while (map.find(arr[i]) != map.end())
                    arr[i]++;
                max = max > arr[i] ? max : arr[i];
            }
        }
    }
    cout << max << endl;
    for (int i = 1; i < n; i++)
        cout << arr[i] << ' ';
    cout << arr[n] << endl;
}
