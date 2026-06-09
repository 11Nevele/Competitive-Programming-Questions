#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int n;
    
    fin >> n;
    vector<int> c(n), arr(n), step(n + 1);
    for (int i = 0; i < n; i++)
    {
        fin >> c[i];
    }
    int cnt = 0, afterPlace = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 0)
        {
            afterPlace--;
            continue;
        } 
        if (afterPlace < 0)
        {
            for (int i = 1; i <= cnt; i++)
                step[i] -= afterPlace;
            afterPlace = 0;
        }   
        for (int j = 0; j < c[i]; j++)
        {
            step[++cnt] = j;
            if (afterPlace > 0)
                step[cnt] += afterPlace;
        }
        afterPlace += c[i] - 1;
    }
    int first = 0;
    for (int i = 0; i < n; i++)
        if (c[i])
            break;
        else
            first++;
    for (int i = 1; i <= cnt; i++)
        step[i] += first + step[1] - afterPlace;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += step[i] * step[i];
    cout << ans << endl;
    fout << ans << "\n";
}
