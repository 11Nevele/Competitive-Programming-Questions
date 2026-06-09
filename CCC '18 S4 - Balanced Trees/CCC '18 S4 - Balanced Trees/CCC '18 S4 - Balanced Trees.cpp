#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;
#define LL long long

unordered_map<int, LL> mp;

LL f(LL x)
{
	if (x == 1)
		return 1;
	if (mp[x])
		return mp[x];
	
	LL res = 0;
	//i is weight of subtree
	for (LL i = 1; i * i <= x; ++i)
	{
		res += f(i) * ((x / i) - (x / (i+1)));
	}
	//i is number of segment
	for (LL i = 2; (x / i) * (x / i) > x; ++i)
	{
		res += f(x / i);
	}
	mp[x] = res;
	return res;



}

int main()
{
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << f(n) << endl;
	return 0;
}
