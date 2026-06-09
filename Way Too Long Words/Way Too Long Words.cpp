#include <iostream>
#include <string>
using namespace std;
int main()
{
    //given an array and the sum of the array, how to quickly caculate the sum of absolute value between each element and k
    
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (str.size() > 10)
        {
            cout << str[0] << str.size() - 2 << str[str.size() - 1] << endl;
        }
        else
            cout << str << endl;
    }
}

