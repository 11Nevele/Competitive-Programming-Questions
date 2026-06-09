#include <iostream>
using namespace std;

int psa[500005];
int main()
{
    int n, l, q;
    cin >> n >> l >> q;
    for (int i = 0; i < l; ++i)
    {
        int s, r;
        cin >> s >> r;
        int a = max(1, s - r);
        int b = min(n, s + r);
        psa[a]++;
        psa[b + 1]--;
    }
    for (int i = 1; i <= n; ++i)
        psa[i] += psa[i - 1];
    while (q--)
    {
        int x;
        cin >> x;
        if (psa[x])
            cout << "Y\n";
        else
            cout << "N\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
