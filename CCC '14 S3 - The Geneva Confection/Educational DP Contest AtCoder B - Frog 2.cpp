#include <iostream>
#include <stack>
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
int main()
{
    int t = redn();
    while (t--)
    {
        std::stack<int> mountain;
        std::stack<int>branch;

        int n = redn();
        int target = 1;
        for (int i = 0; i < n; i++)
        {
            mountain.push(redn());
        }

        while (true)
        {
            if (mountain.empty() && branch.empty())
            {
                std::cout << "Y\n";
                break;
            }
            if (branch.size() > 0 && branch.top() == target) {
                // if the top car on branch is the target, move it to lake
                branch.pop();
                target++; // increment target
            }
            else if (mountain.size() > 0 && mountain.top() == target) {
                // if the top car on mountain is the target, move it to lake
                mountain.pop();
                target++; // increment target
            }
            else if (mountain.size() > 0) {
                // otherwise, move a car from mountain to branch
                branch.push(mountain.top());
                mountain.pop();
            }
            else 
            {
                std::cout << "N\n";
                break;
            }
        }
    }
}
