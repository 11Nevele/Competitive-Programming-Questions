#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
bool pcom(const pair<long long, long long>& a, const pair<long long, long long>& b)
{
	return a.second > b.second;
}
bool mcom(const long long& a, const long long& b)
{
	return a > b;
}
int l = 0, r = -1;
long long binary(const vector<pair<long long, long long>>& a, int t)
{
	l = 0;
	if (r == -1)
		r = a.size() - 1;
	if (t > a[a.size() - 1].first)
		return a[r].second;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (a[mid].first < t)
		{
			l = mid;
		}
		else if (a[mid].first > t)
		{
			r = mid - 1;
		}
		else
		{
			return a[mid].second;
		}
	}
	long long ans = a[l].second;
	ans += (t - a[l].first) * ((a[l + 1].second - a[l].second) / (a[l + 1].first - a[l].first));
	return ans;
}
int main()
{
	ifstream fin("rental.in");
	ofstream fout("rental.out");
	int n, m, r;
	fin >> n >> m >> r;
	vector<int> cow(n + 1);
	vector<long long> rent(r + 1);
	vector < pair<long long, long long>> shop(m + 1);
	for (int i = 1; i <= n; i++)fin >> cow[i];
	for (int i = 1; i <= m; i++) { fin >> shop[i].first >> shop[i].second; }
	for (int i = 1; i <= r; i++) { fin >> rent[i]; }
	sort(cow.begin() + 1, cow.end());
	sort(rent.begin()+1, rent.end(), mcom);
	sort(shop.begin()+1, shop.end(), pcom);
	for (int i = 1; i <= n; i++)cow[i] += cow[i - 1];
	for (int i = 1; i <= m; i++) {
		shop[i].second = shop[i - 1].second + shop[i].second * shop[i].first;
		shop[i].first += shop[i - 1].first;
	}
	for (int i = 1; i <= r; i++) { rent[i] += rent[i - 1]; }
	long long ans = 0;
	for (int i = 0; i <= n; i++)//a = rent amount, b = milk amount
	{
		int a = i, b = cow[n] - cow[i];
		if (a > r)
			a = r;
		long long sum = binary(shop, b);
		sum +=rent[a];
		if (sum >= ans)
		{
			ans = sum;
		}
		else
			break;
	}
	cout << ans << endl;
	fout << ans << endl;
}
