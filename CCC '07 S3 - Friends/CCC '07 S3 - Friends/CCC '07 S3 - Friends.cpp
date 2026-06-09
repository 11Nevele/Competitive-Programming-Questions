#include <iostream>
#include<vector>
#include <list>
using namespace std;
vector<vector<int>>v(10000);
bool arr[10000];
int DPSUntil(int node, int target, int step)
{
	arr[node] = true;
	if (node == target)
	{
		return step;
	}
	int min = 99999;
	for (int i = 0; i < v[node].size(); i++)
	{
		if (!arr[v[node][i]])
		{
			int temp = DPSUntil(v[node][i], target, step + 1);
			min = min < temp ? min : temp;
		}
		
	}
	return min;
}
int main()
{
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
	}
	while (true)
	{
		cin >> a >> b;
		if (a == 0)
			break;
		b = DPSUntil(a, b, -1);
		if (b != 99999)
			cout << "yes " << b;
		else
			cout << "No";
		memset(arr, false, n + 1);
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
