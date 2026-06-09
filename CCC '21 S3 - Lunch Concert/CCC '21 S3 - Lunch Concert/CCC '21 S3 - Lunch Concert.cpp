#include <iostream>
#include<cmath>
using namespace std;
int p[1000];
int w[1000];
int d[1000];
int n, ma = 0, mi = 99999;
int GetTime(int index)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = (abs(p[i] - index) - d[i]) * w[i];
        if (temp > 0)
            ans += temp;
    }
    return ans;
}
int main()
{
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        
        cin >> p[i] >> w[i] >> d[i];
        if (p[i] > ma)
        {
            ma = p[i];
        }
         if (p[i] < mi)
        {
            mi = p[i];
        }
    }
    int m;
    while (ma > mi)
    {
        m = (ma + mi) / 2;
        long miTime = GetTime(mi), maTime = GetTime(ma);
        if (maTime < miTime)
        {
            mi = m;
        }
        else if(maTime > miTime)
        {
            ma = m;
        }
        else
        {
            break;
        }
    }
    cout << GetTime(ma);

}
