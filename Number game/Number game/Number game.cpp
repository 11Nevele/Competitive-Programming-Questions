#include <iostream>;
using namespace std;
long long ans = 0 ,n;
void count_numbers(long long a) {
    if (a > n)
        return;
    ans++;
    count_numbers(a * 10 + 2);
    count_numbers(a * 10 + 3);
}
int main() {
    cin >> n;
    count_numbers(0);
    cout << ans - 1<< endl;
    return 0;
}