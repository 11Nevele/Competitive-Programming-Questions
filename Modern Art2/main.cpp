#include <iostream>
#include <vector>
using namespace std;
inline int redn() {
    int ret = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -f; ch = getchar(); }
    while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}

long long f(int i, const vector<long long> &p, const vector<long long>& w, const vector<long long>& d)
{
    long long sum = 0;
    for (int j = 0; j < p.size(); j++)
    {
        long long t = (abs(p[j] - i) - d[j]) * w[j];
        if (t > 0)
            sum += t;
    }
    return sum;
}
int main()
{
    int n = redn();
    cin >> n;
    cout << n;

    vector<long long> p(n), w(n), d(n);
    long long l = ((long long)1 << 63) - 1, r = 0;
    for (int i = 0; i < n; i++)
    {
        p[i] = redn();
        l = min(l, p[i]);
        r = max(r, p[i]);
        w[i] = redn();
        d[i] = redn();
    }
    while(l < r)
    {
        int mid = (l + r) / 2;
        long long a = f(mid, p, w, d), b = f(mid + 1, p, w, d);
        if (a < b)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << f(l, p,w,d) << endl;
}
