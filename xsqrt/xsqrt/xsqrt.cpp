// xsqrt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
using namespace std;
int mySqrt(int x)
{
    int h = 0, t = x / 2;
    while (h <= t)
    {
        int mid = (h + t) / 2;
        if (mid == x / mid)
        {
            return mid;
        }
        if (mid < x / mid)
        {
            h = mid + 1;
        }
        else
        {
            t = mid - 1;
        }
    }
    return h - 1;
}
int main()
{
    int x;
    cin >> x;
    cout << mySqrt(x);
}
