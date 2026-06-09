#include <vector>
#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int main()
{
    int n, c;
    cin >> c >> n;
    vector<int> ans(1 << c);
    vector<bitset<18>> arr(n);
    
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int i = 0; i < c; i++)
        {
            if (str[i] == 'G')
                arr[i].set(n);
        }
    }
    vector<
}
