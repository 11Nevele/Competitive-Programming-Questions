#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<LL> psa(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> psa[i];
           psa[i] += psa[i - 1];
        }
            
        int x = (n >> 1) - 1;
        LL e = 0;
        
        for (int s = x, r = n; s >= 0; --s, --r)
        {
            e = max(e, psa[s] + psa[n] - psa[r]);
        }
        cout << psa[n] - e << " " << e << endl;

    }
    return 0;
}