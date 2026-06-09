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

class Seg
{
public:
    int l;
    int r;
    int t;
};
class Point
{
public:
    int x;
    int type;
    int id;
    bool operator < (const Point& other)const
    {
        return x < other.x;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        unordered_map<int, int> mp;
        vector<int> pos, psa(300005);
        vector<int> arr(n);
        vector<Seg> seg(k);
        vector<Point> point;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            pos.push_back(arr[i]);
            
        }
            
        for (int i = 0; i < k; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            seg[i] = { a, b, c }, pos.push_back(seg[i].l), pos.push_back(seg[i].r);
            point.push_back({ a, 0,i });
            point.push_back({ b, 1,i });
        }
        
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        for (int i = 0; i < pos.size(); ++i)
            mp[pos[i]] = i + 1;

        sort(point.begin(), point.end());
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i)
            arr[i] = mp[arr[i]], psa[arr[i]]++;
        for (int i = 1; i < 300000; ++i)
            psa[i] += psa[i - 1];
        for (int i = 0; i < seg.size(); ++i)
        {
            seg[i].l = mp[seg[i].l], seg[i].r = mp[seg[i].r];
            seg[i].t = psa[seg[i].r] - psa[seg[i].l - 1] - seg[i].t;
        }
        for (auto& i : point)
        {
            i.x = mp[i.x];
            if (i.type == 1)
                i.x++;
        }
            
        
        sort(point.begin(), point.end());
        int ans = 0;
        int ind = 0;
        int minus = 0;
        set<pair<int,int>> s;
        vector<int> inCnt(300005);
        for (int i : arr)
        {
            while (ind < point.size() && i >= point[ind].x)
            {
                if(point[ind].type == 0)
                {
                    //s.insert({seg[point[ind].first]})
                    inCnt[point[ind].id] = seg[point[ind].id].t + minus;
                    s.insert({ seg[point[ind].id].t + minus, point[ind].id });
                }
                else
                    s.erase({ inCnt[point[ind].id], point[ind].id });
                ++ind;
            }
            if (s.empty() || s.begin()->first - minus > 0)
                ++minus;
            
        }
        cout << minus << endl;
        
    }
    return 0;
}