#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int n = redn();
    vector<int> arr(n);
    for (int& i : arr)
        i = redn();
    long long ans = 0;
    for (int k = 0; k < 2; k++)
    {
        stack<int> s,s2;
        for (int i = 0; i < n; i++)
        {
                while (!s.empty() && s.top() < arr[i])
                {
                    ans += (i - s2.top() + 1);
                    s2.pop();
                    s.pop();
                }
            s.push(arr[i]);
            s2.push(i);
        }
        reverse(arr.begin(), arr.end());
    }
    cout << ans << endl;
}
