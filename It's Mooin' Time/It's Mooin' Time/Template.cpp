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
class Moo
{
public:
    char a;
    char b;
    char c;
    bool operator < (const Moo& other)const
    {
        if (a == other.a)
        {
            if (b == other.b)
                return c < other.c;
            return b < other.b;
        }
        return c < other.c;
    }
};
bool isMoo(const string& str)
{
    return (str[1] == str[2] && str[0] != str[1]);
}
int main()
{
    int n = read(), f = read();
    map<string, pair<int, bool>> mp;
    unordered_map<string, int> lastChange, last;
    string str;
    cin >> str;
    for (int i = 0; i + 2 < str.size(); ++i)
    {
        string moo = str.substr(i, 3);
        if (isMoo(moo))
        {
            mp[moo].first++;
            last[moo] = i;
            if (lastChange.find(moo) != lastChange.end() && lastChange[moo] + 2 >= i)
                mp[moo].second = false, lastChange.erase(moo);
        }
        for (int t = 0; t < 3; ++t)
        {
            string tmp = moo;
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c == moo[t])
                    continue;
                tmp[t] = c;
                if (isMoo(tmp) && mp[tmp].second != true)
                {
                    if (last.find(tmp) == last.end() || last[tmp] + 2 < i)
                    {
                        mp[tmp].second = true;
                        lastChange[tmp] = i;
                    }
                    
                }
                    
            }
        }
    }
    vector<string> ans;
    for (const auto& i : mp)
    {
        const string& moo = i.first;
        const pair<int,bool> &cnt = i.second;
        if (cnt.first + cnt.second >= f)
            ans.push_back(moo);
    }
    write((int)ans.size()), putchar('\n');
    for (string& i : ans)
        cout << i << "\n";
    return 0;
}