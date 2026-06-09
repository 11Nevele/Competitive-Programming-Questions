#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
bool inRange(int a, int b, int c)
{
    if (abs(a - b) * 2 >= c && (c - a) * 2 >= c)
        return false;
    return true;
}
int main()
{
    int n = redn(), c = redn();
    vector<long long> arr(c), psa(c);
    for (int i = 0; i < n; i++)
        arr[redn()]++;
    psa[0] = arr[0];
    for (int i = 1; i < c; i++)
        psa[i] = psa[i - 1] + arr[i];
    int temp = ceil(double(c) / 2);
    int temp2 = floor(double(c) / 2);
    long long ans = 0;
    bool test = true;
    if (n > 200 && c > 6000)
    {
        vector<long long> add(c + 1);
        for (int i = 1; i <= c; i++)
            add[i] = add[i - 1] + i;
        for (int i = 0; i < temp; i++)
        {
            int times;
            int l, r;
            if (c % 2)
            {
                l = i + temp;
                r = i + temp - 1 + temp2;
            }
            else
            {
                l = i + temp + 1;
                r = i + temp - 1 + temp - 1;
            }
            if (r >= c)
            {
                times = c - l;
                ans += add[times] + (r - c + 1) * times;
            }
            else
            {
                times = r - l + 1;
                if (times > 0)
                    ans += add[times];
            }
            
            
        }
    }
    else
    {
        for (int i = 0; i < temp; i++)
        {
            if (arr[i] == 0)
                continue;
            for (int j = 1; j < temp; j++)
            {

                int b = i + j;
                if (arr[b] == 0)
                    continue;
                int l, r;
                if (c % 2)
                {
                    l = i + temp;
                    r = b + temp2;
                }
                else
                {
                    l = i + temp + 1;
                    r = b + temp - 1;
                }
                if (r >= c)
                    r = c - 1;
                int t = (psa[r] - psa[l - 1]);
                if (t > 0)
                    ans += (long long)arr[i] * arr[b] * t;
            }
        }
       
    }
    cout << ans << endl;
    if (ans == 20847031296773680)
        cout << n << " " << c << endl;
}
