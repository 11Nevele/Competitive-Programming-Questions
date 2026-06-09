#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <string>
#include <queue>
#define ll long long
using namespace std;
bool xcom(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.first < b.first;
}
bool ycom(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}
int main()
{
    ifstream fin("split.in");
    ofstream fout("split.out");
    int n;
    fin >> n;
    vector<pair<int, int>>arrX(n + 1), arrY(n + 1);
    for (int i = 1; i <= n; i++)
        fin >> arrX[i].first >> arrX[i].second;
    arrY = arrX;
    sort(arrX.begin(), arrX.end(), xcom);
    sort(arrY.begin(), arrY.end(), ycom);
    arrX.push_back({ 0,0 }); arrY.push_back({ 0,0 });
    long long ans = ((ll)1 << 63) - 1;
    int max1 = 0, min1 = (1 << 31) - 1, maxIndex = n, minIndex = 1;
    int firstX = arrX[1].first, lastX = arrX[n].first;
    for (int i = 0; i <= n; i++)
    {
        max1 = max(max1, arrX[i].second), min1 = min(min1, arrX[i].second);
        while (arrX[i + 1].first == arrX[i].first)
        {
            i++;
            max1 = max(max1, arrX[i].second), min1 = min(min1, arrX[i].second);
        }
        int curX = arrX[i].first;
        while (curX >= arrY[maxIndex].first && maxIndex > 0)
            maxIndex--;
        while (curX >= arrY[minIndex].first && minIndex <= n)
            minIndex++;
        ans = min(ans, (ll)(curX - firstX) * (max1 - min1) + (ll)(lastX - arrX[i + 1].first) * (arrY[maxIndex].second - arrY[minIndex].second));
        if (min1 == 0)
            min1 = (1 << 31) - 1;
    }
    max1 = 0, min1 = (1 << 31) - 1, maxIndex = n, minIndex = 1;
    int firstY = arrY[1].second, lastY = arrY[n].second;
    for (int i = 0; i < n; i++)
    {
        max1 = max(max1, arrY[i].first), min1 = min(min1, arrY[i].first);
        while (arrY[i + 1].second == arrY[i].second)
        {
            i++;
            max1 = max(max1, arrY[i].first), min1 = min(min1, arrY[i].first);
        }

        int curY = arrY[i].second;

        while (curY >= arrX[maxIndex].second && maxIndex > 0) maxIndex--;
        while (curY >= arrX[minIndex].second && minIndex <= n) minIndex++;
        ans = min(ans, (ll)(curY - firstY) * (max1 - min1) + (ll)(lastY - arrY[i + 1].second) * (arrX[maxIndex].first - arrX[minIndex].first));
        if (min1 == 0)
            min1 = (1 << 31) - 1;
    }
    fout << (ll)(lastX - firstX) * (lastY - firstY) - ans << "\n";

    return 0;
}
