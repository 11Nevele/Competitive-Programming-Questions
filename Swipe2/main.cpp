#include <iostream>
#include <vector>
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
    vector<int>a(n), b(n), dif(n);
    vector<pair<int, int>> left, right;
    for (int& i : a)
        i = redn();
    for (int& i : b)
        i = redn();
    int cnt = 0;
    int ind = 0;
    for (int i = 0; i < n; i++)
    {
        if (ind < i)
            ind = i;
        int temp = ind;
        while (ind < n && b[i] != a[ind])
        {
            ind++;
        }

        if (ind < n && (i == 0 || b[i] != b[i - 1]))
        {
            for (int j = i; j < ind; j++)
                a[j] = a[ind];
            if (ind != i)
                cnt++;
            left.push_back({ i, ind });
        }
        if (ind >= n)
            ind = temp;
    }
    ind = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (ind > i)
            ind = i;
        int temp = ind;
        while (ind >= 0 && b[i] != a[ind])
        {
            ind--;
        }

        if (ind >= 0 && (i == n - 1 || b[i] != b[i + 1]))
        {
            for (int j = ind; j <= i; j++)
                a[j] = a[ind];
            if (ind != i)
                cnt++;
            right.push_back({ ind, i });
        }
        if (ind <= 0)
            ind = temp;
    }
    bool ans = true;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            ans = false;
            break;
        }
    if (ans)
    {
        cout << "YES\n";
        cout << cnt << "\n";
        for (auto i : left)
        {
            if (i.first != i.second)
                cout << "L " << i.first << " " << i.second << "\n";
        }
        for (auto i : right)
        {
            if (i.first != i.second)
                cout << "R " << i.first << " " << i.second << "\n";
        }

    }
    else
    {
        cout << "NO\n";
    }

}
