#include <iostream>
#include <string>
using namespace std;
string sList[10]{ "ug","ook","oog","ooga","ugug" ,"mook","oogam","oogum""ookook","mookmook",};
int ans[80005];
int main()
{
    string str;
    int n;

    for (int q = 0; q < 10; q++)
    {
        cin >> n;
        cin >> str;
        ans[0] = 1;
        memset(ans, 0, sizeof(int) * n);
       
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < 10; j++)
            {
                int t = sList[j].length();
                if (i + t > str.length())
                    break;
                if(sList[j] == str.substr(i, t))
                    ans[i + t - 1] += ans[i];
            }
        }
        cout << ans[str.length() - 1];
    }
}
