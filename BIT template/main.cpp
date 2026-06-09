#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647
#define LL long long
#define LL_MAX 9223372036854775807
inline int read() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline long long readLL()
{
    long long ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
inline void write(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
int lowbit(int n) { return n & -n; }
void Change(vector<LL>& arr, int target, LL value)
{
    while (target < arr.size())
    {
        arr[target] += value;
        target += lowbit(target);
    }
}
int Sum(vector<LL>& arr, int target)
{
    LL ans = 0;
    while (target > 0)
    {
        ans += arr[target];
        target -= lowbit(target);
    }
    return ans;
}
int GetRange(vector<LL>& arr, int start, int end)
{
    return Sum(arr, end) - Sum(arr, start - 1);
}

void Program1(vector<LL>& arr)
{
    int op = read(), x = read(), y = read();
    if (op == 1)
    {
        Change(arr, x, y);
    }
    else
    {
        write(GetRange(arr, x, y));
        putchar('\n');
    }
}

class BIT_Max {
private:
    int n;
    vector<int> tree;

public:
    BIT_Max(int size) {
        n = size;
        tree.assign(n + 1, INT_MIN);  // Initialize with negative infinity
    }

    void update(int index, int value) {
        // Update BIT with the max value at index
        while (index <= n) {
            tree[index] = max(tree[index], value);
            index += index & -index;  // Move to next responsible index
        }
    }

    int query(int index) {
        // Find the maximum in range [1, index]
        int max_val = INT_MIN;
        while (index > 0) {
            max_val = max(max_val, tree[index]);
            index -= index & -index;  // Move to parent node
        }
        return max_val;
    }
};

int main() {
    BIT_Max bit(10);

    bit.update(3, 5);
    bit.update(5, 10);
    bit.update(5, 7);

    cout << bit.query(5) << endl;  // Should return 10 (max in range [1,5])
    cout << bit.query(7) << endl;  // Should return 10 (max in range [1,7])
    cout << bit.query(3) << endl;  // Should return 5 (max in range [1,3])

    return 0;
}