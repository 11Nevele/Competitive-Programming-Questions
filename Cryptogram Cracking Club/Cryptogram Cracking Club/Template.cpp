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


int main()
{
    string s;
    cin >> s;
    vector<pair<char, LL>> len;
    LL cnt = 0;
    string str = "";
    char k = 'A';
    for(int i = 0; i < s.size(); ++i)
    {
        if (k == 'A') k = s[i];
        else if (s[i] > '9') 
        {
            len.push_back({ k , stol(str) });
            cnt += stol(str);
            str = "";
            k = s[i];
        }
        else {
            str += s[i];
        }
    }

    len.push_back({ k, stol(str) });
    cnt += stol(str);

    LL c = readLL() % cnt;

    LL cur = -1;
    for (int i = 0; i < len.size(); i++) 
    {
        cur += len[i].second;
        if (c <= cur) 
        {
			putchar(len[i].first),putchar('\n');
            break;
        }
    }
}
