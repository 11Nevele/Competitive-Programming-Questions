#include <iostream>
using namespace std;
void f(char s, char m, char e, int cnt)
{
    if (cnt == 1)
    {
        cout << s << " -> " << e << endl;
        return;
    }
    f(s, e, m, cnt - 1);
    cout << s << " -> " << e << endl;
    f(m, s, e, cnt - 1);
    return;

}
int main()
{
    int n;
    cin >> n;
    f('A', 'B', 'C', n);
}
