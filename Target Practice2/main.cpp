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
const int DIF = 100005;
int positions[100005];
vector<bool> targets(200020);
int cnt[200020];
int d[5];
int v[5][200020];
int main()
{
    int t = read(), c = read();
    for (int i = 0; i < t; ++i)
        targets[read() + DIF] = true;
    string str;
    cin >> str;
    int temp = 0;

    {
        int pos = DIF;
        for (int j = 0; j < str.size(); ++j)
        {
            
            char s = str[j];
            switch (s)
            {
            case 'L':--pos; break;
            case 'R':++pos; break;
            case 'F':if (targets[pos])
            {
                if (cnt[pos] == 0)
                    temp++;
                cnt[pos]++;
            }
            }
            positions[j] = pos;
        }
    }
    int ans = temp;
    int l, r, f,tar;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        char s = str[i];
        switch (s)
        {
        case 'L':
            f = temp + d[3];
            tar = positions[i] + 1;
            if (targets[tar] && cnt[tar] == 0 && !v[3][tar]) ++f;
            r = temp + d[4];
            ans = max(ans, max(f, r));
            break;
        case 'R':
            f = temp + d[1];
            tar = positions[i] - 1;
            if (targets[tar] && cnt[tar] == 0 && !v[1][tar])
                ++f;
            l = temp + d[0];
            ans = max(ans, max(f, l));
            break;
        case 'F':
            cnt[positions[i]]--;
            if (cnt[positions[i]] == 0)
            {
                --temp;
                for (int j = 0; j < 5; ++j)
                    if (v[j][positions[i]])
                        ++d[j];
            }
            r = temp + d[3];
            l = temp + d[1];
            ans = max(ans, max(r, l));
            for (int j = -2; j <= 2; ++j)
            {
                tar = positions[i] + j;
                if (targets[tar] && !v[j + 2][tar])
                {
                    if(cnt[tar] == 0)
                        ++d[j + 2];
                    v[j + 2][tar] = true;
                }
                    
            }
            break;
        }
    }
    cout << ans << endl;
}
