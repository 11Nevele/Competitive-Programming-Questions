#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int M = 26;

vector<vector<bool>> mp(60, vector<bool>(60));
vector<int> v(60);

class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    
    int getParent(int x)
    {
        if (parent[x] == x)
            return x;
        int p = getParent(parent[x]);
        parent[x] = p;
        return p;
    }
    bool unite(int a, int b)
    {
        int pa = getParent(a), pb = getParent(b);
        int sa = size[pa], sb = size[pb];
        if (pa == pb)
            return false;
        if (sa > sb)
        {
            //merge b to a
            parent[pb] = pa;
            size[pa] += size[pb];
        }
        else
        {
            parent[pa] = pb;
            size[pb] += size[pa];
        }

        return  true;
    }

};

bool dfs(int x)
{
    if (v[x] == 1)
        return true;
    v[x] = 1;
    bool ans = false;
    for (int i = 0; i <= 52; ++i)
    {
        if (mp[x][i])
        {
            if (v[i] == 0)
            {
                ans |= dfs(i);
            }
            if (v[i] == 1)
                return true;
        }
    }
    v[x] = 2;
    return ans;
}

int neg(int x)
{
    return  (-(x - M)) + M;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a[4]{};
        for (int j = 0; j < 4; ++j)
        {
            cin >> a[j];
            a[j] += M;
        }
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                if (j == k)
                    continue;
                if (a[j] == M || a[k] == M)
                    continue;
                mp[neg(a[j])][a[k]] = true;
            }
        }
    }

    bool ans = false;
    for (int i = 0; i <= 52; ++i)
    {
        for(int j)
    }
    cout << (int)ans << endl;
    


}
/*
2
1 1 1 1
-1 0 0 0
*/