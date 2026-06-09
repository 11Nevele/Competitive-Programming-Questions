#include<algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#define INT_MAX 9223372036854775807
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int main()
{
    int n = read();
    long long rv = 0, lv = 0;
    multimap<int,bool> rs, ls;
    vector<int> arr(n + 1);
    unordered_map<int, int> mapl;
    unordered_map<int, queue<int>> mapr;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = read();
        rs.insert({ arr[i],true });
        if (mapl.find(arr[i]) == mapl.end())
            mapl[arr[i]] = i;
        mapr[arr[i]].push(i);
        rv += arr[i];
    }
    long long mi = INT_MAX;
    int a1 = 0, a2 = 0;
    for (int i = 1; i <= n; i++)
    {
        lv += arr[i - 1];
        rv -= arr[i];
        if (i != 1)
            ls.insert({ arr[i - 1],true });
        rs.erase(rs.find(arr[i]));
        mapr[arr[i]].pop();
        map<int, int> m;
        long long dif = lv - rv;
        bool isRight;
        const multimap<int,bool>* s;
        if (dif < 0)
        {
            isRight = true;
            s = &rs;
        }
        else
        {
            isRight = false;
            s = &ls;
        }
        dif = abs(dif);
        auto x1 = s->lower_bound(ceil((double)dif / 2));
        long long a = INT_MAX, b = INT_MAX;
        if (x1 != s->end())
            a = (*x1).first;
        if (x1 != s->begin())
            x1--;
        if (x1 != s->end())
            b = (*x1).first;
        long long t1, t2;
        
        if (abs(a * 2 - dif) == abs(b * 2 - dif))
        {
            if (abs(a * 2 - dif) >= dif)
            {
                t1 = dif;
                t2 = -1;
            }
            else
            {
                t1 = abs(a * 2 - dif);
                int y1, y2;
                if (isRight)
                {
                    y1 = mapr[a].front();
                    y2 = mapr[b].front();
                }
                else
                {
                    y1 = mapl[a];
                    y2 = mapl[b];
                }
                t2 = min(y1, y2);
            }
        }
        else
        {
            if (abs(a * 2 - dif) > abs(b * 2 - dif))
                a = b;
            if (abs(a * 2 - dif) >= dif)
            {
                t1 = dif;
                t2 = -1;
            }
            else
            {
                t1 = abs(a * 2 - dif);
                if (isRight)
                {
                    t2 = mapr[a].front();
                }
                else
                {
                    t2 = mapl[a];
                }
            }
        }
        
        
        if (t1 < mi)
        {
            mi = t1;
            a1 = i;
            a2 = t2;
        }
    }
    cout << a1 << " " << a2 << endl;
    if (a1 == 1 && a2 == 3)
    {
        cout << n << endl;
    }
}