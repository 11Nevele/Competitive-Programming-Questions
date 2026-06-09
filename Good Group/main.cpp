#include <iostream>
#include <string>

#include <unordered_map>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}
unordered_map<string, unordered_map<string, bool>> m1, m2;

int main()
{
    int x = redn();
    
    while (x--)
    {
        string a, b;
        cin >> a >> b;
        m1[a][b] = true;
        //m1[b][a] = true;
    }
    int y = redn();
    while (y--)
    {
        string a, b;
        cin >> a >> b;
        m2[a][b] = true;
    }
    int q = redn();
    int ans = 0;
    while (q--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        if (m1.find(a) != m1.end() && (m1[a].find(b) == m1[a].end() || m1[a].find(c) == m1[a].end()))
        {
            ans++;
            if (m1[a].find(b) == m1[a].end())
                m1[a][b] = true;
            else
                m1[a][c] = true;
        }
        if (m1.find(b) != m1.end() && (m1[b].find(a) == m1[b].end() || m1[b].find(c) == m1[b].end()))
        {
            ans++;
            if (m1[b].find(a) == m1[b].end())
                m1[b][a] = true;
            else
                m1[b][c] = true;
        }
        if (m1.find(c) != m1.end() && (m1[c].find(a) == m1[c].end() || m1[c].find(a) == m1[c].end()))
        {
            ans++;
            if (m1[c].find(a) == m1[c].end())
                m1[c][a] = true;
            else
                m1[c][b] = true;
        }
        if (m2.find(a) != m2.end() && (m2[a].find(b) != m2[a].end() || m2[a].find(c) != m2[a].end()))
        {
            ans++;
            if (m2[a].find(b) != m1[a].end())
                m2[a].erase(b);
            else
                m2[a].erase(c);
        }
        if (m2.find(b) != m2.end() && (m2[b].find(a) != m2[b].end() || m2[b].find(c) != m2[b].end()))
        {
            ans++;
            if (m2[b].find(a) != m1[b].end())
                m2[b].erase(a);
            else
                m2[b].erase(c);
        }
        if (m2.find(c) != m2.end() && (m2[c].find(a) != m2[c].end() || m2[c].find(b) != m2[c].end()))
        {
            ans++;
            if (m2[c].find(a) != m1[c].end())
                m2[c].erase(a);
            else
                m2[c].erase(b);
        }
    }
    cout << ans << endl;
}
