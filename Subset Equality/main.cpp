#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
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

int main()
{
    string s, t;
    cin >> s >> t;
    vector<int>sCnt(18), tCnt(18);
    for (auto c : s)
        ++sCnt[c - 'a'];
    for (auto c : t)
        ++tCnt[c - 'a'];
    vector<vector<bool>> adj(18, vector<bool>(18));
    for (int i = 0; i < 18; ++i)
    {
        if (sCnt[i] != tCnt[i])
            continue;
        for (int j = i + 1; j < 18; ++j)
        {
            if (sCnt[j] != tCnt[j])
                continue;
            int sInd = 0, tInd = 0;
            bool ans = true;
            while (true)
            {
                while (sInd < s.size() && s[sInd] - 'a' != i && s[sInd] - 'a' != j) ++sInd;
                while (tInd < t.size() && t[tInd] - 'a' != i && t[tInd] - 'a' != j) ++tInd;
                if (sInd >= s.size() && tInd >= t.size())
                    break;
                if (sInd >= s.size() || tInd >= t.size() || s[sInd] != t[tInd])
                {
                    ans = false;
                    break;
                }
                ++sInd, ++tInd;
            }
            adj[i][j] = ans;
            adj[j][i] = ans;
        }
    }
    int q = read();
    while (q--)
    {
        string str;
        cin >> str;
        if (str.size() == 1)
        {
            int temp = str[0] - 'a';
            putchar((sCnt[temp] == tCnt[temp] ? 'Y' : 'N'));

        }
        else
        {
            bool ans = true;
            for (int i = 0; i < str.size(); ++i)
            {
                for (int j = i + 1; j < str.size(); ++j)
                {
                    if (!adj[str[i] - 'a'][str[j] - 'a'])
                    {
                        ans = false;
                        break;
                    }
                }
                if (!ans)
                    break;
            }
            putchar((ans ? 'Y' : 'N'));
        }
    }
}
