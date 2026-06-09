#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<int> arr;
vector<vector<int>> ans(5005, vector<int>(5005));
int dif(int l, int r)
{
    if (l == r)
    {
        ans[l][r] = 0;
        return 0;
    }
        
    if (l + 1 == r)
    {
        ans[l][r] = abs(arr[l] - arr[r]);
        return ans[l][r];
    }
    ans[l][r] = abs(arr[l] - arr[r]) + dif(l + 1, r - 1);
    return ans[l][r];
}
int main()
{
    int n = redn();
    arr.resize(n);
    for (int& i : arr)
        i = redn();
    for (int i = 0; i < n; i++)
    {
        dif(0, i);
        dif(i, n - 1);
    }
    cout << "0";
    for (int i = 1; i < n; i++)
    {
        cout << " ";
        int mi = 2147483647;
        for (int j = 0; j + i < n; j++)
        {
            mi = min(mi, ans[j][j + i]);
        }
        cout << mi;
    }
    
    cout << endl;
}
