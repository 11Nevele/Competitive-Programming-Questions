#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector <int> road(200005), ans(200005), c(200005);
int main()
{
    int k = redn(), m = redn(), n = redn();

    for (int i = 0; i < k; i++)
    {
        int a = redn(), b = redn();
        road[a] = b;
    }
    for (int i = 0; i < m; i++)
    {
        c[i] = redn();
    }
    sort(c.begin(), c.begin() + m );
    
    
    for (int i = 0; i < m; i++)
    {
        int l, r = c[i];
        if (i == 0)
            l = -1;
        else
            l = c[i - 1];
        if (l + 1 == r)
            continue;
        long long sum = 0;
        queue<int> t;
        for (int j = l + 1; j < r; j++)
        {
            if (!t.empty())
            {
                int node = t.front();
                if (l != -1 && abs(node - l) >= abs(node - j))
                {
                    sum -= node;
                    t.pop();
                }
                else if (abs(node - r) > abs(node - j))
                {
                    sum -= node;
                    t.pop();
                }
            }
            if (road[j] != 0)
            {
                sum += road[j];
                t.push(j);
            }
            ans[j] += sum;
        }
        sum = 0;
        while (!t.empty())
            t.pop();
        int l2 = l == -1 ? 0 : l;
        for (int j = r - 1; j > l2; j--)
        {
            if (!t.empty())
            {
                int node = t.front();
                if (l != -1 && abs(node - l) > abs(node - j))
                {
                    sum -= node;
                    t.pop();
                }
                else if (abs(node - r) >= abs(node - j))
                {
                    sum -= node;
                    t.pop();
                }
            }
            if (road[j] != 0)
            {
                sum += road[j];
                t.push(j);
            }
            ans[j - 1] += sum;
        }
        
    }

}
