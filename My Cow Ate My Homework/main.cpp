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
    ifstream fin("homework.in");
    ofstream fout("homework.out");
    int n;
    fin >> n;
    long long sum = 0;
    vector<int> ans, arr(n + 1), indArr(10005, -1);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        fin >> temp;
        sum += temp;
        arr[i] = temp;
        indArr[temp] = i;
    }
    double max = 0;
    int min = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        sum -= arr[i];
        while (indArr[min] == -1 || indArr[min] <= i)
            min++;
        double temp = sum;
        temp -= min;
        temp = temp / (n - i - 1);
        if (temp > max)
        {
            max = temp;
            ans.clear();
            ans.push_back(i);
        }
        else if (temp == max)
        {
            ans.push_back(i);
        }
    }
    for (int i : ans)
    {
        fout << i << "\n";
        cout << i << "\n";
    }
        
}
