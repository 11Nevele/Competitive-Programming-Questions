#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <queue>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    vector<int>temp(n), arr(n);
    unordered_map<int, queue<int>> map;
    for (int i = 0; i < n; i++)
    {
        fin >> temp[i];
        map[temp[i]].push(i);
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++)
    {
        arr[map[temp[i]].front()] = i;
        map[temp[i]].pop();
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, i - arr[i]);
    }
    cout << ans + 1 << endl;
    fout << ans + 1 << endl;

}
