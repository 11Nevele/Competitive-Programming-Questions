#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using namespace std;
int main()
{
    vector<int>p(100, 100);
    srand(time(0));
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            int t1 = rand() % 100;
            p[j]--;
            p[t1]++;
        }
        if (i % 100 == 1)
        {
            for (int j = 0; j < 100; j++)
                cout << p[j] << " ";
            cout << endl << endl;
        }
    }
}
