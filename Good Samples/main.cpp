#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long cur = 0;
    int level = 0;
    for (int i = 0; i < n; i++)
    {
        cur += n - i;
        if (cur + n - i - 1 > k)
        {
            level = i + 1;
            break;
        }
        if (cur == k)
        {
            level = i + 1;
            break;
        }
    }
    if (level == 0|| k < n)
    {
        cout << -1 << endl;
        return 0;
    }
    
    vector<int> ans(n);
    

    int t = k - cur;
    if (t > 0)
    {
        if (level  + 1 > m)
        {
            cout << -1 << endl;
            return 0;
        }
        int a = t / (level + 1), b = t % (level + 1);
        for (int i = b - 1, e = 0; i < n && e <= a; i += (level + 1), e++)
        {
            if (i < 0)
                continue;
            ans[i] = level + 1;
        }
        a = 0;
        for (int i = 0; i < n; i++)
        {
            if (!ans[i])
            {
                ans[i] = (a % level) + 1;
                a++;
            }
        }
    }
    else
    {
        if (level > m)
        {
            cout << -1 << endl;
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            ans[i] = level - (i % level);
        }
    }
        


    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << " ";

    cout << ans[n - 1] << endl;
}
