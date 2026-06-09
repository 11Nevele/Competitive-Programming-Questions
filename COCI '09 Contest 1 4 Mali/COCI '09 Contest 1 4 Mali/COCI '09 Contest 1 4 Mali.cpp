#include <iostream>
using namespace std;
short arrA[102];
short arrB[102];
int main()
{
    int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        int temp, t = 0;
        cin >> temp;
        arrA[temp]++;
        cin >> temp;
        arrB[temp]++;
        int ans = 0;
        int i = 1, j = 100;
        short tarrA[101], tarrB[101];
        copy(arrA, arrA + 101, tarrA);
        copy(arrB, arrB + 101, tarrB);
        while (true)
        {
            while (!tarrA[i])
                i++;
            while (!tarrB[j])
                j--;
            if (i > 100 || j < 1)
                break;
            ans = ans > i + j ? ans : i + j;
            int temp = tarrA[i] < tarrB[j] ? tarrA[i] : tarrB[j];
            tarrA[i] -= temp;
            tarrB[j] -= temp;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
