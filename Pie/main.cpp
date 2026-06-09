#include <iostream>
using namespace std;

int n, m, l = 1, r = 1, cnt = 1, ans = 10000000, al = 0, ar = 0;
int arr[1000001] = { 0 };
int barrel[1000] = { 0 };

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    barrel[arr[1]]++;

    while (true)
    {
        if (cnt == m)
        {
            if (ans > r - l) {
                ans = r - l;
                al = l;
                ar = r;
            }
            barrel[arr[l]]--;
            if (barrel[arr[l]] == 0) {
                cnt--;
            }

            l++;
        }

        else if (r < n)
        {
            r++;
            barrel[arr[r]]++;
            if (barrel[arr[r]] == 1)
            {
                cnt++;
            }
        }

        else {
            break;
        }

    }

    cout << al << " " << ar;
}