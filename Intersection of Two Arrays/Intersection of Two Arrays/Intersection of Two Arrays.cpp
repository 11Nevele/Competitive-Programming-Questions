// Intersection of Two Arrays.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<algorithm>
#define w(n, l) while (l < n.size() - 1 && n[l] == n[l + 1]) l++;
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int l = 0, r = 0;
    while (l < nums1.size() && r < nums2.size())
    {
        if (nums1[l] == nums2[r])
        {
            w(nums1, l)
            w(nums2, r)
            ans.push_back(nums1[l]);
            l++;
            r++;
            continue;
        }
        if (nums1[l] < nums2[r])
        {
            w(nums1, l)
            l++;
        }
        else
        {
            w(nums2, r)
            r++;
        }
    }
    return ans;
}
int main()
{
    vector<int> a{ 1, 2, 2, 1 };
    vector<int> b{ 2, 2};
    a = intersection(a, b);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
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
