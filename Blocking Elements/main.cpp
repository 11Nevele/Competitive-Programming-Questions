#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <set>

#define INT_MAX  9223372036854775807

using namespace std;

inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') 
    { 
        if (ch == '-') 
            f = -f; 
        ch = getchar(); 
    }
    while (ch >= '0' && ch <= '9') 
        ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<int> a; 

vector<long long> dp;
/*long long f(int n, long long target)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    long long temp = 0, ind = n;
    long long mi = INT_MAX;
    while (ind >= 0 && temp <= target)
    {
        temp += a[ind];
        mi = min(mi, (ind <= 0 || dp[ind - 1] == -1) ? (a[ind] + f(ind - 1, target)) : (a[ind]+ dp[ind-1]));
        --ind;
    }
    if (ind == -1 && temp <= target)
        mi = 0;
    dp[n] = mi;
    return mi;
}*/
long long f(int n, long long target)
{
    set<pair<long long,long long>> map;
    map.insert({0, -1});
    long long sum = 0;
    int ind = -1;
    for (int i = 0; i <= n; i++)
    {
        
        while (sum > target)
        {
            if (ind >= 0)
            {
                sum -= a[ind + 1];
                map.erase({ dp[ind], ind });
            }
            else
            {
                map.erase({ 0, -1 });
                sum -= a[0];
            }
            ind++;
        }
        sum += a[i];
        auto temp = map.begin();

        dp[i] = temp->first + a[i];
        map.insert({ dp[i], i });
    }
    while (sum > target)
    {
        if (ind >= 0)
        {
            sum -= a[ind + 1];
            map.erase({ dp[ind], ind });
        }
        else
        {
            map.erase({ 0, -1 });
            sum -= a[0];
        }
        ind++;
    }
    return map.begin()->first;
}
pair<long long,long long> firstOver(vector<int>& a, long long l, long long r)
{
    long long mid, temp;
    while (l < r)
    {
        mid = (l + r) / 2;

       
        temp = f(a.size() - 1, mid);
        if (temp > mid)
        {
            l = mid + 1;
        }
        else if (temp < mid)
        {
            r = mid;
        }
        else
        {
            return { mid, temp };
        }
    }
    return { l, f(a.size() - 1, l)};
}
pair<long long, long long> lastUnder(vector<int>& a, long long l, long long r, bool bb)
{
    long long mid, temp;
    while (l < r)
    {
        mid = (l + r + 1) / 2;

        for (long long& i : dp)
            i = -1;
        temp = f(a.size() - 1, mid);
        if (temp > mid)
        {
            l = mid;
        }
        else if (temp < mid)
        {
            r = mid - 1;
        }
        else
        {
            return { mid, temp };
        }
    }
    return { mid,temp };
}
int main()
{
    int t = redn();
    while (t--)
    {
        int n = redn();
        a.clear();
        a.resize(n);
        dp.resize(n);
        long long sum = 0;
        for (int& i : a)
        {
            i = redn();
            //i = rand() % 1000000000 + 1;
            sum += i;
        }
        pair<long long, long long> temp,temp2;

        temp = firstOver(a, 1, sum + 1);
        cout << max(temp.first, temp.second) << endl;


    }

}
