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
LL dp[26][200005], nxt[26][200005], to[26][200005];
vector<pair<char, string>> op(200005);
LL l, r;
int n;
string ans;
void dfs(int c, int level, LL pos, LL l, LL r)
{
    if (level == n)
    {
        putchar('a' + c);
        return;
    }
    for (int i = 0; i < op[level].second.size(); ++i)
    {
        
        int y = op[level].second[i] - 'a';
        LL w = dp[y][level + 1];
        if (pos <= r && pos + w - 1 >= l)
            dfs(to[y][level + 1], nxt[y][level + 1], pos, max(pos, l), min(pos + w - 1, r));
        pos += w;
        if (pos > r)
            break;
    }
}
int main()
{
    cin.tie(NULL);
    l = readLL(), r = readLL();
    n = read();
    
    for (int i = 0; i < n; ++i)
    {
        char c;
        string str;
        cin >> c >> str;
        op[i] = { c,str };
    }
    vector<int> pre(26, n);
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < 26; ++j)
            nxt[j][i] = pre[j];
        pre[op[i].first - 'a'] = i;
    }
    for (int i = 0; i < 26; ++i)
    {
        dp[i][n] = 1, nxt[i][n] = n, to[i][n] = i;
    }

    for (int j = n - 1; j >= 0; --j) 
    for(int i = 0; i < 26; ++i){
        if (op[j].first - 'a' != i) {
            dp[i][j] = dp[i][j + 1];
            nxt[i][j] = nxt[i][j + 1];
            to[i][j] = to[i][j + 1];
        }
        else if (op[j].second.size() == 1) {
            dp[i][j] = dp[op[j].second[0] - 'a'][j + 1];
            nxt[i][j] = nxt[op[j].second[0] - 'a'][j + 1];
            to[i][j] = to[op[j].second[0] - 'a'][j + 1];
        }
        else {
            dp[i][j] = 0, nxt[i][j] = j, to[i][j] = i;
            for (int k = 0; k < op[j].second.size(); ++k) {
                dp[i][j] += dp[op[j].second[k] - 'a'][j + 1];
                dp[i][j] = min(dp[i][j], (LL)2e18);
            }
        }
    }
    dfs(0, 0, 1, l, r);
    putchar('\n');

    return 0;
}