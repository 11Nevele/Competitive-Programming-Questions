#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <cstring>
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



int main()
{
    int n = read();
    vector<pair<int, int>> change(n);
    vector<int> points;
	for (auto& i : change)
	{
		i.first = read();
		i.second = read();
		points.push_back(i.first);
		points.push_back(i.second);
	}
    int pre = 0;
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
    
    vector<pair<int, int>> ranges;
	unordered_map<int, int> rangeToInd;

    set<pair<double, int>> line;

	vector<double> order(400005);

    for (int i : points)
    {
        if(pre + 1 < i)
		{
			ranges.push_back({ pre + 1, i - 1 });
            order[ranges.size() - 1] = (ranges.size() * 1000000000);
			rangeToInd[pre + 1] = ranges.size() - 1;
            line.insert({ ranges.size() * 1000000000, pre + 1 });
		}
		ranges.push_back({ i, i });
        order[ranges.size() - 1] = (ranges.size() * 1000000000);
        rangeToInd[i] = ranges.size() - 1;
		line.insert({ ranges.size() * 1000000000, i });
		pre = i;
	}
    if (pre < 1000000000)
    {
        ranges.push_back({ pre + 1, 1000000000 });
        order[ranges.size() - 1] = (ranges.size() * 1000000000);
        rangeToInd[pre + 1] = ranges.size() - 1;
        line.insert({ ranges.size() * 1000000000, pre + 1 });
    }

    for (auto i : change)
    {
		int indA = rangeToInd[i.first], indB = rangeToInd[i.second];
        line.erase({ order[indA], i.first });
        auto it = line.lower_bound({ order[indB], 0 });
		double preOrder = 0.0;
		if (it != line.begin())
			preOrder = (--it)->first;
        double newOrder = (order[indB] + preOrder) / 2.0;
		
		line.insert({ newOrder, i.first });
		order[indA] = newOrder;
    }

    vector<pair<int, int>> indToRange;
    unordered_map<int,int> numToInd;
    for (auto i : line)
    {
		pair<int, int> range = ranges[rangeToInd[i.second]];
		indToRange.push_back({ range.second - range.first + 1, i.second });
    }
    int preLength = indToRange[0].first;
    indToRange[0].first = 1;
    numToInd[indToRange[0].second] = 1;
    for (int i = 1; i < indToRange.size(); ++i)
    {
        int t = indToRange[i].first;
		indToRange[i].first = indToRange[i - 1].first + preLength;
		numToInd[indToRange[i].second] = indToRange[i].first;
		preLength = t;
    }
    
    vector<int> rangeBegin(ranges.size());
	for (int i = 0; i < ranges.size(); ++i)
		rangeBegin[i] = ranges[i].first;

    int q = read();
    while (q--)
    {
        char c = getchar();
        int a = read();
        if (c == 'P')//label to Ind
        {
			auto dif = upper_bound(rangeBegin.begin(), rangeBegin.end(), a);
            --dif;
			int d = a - *dif;
            write(numToInd[*dif] + d),putchar('\n');
        }
        else // ind to num
        {
			auto it = upper_bound(indToRange.begin(), indToRange.end(), make_pair(a, INT_MAX));
			--it;
			write(a - it->first + it->second), putchar('\n');
        }
    }
    return 0;
}