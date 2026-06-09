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
struct rect
{
	int x1, y1, x2, y2;
    int t;
};
void AddPsa(vector < vector<LL>>& psa, rect & r)
{
	psa[r.x1][r.y1] += r.t;
	psa[r.x1][r.y2] -= r.t;
	psa[r.x2][r.y1] -= r.t;
	psa[r.x2][r.y2] += r.t;
}
int main()
{
    int n = read(), k = read();
    unordered_map<int, int> mpX, mpY;
    vector<int> pointX, pointY, xD(2005), yD(2005);
    vector<rect> rects(n);
	for (auto& i : rects)
	{
		i = { read(), read(), read(), read(), read() };
		pointX.push_back(i.x1);
		pointX.push_back(i.x2);
		pointY.push_back(i.y1);
		pointY.push_back(i.y2);
	}
	sort(pointX.begin(), pointX.end());
    sort(pointY.begin(), pointY.end());
	pointX.erase(unique(pointX.begin(), pointX.end()), pointX.end());
	pointY.erase(unique(pointY.begin(), pointY.end()), pointY.end());
	for (int i = 0; i < pointX.size(); i++)
		mpX[pointX[i]] = i + 1, xD[i + 1] = ((i + 1) < pointX.size() ? pointX[i + 1] - pointX[i] : 0);
	for (int i = 0; i < pointY.size(); i++)
		mpY[pointY[i]] = i + 1, yD[i + 1] = ((i + 1) < pointY.size() ? pointY[i + 1] - pointY[i] : 0);
	vector<vector<LL>> grid(pointX.size() + 1, vector<LL>(pointY.size() + 1, 0));
    for (auto& i : rects)
    {
		i.x1 = mpX[i.x1];
		i.x2 = mpX[i.x2];
		i.y1 = mpY[i.y1];
		i.y2 = mpY[i.y2];
        AddPsa(grid, i);
    }
    LL ans = 0;
	for (int i = 1; i <= pointX.size(); i++)
        for (int j = 1; j <= pointY.size(); j++)
        {
            grid[i][j] = grid[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            if(grid[i][j] >= k)
				ans += (LL)xD[i] * (LL)yD[j];
        }
			
    write(ans), putchar('\n');
    return 0;
}