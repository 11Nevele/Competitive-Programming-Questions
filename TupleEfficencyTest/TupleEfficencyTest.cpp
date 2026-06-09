#include <iostream>
#include <tuple>
#include <ctime>
#include <random>
#include <unordered_map>
using namespace std;
int main()
{
	tuple<vector<int>> testTuple;
	vector<int> map(100000);
	for (int i = 0; i < 100000; i++)
	{
		map[i] = rand();
	}
	get<0>(testTuple).resize(100000);
	clock_t start = clock();

	for (int i = 0; i < 100000; i++)
	{
		int b = map[rand() % 100000];
		get<0>(testTuple)[b] = rand();
		get<0>(testTuple)[b] *= 132;
		get<0>(testTuple)[b] /= 32;
		get<0>(testTuple)[b] += 1245123;
		get<0>(testTuple)[b] -= 4312;

		//testVector[b][a] = rand();
	}
	cout << "Tuple time: " << (double)(clock() - start) / CLOCKS_PER_SEC << endl;

	

	
}
