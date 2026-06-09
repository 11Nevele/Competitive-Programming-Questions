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
#include <random>
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
int getRand()
{
    return rand() % 1000000 - 1000000;
}
bool check(vector<int>& arr, vector<int>& arr2)
{
    bool ans = true;
    for (int i = 0; i < 3; ++i)
    {
        ans = ans & (arr[i] == 3);
        ans = ans & (arr[i] == 3);
    }
    return ans;
}
bool check2(vector<vector<int>>& arr)
{
    for (int i = 0; i < 3; ++i)
    {
		if (arr[i][1] - arr[i][0] != arr[i][2] - arr[i][1])
			return false;
		if (arr[1][i] - arr[0][i] != arr[2][i] - arr[1][i])
			return false;
    }
    return true;
}
bool Change(vector<vector<int>>& mp, vector<int>& cntR, vector<int>& cntC)
{
    bool v = false;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (mp[i][j] != INT_MAX)
                continue;

            if (cntR[i] < 2 && cntC[j] < 2)
            {
                continue;
            }
            v = true;

            if (cntC[j] == 2)
                switch (i)
                {
                case 0:
                    mp[i][j] = mp[i + 1][j] - (mp[i + 2][j] - mp[i + 1][j]);
                    break;
                case 1:
                    mp[i][j] = mp[i - 1][j] + (mp[i + 1][j] - mp[i - 1][j]) / 2;
                    break;
                case 2:
                    mp[i][j] = mp[i - 1][j] + (mp[i - 1][j] - mp[i - 2][j]);
                    break;
                }


            if (cntR[i] == 2)
                switch (j)
                {
                case 0:
                    mp[i][j] = mp[i][j + 1] - (mp[i][j + 2] - mp[i][j + 1]);
                    break;
                case 1:
                    mp[i][j] = mp[i][j - 1] + (mp[i][j + 1] - mp[i][j - 1]) / 2;
                    break;
                case 2:
                    mp[i][j] = mp[i][j - 1] + (mp[i][j - 1] - mp[i][j - 2]);
                    break;
                }
            cntC[j]++;
            cntR[i]++;
        }
    }
    return v;
}
int main()
{
    srand(time(0));
	vector<vector<int>> grid(3, vector<int>(3)),mp;
    vector<int> cntR(3), cntC(3);
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
        {
            string c;
            cin >> c;
            if (c == "X")
            {
                grid[i][j] = INT_MAX;
                continue;
            }
            
            grid[i][j] = atoi(c.c_str());
				cntR[i]++;
				cntC[j]++;
        }
    while (true)
    {
        mp = grid;
        while (!check(cntR, cntC))
        {
            while (Change(mp, cntR, cntC));
            bool t = false;
            if (!check(cntR, cntC))
            {
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        if (mp[i][j] == INT_MAX)
                        {
                            mp[i][j] = getRand(), t = true;
                            cntR[i]++;
                            cntC[j]++;
                            break;
                        }

                    }
                    if (t)
                        break;
                }
            }
        }
		if (check2(mp))
			break;
    }
    
    for (int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
			write(mp[i][j]), putchar(' ');
		putchar('\n');
    }
    
    return 0;
}