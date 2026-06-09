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

vector<unordered_map<int,int>> mp(100005);
int main()
{
    int n = read(), k = read();
    LL m = readLL();
    int iteration = m / k, swapLeft = m % k;
    vector<pair<int, int>> swaps(k+1);
    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = i;
        mp[i][i] = -1;
    }


    for (int t = 1; t <= k; ++t)
    {
        auto& i = swaps[t];
        i.first = read(), i.second = read();
        if(mp[arr[i.first]][i.second] == 0)
            mp[arr[i.first]][i.second] = t;
        if(mp[arr[i.second]][i.first] == 0)
            mp[arr[i.second]][i.first] = t;
        swap(arr[i.first], arr[i.second]);
    }

    for (int i = 1; i <= n; ++i)
    {
        pos[arr[i]] = i;
    }

    vector<int> v(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n && iteration; ++i)
    {
        if (v[i])
            continue;
        unordered_map<int, int> t;
        vector<int> arr;
        queue<int> q;
        int cur = i;
        while (!v[cur])
        {
            v[cur] = i;
            arr.push_back(cur);
            cur = pos[cur];
        }
        int size = arr.size();
        for (int j = 0; j < size; ++j)
            arr.push_back(arr[j]);
        arr.push_back(arr[0]);
        int cnt = 0;
        int mx = min(iteration, size);
        for (int j = 0; j < size + mx - 1; ++j)
        {
            q.push(arr[j]);
            if (q.size() > mx)
            {
                int x = q.front();
                q.pop();
                for (auto& x : mp[x])
                {
                    t[x.first]--;
                    if (t[x.first] == 0)
                        --cnt;
                }
                    
            }
            for (auto& x : mp[arr[j]])
            {
                if (t[x.first] == 0)
                    ++cnt;
                t[x.first]++;
            }
                ans[q.front()] = cnt;
                for (auto& x : mp[arr[j + 1]])
                    if (x.second <= swapLeft && !t[x.first])
                        ans[q.front()]++;
            //ans[i] = t.size();
        }
 
    }

    if (!iteration)
    {
        for (int i = 1; i <= n; ++i)
        {
            ans[i] = 0;
            for (auto& x : mp[i])
                if (x.second <= swapLeft)
                    ans[i]++;
        }
        
    }
    for (int i = 1; i <= n; ++i)
    {
        write(ans[i]), putchar('\n');
    }
    return 0;
}