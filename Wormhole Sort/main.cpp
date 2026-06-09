#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 2147483647
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
class Hole
{
public:
    int a;
    int b;
    int w;
    Hole() {};
    Hole(int na, int nb, int nc)
    {
        a = na;
        b = na;
        w = nc;
    }
};


void swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}
int dfs(vector<int>& arr, const vector<Hole>& h, int cnt, int target, int mi)
{
    if (cnt == target)
    {
        return mi;
    }
    bool b = true;
    int ma = -1;
    for (auto& hole : h)
    {
        if (arr[hole.a] == hole.b || arr[hole.b] == hole.a)
        {
            int ncnt = cnt;
            if (arr[hole.a] == hole.b && arr[hole.b] == hole.a)
                ncnt += 2;
            else
                ncnt += 1;
            swap(arr[hole.a], arr[hole.b]);
            int nmi = min(mi, hole.w);
            ma = max(ma, dfs(arr, h, ncnt, target, nmi));
        }
    }
    if (b)
    {
        return -1;
    }
    return ma;

}
int main()
{
    int n = redn(), m = redn();
    vector<int> arr(n + 1);
    vector<Hole> h(m);
    int cnt = 0;
    for (int i = 1; i <=n; i++)
    {
        arr[i] = redn();
        if (arr[i] == i)
            cnt++;
    }
    for (auto& i : h)
    {
        i.a = redn();
        i.b = redn();
        i.w = redn();
    }
    int ans = dfs(arr, h, cnt, n, INT_MAX);
    if (cnt == n)
        cout << -1 << endl;
    else
    cout << ans << endl;
}
