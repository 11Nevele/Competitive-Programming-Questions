#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <algorithm>
#define lowbit(x) (x&(-x))
using namespace std;

// 使用一个全局变量来表示数组的最大长度
const int MAXN = 100005;
// 使用一个哈希表来表示树状数组
unordered_map <int, int> bit;
// 使用一个数组来存储输入的数据
int arr[MAXN];
// 使用一个数组来存储离散化后的数据
int brr[MAXN];

// 定义一个函数来计算排名
int getRank(int x) {
    int rank = 0;
    // 从x开始向下遍历树状数组，累加每个节点的值
    for (int i = x; i; i -= lowbit(i)) {
        rank += bit[i];
    }
    return rank;
}

// 定义一个函数来更新树状数组
void update(int x) {
    // 从x开始向上遍历树状数组，更新每个节点的值
    for (int i = x; i <= MAXN; i += lowbit(i)) {
        bit[i]++;
    }
}

int main() {
    cin.tie(NULL);
    int t, cnt = 0;
    long long ans = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
        // 把输入的数据复制到另一个数组中
        brr[i] = arr[i];
    }
    // 对复制后的数组进行排序
    sort(brr, brr + t);
    // 对输入的数据进行离散化，把它们映射到1到t之间
    for (int i = 0; i < t; i++) {
        arr[i] = lower_bound(brr, brr + t, arr[i]) - brr + 1;
    }
    for (int i = 0; i < t; i++) {
        int temp = arr[i], r = 0;
        cnt++;
        // 调用函数计算排名
        r = getRank(temp);
        // 调用函数更新树状数组
        update(temp);
        ans += cnt - r;
    }
    cout << fixed << setprecision(2) << (float)ans / t << endl;
    return 0;
}
