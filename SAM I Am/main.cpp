#include <iostream>
#include <vector>
#include <string>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
vector<vector<pair<int, char>>> adj;

int dfs(string& str, int n, int s)
{
    if (str.empty())
    {
        return s;
    }
}
int main()
{
    string s;
    cin >> s;
    int q = redn();
    while (q--)
    {
        int c = getchar();
        if (c == 'C')
        {
            int n = redn();
            char t = getchar();
            getchar();
            adj.push_back(vector<pair<int,char>>());
            adj[n].push_back({ adj.size(), t });

        }
        else
        {
            string t;
            cin >> t;
            if (t[0] != s[0])
            {
                cout << "-1\n";
                continue;
            }
            t.reserve();
            bool b = false;
            for (int i = 0; i < s.size(); i++)
            {
                if (t.back() == s[i])
                {
                    t.pop_back();
                }
                else
                {
                    b = true;
                    break;
                }
                if (t.empty())
                {
                    b = true;
                    break;
                }
            }
            if (b)
            {
                cout << "1\n";
                continue;
            }
            int ans = 1;

        }
    }

}
