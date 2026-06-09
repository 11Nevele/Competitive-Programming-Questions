#include <iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
bool isSameTree(TreeNode* p, TreeNode* q)
{
    /*queue<struct TreeNode*> linep, lineq;
    linep.push(p);
    lineq.push(q);
    while (!linep.empty() && lineq.empty())
    {
        struct TreeNode* temp1 = linep.front();
        struct TreeNode* temp2 = lineq.front();
        linep.pop();
        lineq.pop();
        if (temp1->val != temp2->val)
            return false;
        else
        {
            linep.push(temp1->left);
            linep.push(temp1->right);
            lineq.push(temp2->left);
            lineq.push(temp2->right);
        }
    }
    return true;*/
    if (!p || !q)
        return !p & !q;
    if (p->left == NULL && p->right == NULL && q->left == NULL && q->right == NULL)
        return p->val == q->val ? true : false;
    bool temp;
    if (p->left && q->left)
        temp = isSameTree(p->left, q->left);
    else
        return false;
    if (p->right && q->right)
        temp = temp & isSameTree(p->right, q->right);
    else
        return false;
    return temp;
}
int main()
{
    
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
