#include <iostream>
#define MAX 5280
using namespace std;
int nums[33];
int dp[MAX + 1]{MAX};
int main() 
{

    int t, n;
    cin >> t >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i <= t; i++)
        dp[i] = MAX;
    dp[0] = 0;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[j] <= i) {
                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
            }
        }
    }
    if (dp[t] != MAX)
        cout << "Roberta wins in " << dp[t] << " strokes.\n";
    else
    {
        cout << "Roberta acknowledges defeat.\n";

    }
        
    return 0;
}