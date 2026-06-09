#include <iostream>
#include <vector>
#include <string>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<int> rcp(3);
vector<int> amt(3);
vector<int> price(3);
long long money;
long long GetPrice(long long amount)
{
    long long b = amount * rcp[0] - amt[0], s = amount * rcp[1] - amt[1], c = amount * rcp[2] - amt[2];
    b = b > 0 ? b : 0;
    c = c > 0 ? c : 0;
    s = s > 0 ? s : 0;
    return (b * price[0] + s * price[1] + c * price[2]);
}
long long last()
{
    long long l = 0, r = money + amt[0] + amt[1] + amt[2];
    while (l < r)
    {
        long long mid = (l + r + 1) / 2;
        long long p = GetPrice(mid);
        if (p <= money)
        {
            l = mid;
        }
        else if (p > money)
        {
            r = mid - 1;
        }
            
    }
    return l;
}
int main()
{
    string str;
    cin >> str;
    for (char s : str)
    {
        switch (s)
        {
        case 'B': ++rcp[0]; break;
        case 'S': ++rcp[1]; break;
        case 'C': ++rcp[2]; break;
        }
    }
    for (int& i : amt)
        i = redn();
    for (int& i : price)
        i = redn();
    cin >> money;
    cout << last() << endl;
}
