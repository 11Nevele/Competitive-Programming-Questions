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
void swap(int& a, int& b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
void Insert(vector<int>& heap, int value)
{
    heap.push_back(value);
    int ind = heap.size() - 1;
    while (ind > 0 && heap[ind] < heap[(ind - 1) >> 1])
    {
        swap(heap[ind], heap[(ind - 1) >> 1]);
        ind = (ind - 1) >> 1;
    }
}
void EarseTop(vector<int>& heap)
{
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    int ind = 0;
    while (true)
    {
        int left = (ind << 1) + 1, right = (ind << 1) + 2;
        bool l = (left < heap.size() && heap[left] < heap[ind]), r = (right < heap.size() && heap[right] < heap[ind]);
        if (l && r)
        {
            if (heap[left] < heap[right])
            {
                swap(heap[ind], heap[left]);
                ind = left;
            }
            else
            {
                swap(heap[ind], heap[right]);
                ind = right;
            } 
        }
        else if (l)
        {
            swap(heap[ind], heap[left]);
            ind = left;
        }
        else if (r)
        {
            swap(heap[ind], heap[right]);
            ind = right;
        }
        else
            break;
    }
}
int main()
{
    int n = read();
    vector<int> heap;
    while (n--)
    {
        char op = read();
        switch (op)
        {
        case 1: 
            int t;
            cin >> t;
            Insert(heap, t);
            break;
        case 2:
            write(heap[0]);
            putchar('\n');
            break;
        case 3:
            if(heap.size() > 0)
                EarseTop(heap);
            break;
        default:
            cout << "WTF\n";
        }
    }
    

}
