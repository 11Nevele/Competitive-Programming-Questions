#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> fre(100005);
bool binary(int v, int tl, int tr)
{
    vector<int> arr = fre[v];
    int l = 0, r = arr.size() - 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] < tl)
            l = mid + 1;
        else if (arr[mid] > tr)
            r = mid - 1;
        else
            return true;

    }
    return false;
}
bool func(int l, int r, int x)
{
    for (int i = 1; i * i < x; i++)
    {
        if ((x % i) != 0)
            continue;
        int j = x / i;
        if (binary(i, l, r) && binary(j, l, r))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int t ;
        scanf_s("%d", &t);
        fre[t].push_back(i);
    }
    for (int i = 0; i < q; i++)
    {
        int l, r, x;
        scanf_s("%d%d%d", &l, &r, &x);
        if (func(l, r, x))
            printf("YES\n");
            
        else
            printf("NO\n");
    }
}
