// Search a 2D Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int l = 0, r = matrix.size() - 1, mid, n;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (matrix[mid][0] < target)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    n = l, l = 0, r = matrix[n].size() - 1;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (matrix[n][mid] == target)
            return true;
        if (matrix[n][mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
int main()
{
    vector <vector<int>>v { {1, 3, 5, 7}, { 10, 11, 16, 20 }, { 23, 30, 34, 60 }};
    int target;
    cin >> target;
    cout << searchMatrix(v, target);
    return 0;
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
