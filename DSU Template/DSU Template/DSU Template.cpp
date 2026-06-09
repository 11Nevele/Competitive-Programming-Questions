// DSU Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
class DSU
{
 
public:
    std::vector<size_t> parent;
    std::vector<size_t> cnt;
    DSU(size_t size):parent(size), cnt(size, 1)
    {
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }
    size_t Find(size_t x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Unite(size_t a, size_t b)
    {
        int pa = parent[Find(a)], pb = parent[Find(b)];
        if (pa == pb)
            return;
        if (cnt[pa] > cnt[pb])
        {
            cnt[pa] += cnt[pb];
            parent[pb] = pa;
        }
        else
        {
            cnt[pb] += cnt[pa];
            parent[pa] = pb;
        }
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            dsu.Unite(a, b);
        }
        else
        {
            putchar(dsu.Find(a) == dsu.Find(b) ? 'Y' : 'N');
            putchar('\n');
        }
    }
}
