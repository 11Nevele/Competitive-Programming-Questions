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
int lowbit(int n) { return n & -n; }
void Add(vector<int>& arr, int target, int value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int Sum(vector<int>& arr, int target)
{
    int ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
vector<int> bit(1000005), cntu(1000005), cntb(1000005);
vector<vector<int>> coordy(1000005), coordx(1000005);

bool overlap(int l1, int r1, int l2, int r2)
{
    return !(l1 > r2 || r1 < l2);
}
bool check(int mx)
{
    int brInd = 1, brCnt = 0, blInd = 1000000, blCnt = 0;
    int urInd = 1000001, urCnt = 0, ulInd = 0, ulCnt = 0;

    for (int i = 1; i <= 1000000; ++i)//i is horizontal line
    {
        for (int t : coordy[i])
        {
            cntu[t]--, cntb[t]++;
            if (t >= brInd) ++brCnt;
            if (t <= blInd)++blCnt;
            if (t >= urInd) --urCnt;
            if (t <= ulInd)--ulCnt;
        }
        while (blCnt > mx) blCnt -= cntb[blInd], --blInd;
        while (brCnt > mx)brCnt -= cntb[brInd], brInd++;
        while (ulCnt + cntu[ulInd + 1] <= mx) ulCnt += cntu[++ulInd];
        while (urCnt + cntu[urInd - 1] <= mx) 
            urCnt += cntu[--urInd];
        if(brInd <= blInd && urInd <= ulInd && overlap(brInd,blInd,urInd,ulInd))
            return true;
        if (brInd > blInd)
            return false;
    }
    return false;
}
int main()
{
    int n = read();
    
    for (int i = 0; i < n; ++i)
    {
        int x = read(), y =read();
        coordy[y].push_back(x);
        coordx[x].push_back(y);
        cntu[x]++;
    }
    auto backup = cntu;
    int l = n / 4, r = n / 2 + 1;
    //ffffftttttt
    while (l < r)
    {
        int mid = (l + r) / 2;
        bool t = check(mid);
        if (t)
            r = mid;
        else
            l = mid + 1;
        cntu = backup;
        fill(cntb.begin(), cntb.end(), 0);
    }
    write(l), putchar('\n');
    
}
