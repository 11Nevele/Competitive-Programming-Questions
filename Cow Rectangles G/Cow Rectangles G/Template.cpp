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
inline long long readLL()
{
    long long ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

class cow
{
public:
    int x;
    int y;
    int id;

    bool operator < (const cow& other)
    {
        return x < other.x;
    }
};

bool comY(const cow& a, const cow& b)
{
    if (a.y == b.y)
        return a.id < b.id;
    return a.y < b.y;
}
int length(int l, int r)
{
    return max(l - r, 0);
}
int main()
{


    int n = read();
    vector<cow> arrY(n);
    for (int i  =0; i < n; ++i)
        arrY[i].x = read(), arrY[i].y = read(), arrY[i].id = (getchar() == 'H');
    sort(arrY.begin(), arrY.end(), comY);
    vector<cow> arrX = arrY;
    for (int i = 0; i < n; ++i)
        arrX[i].id = i;
    sort(arrX.begin(), arrX.end());
    arrX.push_back({ -1,-1,0 });
    arrY.push_back({ -1,-1,0 });
    int l = 0, r = 0;
    int mx = 0, area = INT_MAX;
    while (l < n)
    {
        vector<bool> v(n + 1);

        r = l;
        while (r < n)
        {
            while (r < n && arrX[r].x == arrX[r + 1].x)
                v[arrX[r].id] = true, ++r;
            v[arrX[r].id] = true;
            int cnt = 0, s = 0, e = 0;
            for (int j = 0; j < n;)
            {
                bool hasG = false;
                int curY = arrY[j].y, t = 0;
                while (j < n && arrY[j].y == curY)
                {
                    if (v[j])
                        hasG |= !(arrY[j].id), ++t;
                    ++j;
                }
                if (hasG)
                {
                    if (cnt > mx)
                        mx = cnt, area = (length(arrX[r].x, arrX[l].x)) * (length(e, s));
                    else if (cnt == mx)
                        area = min(area, (length(arrX[r].x, arrX[l].x)) * (length(e, s)));
                    cnt = 0;
                }
                else if(t != 0)
                {
                    if (cnt == 0)
                        cnt = t, s = curY, e = curY;
                    else
                        cnt += t, e  = curY;
                }
            }
            if (cnt > 0)
            {
                if (cnt > mx)
                    mx = cnt, area = (length(arrX[r].x, arrX[l].x)) * (length(e, s));
                else if (cnt == mx)
                    area = min(area, (length(arrX[r].x, arrX[l].x)) * (length(e, s)));
            }
            ++r;
        }

        
        while (l < n && arrX[l].x == arrX[l + 1].x)
            ++l;
        l++;
    }
    write(mx), putchar('\n');
    write(max(0,area)), putchar('\n');
    return 0;
}