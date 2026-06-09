#include <iostream>
#include<vector>
#include <time.h>
#include <random>
using namespace std;
vector<int> arr(5005);
vector<int> dp(5005);
int n;
//int max = 0;
int LongestSubArray(int i)
{
    int maxLen = 1;
    for (int j = i + 1; j <= n; j++)
    {
        if (arr[j] > arr[i])
        {
            maxLen = max(LongestSubArray(j) + 1, maxLen);
        }
    }
    return maxLen;
}
int LongestSubArrayDP(int i)
{
    int maxLen = 1;
    if (dp[i] != 0)
        return dp[i];
    for (int j = i + 1; j <= n; j++)
    {
        if (arr[j] > arr[i])
        {
            maxLen = max(LongestSubArrayDP(j) + 1, maxLen);
        }
    }
    dp[i] = maxLen;
    return maxLen;
}
int LongestSubArrayDPNonRecursive(int t)
{
    for (int i = n; i >= 0; i--)
    {
        int maxLen = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[j] > arr[i])
                maxLen = max(maxLen, dp[j] + 1);
        }
        dp[i] = maxLen;
    }
    return dp[0];
}

void GenerateNumbers()
{
    for (int i = 1; i <= n; i++)
    {
        arr[i] = rand() % 1000;
    }
}
void Input()
{
    for (int i = 1; i <= n; i++)
    {
        cin >>arr[i] ;
    }
}
int main()
{
    
    cin >> n;
    Input();
    //GenerateNumbers();
    clock_t startTime = clock();
    cout << LongestSubArray(0) - 1<< endl;
    //cout << LongestSubArrayDPNonRecursive(0) - 1<< endl;
    double duration = clock() - startTime;
    //cout << duration / CLOCKS_PER_SEC  << "ms" << endl;
}