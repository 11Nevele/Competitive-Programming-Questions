#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define LL long long
bool pp(LL a, LL b)
{
    vector<LL> tmp;
    for (LL i = 1; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            tmp.push_back(i);
            tmp.push_back(a / i);
        }
            
    }
    for (LL i : tmp)
    {
        if (i == 1)
            continue;
        if (b % i == 0)
            return false;
    }
    return true;
}
void output(int a, int b)
{
    cout << a << endl << b << endl;
}
void solve(int n)
{
    cout << 1 << endl;
    //for (int i = 1; i + 3 <= n; i +=4)
    //{
        cout << "2 1\n";
        cout << 2 << " " << 3 << endl << 1 << endl;
    //}
}
int main()
{
    //for (int i = 2; i <= 20; ++i)
      //  for (int j = i + 1; j <= 20; ++j)
        //    cout << i << " " << j << " " << pp(i, j) << endl;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> arr(n);
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];

    }
    if (arr[0] == -1)

    {
        solve(n);
        return true;
    }
    

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % 2)
            odd.push_back(i);
        else
            even.push_back(i);
    }
    if (odd.size() + even.size() * 2 < 4)
    {
        for(int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
            {
                if (!pp(arr[i], arr[j]))
                {
                    cout << "YES\n";
                    cout << 1 << " " << 1 << "\n";
                    cout << i + 1 << "\n" << j + 1 << "\n";
                    return 0;
                }
                for (int k = 0; k < arr.size(); ++k)
                {
                    if (i == k || j == k)
                        continue;
                    if (!pp(arr[i] + arr[j], arr[k]))
                    {
                        cout << "YES\n";
                        cout << 2 << " " << 1 << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        cout << k + 1 << "\n";
                        return 0;
                    }
                }
            }
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (even.size() > 1)
    {
        cout << 1 << " " << 1 << "\n";
        cout << even[0] + 1 << "\n";
        cout << even[1] + 1 << "\n";
    }
    else if (even.size() == 1)
    {
        cout << 2 << " " << 1 << "\n";
        cout << odd[0] + 1 << " " << odd[1] + 1 << "\n";
        cout << even[0] + 1 << "\n";
    }
    else
    {
        cout << 2 << " " << 2 << "\n";
        cout << odd[0] + 1 << " " << odd[1] + 1 << "\n";
        cout << odd[2] + 1 << " " << odd[3] + 1 << "\n";
    }

}
