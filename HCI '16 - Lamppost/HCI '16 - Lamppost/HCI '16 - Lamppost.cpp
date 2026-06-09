#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int c, n;
    cin >> c >> n;
    vector<int> v(c+1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a]++;
        v[b]++;
    }
    int mx = 0, mxi = 0;
    for (int i = c; i >= 1; i--)
    {
        if (mx < v[i]) {
            mx = v[i];
            mxi = i;
        }
    }
    cout << mxi << endl;
}
