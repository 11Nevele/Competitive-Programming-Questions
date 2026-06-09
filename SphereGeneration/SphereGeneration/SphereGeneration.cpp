#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926
int main()
{
    float radius = 100;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            float theta = 2 * (float)PI * i / 20;
            float phi = (float)PI * j / 20;
            
            cout << fixed << "new Vector(" << sinf(phi) * cos(theta) * radius << ", " << 
                radius * sin(phi) * sin(theta) << ", " <<
                radius * cos(phi)<<")\n";
            
        }
    }
}
