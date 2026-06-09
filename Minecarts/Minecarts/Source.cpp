#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define LL long long
int lowbit(int n) { return n & -n; }
void Change(vector<LL>& arr, int target, LL value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int Sum(vector<LL>& arr, int target)
{
    LL ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
int GetRange(vector<LL>& arr, int start, int end)
{
    return Sum(arr, end) - Sum(arr, start - 1);
}
vector<LL> bit(1000005);
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n + 1);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        arr[i]++;
    }
		
    
    int mx = 0;
    for (int i = 0; i < n; ++i)
    {
        LL t = i - Sum(bit, arr[i]);
        if (t > mx)
            mx = t;
        Change(bit, arr[i], 1);
    }
    cout << mx << endl;

}
