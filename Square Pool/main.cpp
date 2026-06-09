#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
bool rcom(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}
bool ccom(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}
int main()
{
    int n = redn(), t = redn();
    vector<pair<int, int>> a(t + 2), b;
    a[0] = { 0,0 };
    for (int i = 1; i <= t; i++)
    {
        a[i].first = redn();
        a[i].second = redn();
    }
    a[t + 1] = { n + 1, n + 1 };
    b = a;
    sort(a.begin(), a.end(), rcom);
    sort(b.begin(), b.end(), ccom);
    int ans = 0;
    for(int k = 0; k <= t; k++)
    for (int i = k + 1; i <= t + 1; i++)
    {
        pair<int,int> l = a[k], r = a[i];
        int d = r.first - l.first - 1, ma = 0, preInd = 0;
        for (int j = 1; j <= t; j++)
        {
            auto tt = b[j];
            if (tt.first < r.first && tt.first > l.first)
            {
                ma = max(ma, tt.second - preInd - 1);
                preInd = tt.second;
            }
        }
        ma = max(ma, n + 1 - preInd - 1);
        ans = max(ans, min(d, ma));
    }
    cout << ans << endl;
}
