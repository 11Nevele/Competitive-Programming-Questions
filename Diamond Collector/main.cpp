#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int n, k;
    fin >> n >> k;
    vector<int> arr(n);
    vector<bool> v(n);
    for (int& i : arr)
        fin >> i;
    sort(arr.begin(), arr.end());
    int ind = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ind <= i)
            ind = i + 1;
        while (ind < n && arr[ind] - arr[i] <= k)
        {
            v[ind] = true;
            ind++;
        }
        if (ind - i > 1)
            v[i] = true;
    }
    for (bool i : v)
        if (i) ans++;
    cout << ans << endl;
    fout << ans << endl;
}
