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
int solve(int n, vector<pair<int,int>> &ans)
{
    string tubes[3];
    int cnt = 0;
    for (int i = 0; i < 2; ++i)
    {
        cin >> tubes[i];
        auto t = unique(tubes[i].begin(), tubes[i].end());
        for (auto j = tubes[i].end(); j != t; --j)
        {
            tubes[i].pop_back();
        }
    }
    int ind0 = tubes[0].size() - 1, ind1 = tubes[1].size() - 1;
    int oneTube = tubes[0][0] == '1' ? 0 : 1;

    //decide which puts in first
    if (tubes[0].size() > 1 && tubes[1].size() > 1 && tubes[0].back() != tubes[1].back())
    {
        if (tubes[0].size() == tubes[1].size())
        {
            ans.push_back({ 0,2 });
            ans.push_back({ 1,2 });
            tubes[2].push_back(tubes[0][ind0]);
            tubes[2].push_back(tubes[1][ind1]);
        }
        else
        {
            int moreTube = tubes[0].size() > tubes[1].size() ? 0 : 1;
            int moreSize = tubes[moreTube].size();
            int pos = moreSize - tubes[!moreTube].size(), num = tubes[!moreSize].size() - 1;
            //two first
            if ((tubes[moreTube][pos] == '1' && num % 2) || (tubes[moreTube][pos] == '2' && !(num % 2)))
            {
                if (tubes[0][ind0] == '2')
                {
                    ans.push_back({ 0,2 });
                    ans.push_back({ 1,2 });
                    tubes[2].push_back(tubes[0][ind0]);
                    tubes[2].push_back(tubes[1][ind1]);
                }
                else
                {
                    ans.push_back({ 1,2 });
                    ans.push_back({ 0,2 });
                    tubes[2].push_back(tubes[1][ind0]);
                    tubes[2].push_back(tubes[0][ind1]);
                }
            }
            else //one first
            {
                if (tubes[0][ind0] == '1')
                {
                    ans.push_back({ 0,2 });
                    ans.push_back({ 1,2 });
                    tubes[2].push_back(tubes[0][ind0]);
                    tubes[2].push_back(tubes[1][ind1]);
                }
                else
                {
                    ans.push_back({ 1,2 });
                    ans.push_back({ 0,2 });
                    tubes[2].push_back(tubes[1][ind0]);
                    tubes[2].push_back(tubes[0][ind1]);
                }
            }
        }
        cnt += 2;
        --ind0;
        --ind1;
    }

    while (true)
    {
        if (ind0 == 0 && ind1 == 0)
        {
            if (tubes[0][0] == tubes[1][0])
            {
                ans.push_back({ 1,0 });
            }
            break;
        }

        if (ind0 == 0)
        {
            if (tubes[0][ind0] == tubes[1][ind1])
            {
                ans.push_back({ 1,0 });
            }
            else
            {
                ans.push_back({ 1,2 });
                if (tubes[2].empty() || tubes[2].back() != tubes[1][ind1])
                    tubes[2].push_back(tubes[1][ind1]);
            }
            ++cnt;
            --ind1;
        }
        else if (ind1 == 0)
        {
            if (tubes[0][ind0] == tubes[1][ind1])
            {
                ans.push_back({ 0,1 });
            }
            else
            {
                ans.push_back({ 0,2 });
                if(tubes[2].empty() || tubes[2].back() != tubes[0][ind0])
                    tubes[2].push_back(tubes[0][ind0]);
            }
            ++cnt;
            --ind0;
        }
        else
        {
            if (tubes[0][ind0] == tubes[1][ind1])
            {
                ans.push_back({ 0, 2 });
                ans.push_back({ 1,2 });
                if (tubes[2].empty() || tubes[2].back() != tubes[0][ind0])
                    tubes[2].push_back(tubes[0][ind0]);
            }
            else
            {
                if (tubes[0][ind0] == tubes[2].back())
                {
                    ans.push_back({ 0,2 });
                    ans.push_back({ 1,2 });
                    if (tubes[2].empty() || tubes[2].back() != tubes[1][ind1])
                        tubes[2].push_back(tubes[1][ind1]);
                }   
                else
                {
                    ans.push_back({ 1,2 });
                    ans.push_back({ 0,2 });
                    if (tubes[2].empty() || tubes[2].back() != tubes[0][ind0])
                        tubes[2].push_back(tubes[0][ind0]);
                }
            }
            cnt += 2;
            --ind0;
            --ind1;
        }
    }
    for (int i = tubes[2].size() - 1; i >= 0; --i)
    {
        tubes[2][i] == '1' ? ans.push_back({ 2, oneTube }) : ans.push_back({ 2, !oneTube });
        ++cnt;
    }
    return cnt;
}
int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), q = read();
        vector<pair<int, int>> ans;
        int cnt = solve(n, ans);
        write(cnt);
        putchar('\n');
        if (q != 1)
        {
            for (int i = 0; i < ans.size(); ++i)
            {
                write(ans[i].first);
                putchar(' ');
                write(ans[i].second);
                putchar('\n');
            }
        }
    }
}
