#include <iostream>
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int x1 = redn(), y1 = redn(), x2 = redn(), y2 = redn(), n = redn();
    int distance = abs(x1 - x2) + abs(y1 - y2);
    if (distance > n || distance % 2 != n % 2)
    {
        std:: cout << "N\n";
    }
    else
    {
        std::cout << "Y\n";
    }
}
