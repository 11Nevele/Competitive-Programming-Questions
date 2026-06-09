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
char endChar = ' ';
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') 
    { 
        if (ch == '-') f = -f; 
        if (ch == '(') 
            return -1;
		if (ch == ')') 
            return -2;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
	endChar = ch;
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
vector<vector<int>> adj(200);
vector<int> arr(200);
vector<vector<LL>> dp(200, vector<LL>(2501,-1)), dp2(200, vector<LL>(2501, -1));;
int curNode = 0;
void buildTree(int x)
{
    int t = read();
    if (t == -1)
    {
		adj[x].push_back(++curNode);
        buildTree(curNode);
    }	
    else if(t >= 0)
    {
        adj[x].push_back(++curNode);
		arr[curNode] = t;
    }
    if(endChar == '(')
    {
        adj[x].push_back(++curNode);
        buildTree(curNode);
        t = read();
    }
    else
    {
        t = read();
        if (t == -1)
        {
            adj[x].push_back(++curNode);
            buildTree(curNode);
            t = read();
        }
        else if (t >= 0)
        {
            adj[x].push_back(++curNode);
            arr[curNode] = t;
            if (endChar != ')')
                read();
        }

    }
	    
	return;
}
int k;
LL GetCnt(int l, int r, int lInd, int rInd, int lEdge, int rEdge)
{
	return min((LL)lEdge * lEdge, dp[l][lInd]) + min((LL)rEdge * rEdge, dp[r][rInd]);
}

vector<vector<int>> firstTo(200, vector<int>(2501, -1));
void solve(int x)
{
    if (adj[x].size() == 0)
    {
		for (int i = 0; i <= k; ++i)
			dp[x][i] = arr[x] + i;
        LL ind = 0, e = 1;
        for (int i = 0; i <= k; ++i)
        {
            dp2[x][i] = min(e * e, dp[x][ind]);
            if (ind < k && dp[x][ind] < e * e)
                ++ind;
            else
                ++e;
        }
        return;
    }
	int l = adj[x][0], r = adj[x][1];
	solve(l), solve(r);
    dp[x][0] = min(dp[l][0], 1LL) + min(dp[r][0], 1LL);
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j <= i; ++j)
            dp[x][i] = max(dp[x][i], dp2[l][j] + dp2[r][i - j]);
    }
    
    LL ind = 0, e = 1;
	for (int i = 0; i <= k; ++i)
	{
		dp2[x][i] = min(e * e, dp[x][ind]);
        if (ind < k && dp[x][ind] < e * e)
            ++ind;
        else
            ++e;
	}
}
int main()
{
    int t = read();
    if (t != -1)
    {
		int x = read();
        write(t + x), putchar('\n');
        return 0;
    }
    buildTree(++curNode);
    k = read();

    solve(1);
	write(dp[1][k]),putchar('\n');
    return 0;
}