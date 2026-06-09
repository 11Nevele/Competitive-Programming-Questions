#include <iostream>
using namespace std;
int arr[100005];
long bit[100005];
int ncount[100005];
int lowbit(int x)
{
	return x & (-x);
}
int main()
{
    int n, m;
    long long sum = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j += lowbit(j))
            bit[j] += arr[i];
        for(int j = arr[i]; j <= 100005; j += lowbit(j))
			ncount[j]++;
    }
    for (int i = 0; i < m; i++)
    {
        char op;
        getchar();
        scanf("%c", &op);
        switch (op)
        {
        case 'Q':
            int v;
            sum = 0;
            cin >> v;
            for (; v; v -= lowbit(v)) sum += ncount[v];
            printf("%lld\n", sum);
            break;
        case 'C':
            int temp, a, b;
            scanf("%d%d", &a, &b);
            temp = arr[a];
            arr[a] = b;
            for (int i = a; i <= n; i += lowbit(i))
			{
				bit[i] = bit[i] + b - temp;
			}
            for(int i = b; i <= 100000; i += lowbit(i))
                ncount[i]++;
            for(int i = temp; i <= 100000; i += lowbit(i))
                ncount[i]--;
            break;
        case 'S':
            int l, r;
            scanf("%d%d", &l, &r);
			sum = 0;
            for (int i = r; i; i -= lowbit(i)) sum += bit[i];
            for (int i = l - 1; i; i -= lowbit(i)) sum -= bit[i];
            printf("%lld\n", sum);
            break;
        }
    }
    return 0;
}
