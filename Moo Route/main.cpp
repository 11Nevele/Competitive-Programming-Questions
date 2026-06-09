#include <iostream>
#include <vector>
#include <stack>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
void output(int cnt, int ind, int i)
{
    
    for (int k = 0; k < cnt; k++)
        for (int l = 0; l < 2; l++)
        for (int j = 0; j < (i - ind); j++)
            
                if (l == 0) putchar('L');
                else putchar('R');
}
int main()
{
    int n = redn();
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) arr[i] = (redn() >> 1);
    for (int i = n; i > 0; i--) arr[i] -= arr[i - 1];
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            putchar('R');
            if (arr[i] > 0)
                s.push({ i, arr[i] });
        }
        else
        {
            int t = -arr[i];
            while (t > 0)
            {
                int cnt = 0;//number of loop
                int ind = s.top().first;//target index
                if (s.top().second > t)
                {
                    t = 0;
                    cnt = s.top().second;
                }
                else
                {
                    cnt = s.top().second;
                    t -= cnt;
                    s.pop();
                }
                output(cnt, ind, i);
                    
            }
            putchar('R');
        }
    }
    int t = -arr[n];
    while (t > 0)
    {
        int cnt = 0;//number of loop
        int ind = s.top().first;//target index
        if (s.top().second > t)
        {
            t = 0;
            cnt = s.top().second;
        }
        else
        {
            cnt = s.top().second;
            t -= cnt;
            s.pop();
        }
        if (s.empty())
            output(cnt - 1, ind, n);
        else
            output(cnt, ind, n);
    }
    for (int i = 0; i < n; i++)putchar('L');
    putchar('\n');
}
