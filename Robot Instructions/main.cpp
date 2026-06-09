#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<short>dp(2000000001);
vector<short>step(41);

int main()
{
    cout << sizeof(dp);
    int n = redn();
    int tx = redn(), ty = redn();
    vector<int> arrX(n + 1), arrY(n + 1);
    for (int i = 1; i <= n; i++)
    {
        arrX[i] = redn();
        arrY[i] = redn();
    }


}
