#include <iostream>
#include <vector>
#include <algorithm> 
#include <random>       // std::default_random_engine
#include<time.h>
using namespace std;
vector<int> box(101);
vector<int> randL(100);
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        box[i] = i;
        randL[i - 1] = i;
    }
    int a = 0, b = 0;
    for (int k = 0; k < 10000; k++)
    {

        shuffle(box.begin() + 1, box.end(), default_random_engine(time(0)));
        int cnt = 0;
        for (int i = 1; i <= 100; i++)
        {
            int cur = i;
            for (int j = 0; j < 50; j++)
            {
                if (i == box[cur])
                {
                    cnt++;
                    break;
                }
                cur = box[cur];
            }
        }
        if (cnt == 100)
        {
            int cur = 1;
            for (int j = 0; j < 50; j++)
            {
                std::cout << cur << endl;
                cur = box[cur];
            }
            cur = 50;
            for (int j = 0; j < 50; j++)
            {
                std::cout << cur << endl;
                cur = box[cur];
            }
            return 0;
        }
            
        cnt = 0;
        for (int i = 1; i <= 100; i++)
        {
            shuffle(randL.begin(), randL.end(), default_random_engine(time(0)));
            for (int j = 0; j < 50; j++)
            {
                if (i == box[randL[j]])
                {
                    cnt++;
                }
            }
        }
        if (cnt == 100)
            b++;
    }
    std::cout << a << endl << b << endl;
    return 0;
}

