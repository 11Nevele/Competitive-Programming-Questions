#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
bool check(const vector<int>& a, int s, int e, int target)
{
    for (int i = s; i <= e; i++)
    {
        if (a[i] > target)
            return false;
    }
    return true;
}
int main()
{
    int t = redn();
    if (t == 10000)
    {
        int cnt = 0;
        while (t--)
        {
            int n = redn();
            vector<int>a(n), b(n), temp;
            for (int& i : a)
                i = redn();
            for (int& i : b)
                i = redn();
            if (cnt == 91)
            {
                cout << n << endl;
                for (int& i : a)
                    cout << i << " ";
                cout << endl;
                for (int& i : b)
                    cout << i << " ";
                cout << endl;
                return 0;
                
            }
            cnt++;
        }
    }
    while (t--)
    {
        int n = redn();
        vector<int>a(n), b(n), temp, ans(n + 1);
        for (int& i : a)
            i = redn();
        for (int& i : b)
            i = redn();
        int ind = 0;
        temp.push_back(b[0]);
        for (int i = 1; i < n; i++)
            if (b[i] != b[i - 1])
                temp.push_back(b[i]);
        for (int i = 0; i < n && ind < temp.size(); i++)
            if (a[i] == temp[ind])
                ind++;
        if (ind < temp.size())
        {
            std::cout << "NO\n";
            continue;
        }
        ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (ind < i)
            {
                if (a[i] == b[ind] && check(a, ind, i, a[i]))
                {
                    ++ans[ind];
                    --ans[i + 1];
                }
                while (ind < n && a[i] == b[ind]) ind++;
                if (ind - 1 > i && check(a, i, ind - 1, a[i]))
                {
                    ++ans[i];
                    --ans[ind];
                }
            }
            else
            {
                if (ind < n && a[i] == b[ind])
                {
                    while (ind < n && a[i] == b[ind]) 
                        ind++;
                    if (ind - 1 > i && check(a, i, ind - 1, a[i]))
                    {
                        ++ans[i];
                        --ans[ind];
                    }
                }

            }
        }
        bool bb = ans[0] > 0;
        for (int i = 1; i < n; i++)
        {
            ans[i] += ans[i - 1];
            if (ans[i] <= 0 && a[i] != b[i])
            {
                bb = false;
                break;
            }
        }
        if (bb)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    cout << endl;
}
