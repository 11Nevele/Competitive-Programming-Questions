#include <iostream>
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int fre1[26];
char m1[3][3];
int fre2[26];
int main()
{
    int a1 = 0, a2 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char t = getchar();
            fre1[t - 'A']++;
            m1[i][j] = t;
        }
            
        getchar();
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char t = getchar();
            if (t == m1[i][j])
            {
                a1++;
                fre1[t - 'A']--;
            }
                
            else
                fre2[t - 'A']++;
        }

        getchar();
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (fre1[i] > fre2[i])
            a2 += fre2[i];
        else
            a2 += fre1[i];
    }
    std::cout << a1 << "\n" << a2 << std::endl;
}
