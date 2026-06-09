#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <string>
#include <queue>
using namespace std;
ifstream fin, fans, myans;
ofstream fout;
#define ll long long

int solution() {
    
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s = to_string(i);
        
        fin.open(s + ".in");
        fans.open(s + ".out");
        fout.open(s + ".ans");
        myans.open(s + ".ans");
        
        clock_t start = clock(), end;
        //fout << 1 << endl;
        solution();
        fout.flush();
        end = clock();
        string a, b;
        bool correct = true;
        while(getline(fans, a, '\n'))
        {
            getline(myans, b, '\n');
            if (a != b)
            {
                correct = false;
                break;
            }
        }
        cout << correct << " " << double(end - start) << endl;
        //fin.clear(), fout.clear(), fans.clear(), myans.clear();
        fin.close(), fout.close(), fans.close(), myans.close();
    }
}
