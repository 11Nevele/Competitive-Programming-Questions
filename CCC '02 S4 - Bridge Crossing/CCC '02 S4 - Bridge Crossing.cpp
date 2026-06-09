// CCC '02 S4 - Bridge Crossing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
vector<pair<string, int>> l(1005);
int ans[1005];
string names [1005];
int main()
{
    cin.tie(NULL);
    int m, q;
    cin >> m >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> l[i].first >> l[i].second;
    }
    for (int i = 1; i <= q; i++)
    {
        int min = 999999999;
        int result = -1;
        for (int j = 1; j <= m; j++)
        {
            if (i - j < 0)
                break;
            int time = 0;
            for (int k = i - j + 1; k <= i; k++)
            {
                time = time > l[k].second ? time : l[k].second;
            }
            int temp = time + ans[i - j];
            if (temp < min)
            {
                min = temp;
                result = i - j;
            }
        }
        if (result != -1)
        {
            ans[i] = min;
            names[i] = names[result];
            names[i] += '\n';
            names[i] += l[result + 1].first;
            for (int j = result + 2; j <= i; j++)
            {
                names[i] += ' ';
                names[i] += l[j].first;
            }
        }
        
    }
    std::cout << "Total Time: " << ans[q] << endl;
    std::cout << names[q];
}
