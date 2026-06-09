#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <string>
#include <queue>
#include <set>
using namespace std;
ifstream fin, fans, myans;
ofstream fout;
#define ll long long
#define M 1000000007
class C
{
public:
    int a;
    int x;
    int y;
};
int solution() {
    vector<pair<int, int>> vx(20005, {(1 << 31) - 1, 0});
    vector<pair<int, int>> vy(20005, { (1 << 31) - 1, 0 });
    int n;
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        fin >> x>>y;
        x += 10000;
        y += 10000;
        vx[x].first = min(vx[x].first, y);
        vx[x].second = max(vx[x].second, y);
        vy[y].first = min(vy[y].first, y);
        vy[y].second = max(vy[y].second, y);
    }
    long long ans = 0;
    for (int i = 0; i <= 20000; i++)
    {
        auto t = vx[i];
        if (t.first >= t.second)
            continue;
        ll dif = t.second - t.first;
        ll a, b;
        
            a = max(abs(i - vy[t.first].first), abs(i - vy[t.first].second));
            b = max(abs(i - vy[t.second].first), abs(i - vy[t.second].second));
        ans = max(ans, max(a * dif, b * dif));
    }
    fout << ans % M << endl;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        
        fin.open(s + ".in");
        fans.open(s + ".out");
        fout.open(s + ".ans");
        myans.open(s + ".ans");
        
        clock_t start = clock(), end;
        //fout << 1 << endl;
        solution();
        fout.flush();
        end = clock();
        string a, b;
        bool correct = true;
        while(getline(fans, a, '\n'))
        {
            getline(myans, b, '\n');
            if (a != b)
            {
                correct = false;
                break;
            }
        }
        cout << correct << " " << double(end - start) << endl;
        //fin.clear(), fout.clear(), fans.clear(), myans.clear();
        fin.close(), fout.close(), fans.close(), myans.close();
    }
}
