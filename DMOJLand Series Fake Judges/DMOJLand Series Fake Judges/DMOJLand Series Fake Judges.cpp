#include <iostream>
#include<algorithm>
using namespace std;
unsigned int arr[100000], fre[100001];
bool com(int a, int b) { return a > b; }
int main()
{
	cin.tie(NULL);
	int n, q;
	unsigned long long ans = 0;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		fre[a]++;
		fre[b + 1]--;
	}
	for (int i = 1; i <= n; i++)
	{
		fre[i] += fre[i - 1];
	}
	sort(fre + 1, fre + n + 1, com);
	for (int i = 0; i < n; i++)
	{
		ans += (unsigned long long)arr[i] * (unsigned long long)fre[i + 1];
	}
	cout << ans << endl;
}