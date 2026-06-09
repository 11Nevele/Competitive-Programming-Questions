#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int arr[101][101];
vector<int> ans[100];
int main()
{
    int f = redn(), v = redn();
    for (int i = 1; i <= f; i++)
        for (int j = 1; j <= v; j++)
            arr[i][j] = redn();
    for (int i = 1; i <= f; i++)//aviable flower
    {
        for (int j = 1; j <= v; j++)//loop through vase 
        {
            if (ans[i - 1].size() == 0)
            {
                ans[i].push_back(j);
            }
            for (int k = 0; k < ans[i - 1].size(); k++)
            {

            }
        }
    }
}
