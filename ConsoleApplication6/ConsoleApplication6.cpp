#include <iostream>
#include <unordered_map>
#include <vector>
#include <any>
using namespace std;

//a class with a template that stores two vectors
template <typename T>
class TwoVectors
{
public:
	vector<T> vec1;
	vector<T> vec2;
	TwoVectors(vector<T> v1, vector<T> v2) : vec1(v1), vec2(v2) {}
};
//unordered_map that can store any type of TwoVectors
unordered_map<string, any> map;
//how do I make sure only TwoVectors can be stored in the map?

int main()
{
	vector<int> v1 = { 1,2,3 };
	using t = typeid(v1);

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
