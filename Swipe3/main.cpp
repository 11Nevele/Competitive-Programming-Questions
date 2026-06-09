#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> a(n), b(n);
    for (int& i : a)
        i = redn();
    for (int& i : b)
        i = redn();
    
}
