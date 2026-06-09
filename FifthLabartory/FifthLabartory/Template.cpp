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
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
double dis(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main()
{
    double tx, ty, tz ;
	cin >> tx >> ty >> tz;
    int n = read();
    double mn = INT_MAX;
    while (n--)
    {
        double x, y, z;
		cin >> x >> y >> z;
        if (z > tz)
        {
            double gt = abs(tz - z) / 4, gd = gt * 3;
            mn = min(mn, gt + max(0.0 , sqrt(pow(tx - x, 2) + pow(ty - y, 2)) - gd) / 2);

        }
        else
        {
            mn = min(mn, dis(x, tx,y,ty) / 2 + abs(tz - z));
        }
    }
    cout  << mn << endl;
}