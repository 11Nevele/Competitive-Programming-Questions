// Find First and Last Position of Element in Sorted Array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<istream>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans{ -1, -1 };
    if (!nums.size())
        return ans;

    int l = 0, r = nums.size() - 1, mid;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (nums[mid] < target)
        {
            l = mid + 1;
            continue;
        }
        if (nums[mid] > target)
        {
            r = mid - 1;

        }
        else
            r = mid;
    }
    if (l > nums.size() - 1 || r < 0 || nums[l] != target)
        return ans;
    l = ans[0] = l;
    r = nums.size() - 1;
    while (l < r)
    {
        mid = (l + r + 1) / 2;
        if (nums[mid] < target)
        {
            l = mid + 1;
            continue;
        }
        if (nums[mid] > target)
        {
            r = mid - 1;

        }
        else
            l = mid;
    }
    ans[1] = l;
    return ans;
}
int main()
{
    vector <int> v{2, 2};
    int target;
    cin >> target;
    v = searchRange(v, target);
    cout << v[0] << " " << v[1] << endl;
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
