#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MOD1 354745078340568241
#define MOD2 354745078340568217
unordered_map<long long, int> mp1;
unordered_map<long long, int> mp2;


int main()
{
    string str;
    cin >> str;
    int q;
    cin >> q;
    long long c1 = 0;
    long long c2 = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        c1 = c1 * 27 + (str[i] - 'a' + 1);
        c1 = c1 % MOD1;
        mp1[c1] = 1;

        c2 = c2 * 27 + (str[i] - 'a' + 1);
        c2 = c2 % MOD2;
        mp2[c2] = 1;
    }
    vector<string> strs;
    vector<long long> hashs1;
    vector<long long> hashs2;
    hashs1.push_back(c1);
    hashs2.push_back(c2);
    while (q--)
    {
        char op;
        cin >> op;
        if (op == 'C')
        {
            int ind;
            char c;
            cin >> ind >> c;

            long long tmp = hashs1[ind - 1];
            tmp = tmp * 27 + (c - 'a' + 1);
            tmp = tmp % MOD1;
            hashs1.push_back(tmp);
            if (mp1.find(tmp) == mp1.end())
                mp1[tmp] = hashs1.size();

            tmp = hashs2[ind - 1];
            tmp = tmp * 27 + (c - 'a' + 1);
            tmp = tmp % MOD2;
            hashs2.push_back(tmp);
            if (mp2.find(tmp) == mp2.end())
                mp2[tmp] = hashs2.size();
        }
        else
        {
            string str;
            cin >> str;
            int curInd = -1;

            long long c1 = 0;
            long long c2 = 0;
            for (int i = 0; i < str.size(); ++i)
            {
                c1 = c1 * 27 + (str[i] - 'a' + 1);
                c1 = c1 % MOD1;

                c2 = c2 * 27 + (str[i] - 'a' + 1);
                c2 = c2 % MOD2;

                if (mp1.find(c1) != mp1.end())
                        curInd = mp1[c1];
            }
            cout << curInd << endl;
        }
    }
}
