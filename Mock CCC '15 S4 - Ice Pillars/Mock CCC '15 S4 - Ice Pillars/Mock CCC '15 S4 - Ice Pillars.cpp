
#include <iostream>
#include<vector>
using namespace std;

long long f(long long x)
{
	if (x < 0)
		return 0;
	return x;
}
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> pre(4);
	vector<long long> cur(4);
	vector<long long> w(n + 2), d(n + 2);

	for (int i = 1; i <= n; ++i)
		cin >> d[i] >> w[i];

	for (int i = 1; i <= n; ++i)
	{
		cur[0] = min(pre[0], pre[1]) + f(d[i] - w[i - 1]);
		cur[1] = min(min(pre[0], pre[1]), min(pre[2], pre[3])) + d[i];
		cur[2] = min(min(pre[0], pre[1]), min(pre[2], pre[3])) + f(d[i] - w[i + 1]);
		cur[3] = min(pre[0], pre[1]) + f(d[i] - w[i - 1] - w[i + 1]);
		pre = cur;
	}

	cout << min(cur[0], cur[1]);
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
