#include <iostream>
using namespace std;
int FindGreatestCommonFactor(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
//quick sort
void quickSort(int a[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = a[(left + right) / 2];
	/* partition */
	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);
}
//binary search
int binarySearch(int a[], int left, int right, int x)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearch(a, left, mid - 1, x);
		return binarySearch(a, mid + 1, right, x);
	}
	return -1;
}
//binary search that find the first element that is small than x
int binarySearchFirst(int a[], int left, int right, int x)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return binarySearchFirst(a, left, mid - 1, x);
		return binarySearchFirst(a, mid + 1, right, x);
	}
	return right;
}
//希尔排序
void shellsort()
{
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << FindGreatestCommonFactor(a, b);
	return 0;
}
