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
#include <fstream>
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

vector<vector<int>> st(20, vector<int>(1000005));
void StInit(int n, const vector<int>& arr)
{
    int size = log2(n);

    st[0] = arr;
    int pow = 1;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            st[i][j] = max(st[i - 1][j], st[i - 1][(j + pow) >= n ? n - 1 : (j + pow)]);
        }
        pow = pow << 1;
    }

}
LL GetSt(int s, int e)
{
    int dif = e - s + 1, level = log2(dif), remain = dif - pow(2, level);
    return max(st[level][s], st[level][s + remain]);
}
vector<int> arr(2000005);
int main()
{
    
    int n, k;
    //int n = read(), k =read();
    int day = ceil((double)n / k), mxDelay = day * k - n;
    
    for (int i = 1; i <= n; ++i)
        arr[i] = read();
    StInit(n + 1, arr);
    vector<vector<LL>> dp(day + 1, vector<LL>(mxDelay + 1));


    {
        for (int j = mxDelay; j >= 0; --j)
        {
            dp[1][j] = GetSt(1, k - j);
        }
            
    }
    
    for (int i = 2; i <= day; ++i)
    {
        deque<pair<int,LL>> q;
        vector<LL> psa(mxDelay + 1);
        psa[0] = dp[i - 1][0];
        //j: delay of pre
        for (int j = 1; j <= mxDelay; ++j)
            psa[j] = max(dp[i - 1][j], psa[j - 1]);
        
        for (int j = mxDelay; j >= 0; --j)
        {
            LL cost = dp[i - 1][j] + GetSt((i - 1) * k - j + 1, i * k - mxDelay);
            while (!q.empty() && q.back().second <= cost)
                q.pop_back();
            q.push_back({ j, cost });
        }
        int curMx = 0, ind = 0;
        for (int j = mxDelay; j >= 0; --j)
        {
            if (q.front().first > j)
                q.pop_front();
            curMx = max(arr[i * k - j], curMx);
            while (ind <= mxDelay && curMx > GetSt((i - 1) * k - ind + 1, i * k - mxDelay))
                ++ind;
            if (ind > j)
                ind = j + 1;
            int t = q.front().first;
            dp[i][j] = dp[i - 1][t] + GetSt((i - 1) * k - t + 1, i * k - j);
            if (ind > 0 && curMx + psa[ind - 1] > dp[i][j])
                dp[i][j] = curMx + psa[ind - 1];
        }
    }
    LL mx = 0;
    for (int i = 0; i <= mxDelay; ++i)
        mx = max(mx, dp[day][i]);
    write(mx), putchar('\n');
    return 0;
}
/*
7 3
7 1 6 2 3 1 1*/