#include <iostream>
#include <string>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
char ans[100005];
int main()
{
    int t = redn();
    while (t--)
    {
        int n = redn(), k = redn(), total = 0;
        
        fill(ans, ans + n + 1, '.');
        char c;
        int LG = -1, LH = -1, LGG = -1000000, LHG = -1000000;
        for(int i = 0; i < n; i++)
        {
            c = getchar();
            if (c == 'G' && LGG + k < i && LG == -1)
                LG = 0;
            else if (c == 'H' && LHG + k < i && LH == -1)
                LH = 0;
            LG = LG < 0 ? LG : LG + 1;
            LH = LH < 0 ? LH : LH + 1;
            if (LG > k)
            {
                LG = -1;
                LGG = i;
                ans[i] = 'G';
                total++;
            }
            else if (LH > k)
            {
                LH = -1;
                LHG = i;
                ans[i] = 'H';
                total++;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (LH == -1 && LG == -1)
                break;
            if (LH != -1 && ans[i] == '.')
            {
                LH = -1;
                ans[i] = 'H';
                total++;
            }
            else if (LG != -1 && ans[i] == '.')
            {
                LG = -1;
                ans[i] = 'G';
                total++;
            }
            
        }
        cout << total << '\n';
        for (int i = 0; i < n; i++)
            putchar(ans[i]);
        putchar('\n');

    }
}
