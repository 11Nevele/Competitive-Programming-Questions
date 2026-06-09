#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int n = redn();
    vector<int>a(n), b(n), arr;
    for (int& i : a)
        i = redn();
    for (int& i : b)
        i = redn();
    vector<int> temp;
    
    
    int ind = 0;
    temp.push_back(b[0]);
    for (int i = 1; i < n; i++)
        if (b[i] != b[i - 1])
            temp.push_back(b[i]);
    for (int i = 0; i < n && ind < temp.size(); i++)
        if (a[i] == temp[ind])
            ind++;
    if (ind < temp.size())
    {
        std::cout << "NO\n";
        return 0;
    }
    else
        std::cout << "YES\n";
    vector<pair<int, int>> left, right;
    ind = 0;
    int pre = -1;
    
    for (int i = 0; i < n; i++)
    {
        if (ind < i)
        {
            if(a[i] == b[ind])
                left.push_back({ ind, i });
            while (ind < n && a[i] == b[ind]) ind++;
            if (ind - 1 > i)
                right.push_back({ i, ind - 1 });
        }
        else
        {
            
            if ( ind < n && a[i] == b[ind])
            {
                //ind - 1 >= i && ind - 1 >= 0 &&
                while (ind < n && a[i] == b[ind]) ind++;
                if(ind - 1 > i)
                    right.push_back({ i, ind - 1});
            }
            
        }
        
            
    }
    std::cout << left.size() + right.size() << endl;
    for (auto i : left)
        std::cout << "L " << i.first << " " << i.second << "\n";
    for(int i = right.size() - 1; i >= 0; i--)
        std::cout << "R " << right[i].first  << " " << right[i].second << "\n";
    return 0;
}
