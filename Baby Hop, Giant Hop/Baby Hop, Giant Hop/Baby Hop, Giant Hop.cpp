#include <iostream>
#include <cmath>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long a, b;
    cin >> a >> b;
    long long dif = abs(a - b);
    long long k;
    cin >> k;
    vector<long long> ans(4);
    
    long long jump = dif / k;
    ans[0] = dif / k + abs(dif - (jump) * k);
    //if (dif % k != 0)
    //{
        ans[1] = (jump + 1) + abs(dif - (jump + 1) * k);
    //}
    //else
    //{
        ans[2] = abs(jump - 1) + abs(dif - (jump - 1) *k);
        ans[3] = min(ans[0], ans[1]) + 2;
    //}
    
    sort(ans.begin(), ans.end());
    int t;
    std::cin >> t;
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if (t == 1)
        cout << ans[0] << endl;
    
    else
    {
        cout << ans[1] << endl;
    }
}
