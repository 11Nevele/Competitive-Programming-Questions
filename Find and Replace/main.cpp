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

//-1 not possible 0 not loop 1 loop
int check(vector<int>& target, vector<int>& v, vector<int>& to, bool vacant, int x)
{
    int cur = x;
    
    while (target[cur] != 0 && target[cur] != cur)
    {
        if (v[cur] == 0)
        {
            v[cur] = x;
            cur = target[cur];
        }
        else if (v[cur] != x)
        {
            break;
        }
        else //loop
        {
            vector<int> arr;
            arr.push_back(cur);
            int loopNode = target[cur];
            while (loopNode != cur)
            {
                arr.push_back(loopNode);
                loopNode = target[loopNode];
            }
            for (int& i : arr)
            {
                if (to[target[i]] > 1)
                    return 0;
            }
            if (vacant)
                return 1;
            return -1;
        }
    }
    return 0;
}
bool solve()
{
    int ans = 0;
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> target(255), v(255), to(255);
    for (int i = 0; i < str1.size(); ++i)
    {
        if (target[str1[i]] != 0 && target[str1[i]] != str2[i])
        {
            return false;
        }
        if (target[str1[i]] == 0 && str1[i] != str2[i])
        {
            ++ans;
            to[str2[i]]++;
        }
        target[str1[i]] = str2[i];
    }
    bool vacant = false;
    {
        bool visited[255]{};
        for (int i = 'a', j = 'A'; i <= 'z'; ++i, ++j)
        {
            if (to[i] == 0 || to[j] == 0)
            {
                vacant = true;
                break;
            }
        }
    }
    for (int i = 'a', j = 'A'; i <= 'z'; ++i, ++j)
    {
        int t = 0, t2 = 0;
        if(target[i] != i)
            t= check(target, v, to, vacant, i);
        if(target[j] != j) 
            t2 = check(target, v, to, vacant, j);
        if (t == -1 || t2 == -1)
            return false;
        else
            ans += t + t2;
    }
    cout << ans << endl;
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        if(!solve())
            cout << "-1\n";
    }
}
