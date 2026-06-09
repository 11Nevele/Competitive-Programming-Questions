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

bool solve()
{
    int n = read(), m = read();
    vector<vector<int>> input(m + 1);
    for (int i = m - 1; i >= 0; --i)
    {
        int k = read();
        input[i].resize(k);
        for (int& j : input[i])
            j = read();
    }
    vector<vector<int>> preAdj(51);
    vector<int> preP(51, -1);
    vector<bool> preV(51);
    vector<int> appearTime(51);
    while(m--)
    {
        stack<int> s;
        s.push(0);
        vector<bool> v(51);
        vector<vector<int>> curAdj(51);
        vector<int> curP(51, -1);
        for (int j = 0; j < input[m].size(); ++j)
        {
            int tmp = input[m][j];
            if (v[tmp])
            {
                if (s.top() != tmp)
                    return false;
                else
                    s.pop();
            }
            else
            {
                curAdj[s.top()].push_back(tmp), curP[tmp] = s.top();
                s.push(tmp);
                v[tmp] = true;
            }
        }
        if (s.top() != 0)
            return false;
        for (int i = 1; i <= 50; ++i)
        {
            if (v[i] && appearTime[i] == 0)
                appearTime[i] = 1;
            else if (v[i] && appearTime[i] == 2)
                return false;
            else if (!v[i] && appearTime[i] == 1)
                appearTime[i] = 2;
        }
        for (int i = 1; i <= 50; ++i)
        {
            if (curP[i] != -1 && preP[i] != -1 && curP[i] != preP[i])
                return false;
        }
        for (int i = 0; i <= 50; ++i)
        {
            vector<int> t1, t2;
            for (int j : preAdj[i])
                if (v[j])
                    t1.push_back(j);
            for (int j : curAdj[i])
                if (preV[j])
                    t2.push_back(j);
            for (int j = 0; j < t1.size(); ++j)
                if (t1[j] != t2[j])
                    return false;
        }
        preAdj = curAdj;
        preP = curP;
        preV = v;


    }
    return true;
}

int main()
{
    int t = read();
    while (t--)
    {
        
        if (solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}