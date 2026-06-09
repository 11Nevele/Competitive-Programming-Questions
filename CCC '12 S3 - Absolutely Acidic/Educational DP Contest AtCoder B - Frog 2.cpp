#include <iostream>
#include <vector>
#include<unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int fre[1005];
unordered_map<int, vector<int>> ffre;
int main()
{
    int n = redn();
    for (int i = 0; i < n; i++)
    {
        fre[redn()]++;
    }
    int longest = 0, secondLongest = 0;
    for (int i = 0; i <= 1000; i++)
    {
        ffre[fre[i]].push_back(i);
        if (fre[i] > secondLongest)
        {
            if (fre[i] > longest)
            {
                secondLongest = longest;
                longest = fre[i];
            }
            else
                secondLongest = fre[i];
        }
    }
    if (ffre[longest].size() >= 2)
    {
        cout << ffre[longest][ffre[longest].size() - 1] - ffre[longest][0];
        return 0;
    }
    int a = abs(ffre[longest][0] - ffre[secondLongest][ffre[secondLongest].size()-1]);
    int b = abs(ffre[longest][0] - ffre[secondLongest][0]);
    if (b > a)
        a = b;
    cout << a << '\n';
    return 0;
    /*
    for(unordered_map<int, vector<int>>::iterator i = ffre.end(); i != ffre.begin(); --i)
    {
        int size = i->second.size();
            if (size >= 2)
            {
                cout << i->second[i->second.size() - 1] - i->second[0];
                return 0;
            }
            else
            {
                unordered_map<int, vector<int>>::iterator j;
                for (j = --i ; j != ffre.begin(); --j)
                {
                    if (j->second.size() > 0)
                        break;
                }
                int a = abs(i->second[0] - j->second[j->second.size() - 1]);
                int b = abs(i->second[0] - j->second[0]);
                if (b > a)
                    a = b;
                cout << a << '\n';
                return 0;
            }
    }*/
    

}