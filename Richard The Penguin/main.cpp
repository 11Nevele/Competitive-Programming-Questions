#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int n, k;
vector<int> times(5005);
vector<int> v(5005);
int ans = 0;
int back(int x)
{
    vector<int> arr(x + 2);
    arr[x] = 1;
    for (int i = x - 1; i >= 1; i--)
    {
        if (v[i])
        {
            arr[i] = arr[i - 1];
            continue;

        }
            
        int a = i + 1, b = i + k + 1;
        if (b > x)
            b = x + 1;
        arr[i] = arr[a] + arr[a] - arr[b];
    }
    return arr[1] - arr[2];
}
int tt = 0;
void f(int x,int continueCnt)
{
    if (x > n)
        return;
    if (x == n)
    {
        
        int t  = back(x);
        ans += t;
        tt++;
        ans = ans % 998244353;
        return;
    }
    if (continueCnt == (k - 1))
        return;
    v[x] = true;
    f(x + 1, continueCnt + 1);
    for (int i = 2; i <= k; i++)
    {
        f(x + i, continueCnt);
    }
    v[x] = false;
}
int main()
{
    n = redn(), k = redn();
    for (int i = 2; i <= k + 1; i++)
        f(i, 0);
    cout << ans  << endl;
}
