#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;


template <typename T>
inline void hash_combine(std::size_t& seed, const T& val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t& seed, const T& val) {
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t& seed, const T& val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        return hash_val(p.first, p.second);
    }
};
struct pairhash { template<class T1, class T2>    size_t operator() (const pair<T1, T2>& x) const { hash<T1> h1;        hash<T2> h2;        return h1(x.first) ^ h2(x.second); } };


unordered_map <pair<short, short>, bool, pair_hash> fre;
pair<short, short> arr[2005];

int main()
{

    cin.tie(NULL);
    int n, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        fre[arr[i]] = true;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (fre.find({ arr[i].first, arr[j].second }) != fre.end() && fre.find({ arr[j].first, arr[i].second }) != fre.end())
            {
                int t = abs((arr[i].first - arr[j].first) * (arr[i].second - arr[j].second));
                max = t > max ? t : max;
            }
        }
    }
    std::cout << max << endl;
}