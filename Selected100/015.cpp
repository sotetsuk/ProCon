#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <numeric>

// namespace
using namespace std;
namespace mp = boost::multiprecision;

// types
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
using mpi = mp::cpp_int;
using mpf = mp::number<mp::cpp_dec_float<1024>>;

// consts
int MOD = 1000000007;  // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

ld f(int n) {
    if (n == 1) return 1.0;
    return f(n - 1) * (ld)n;
}

int main() {
    int n, x, y;
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v.emplace_back(make_pair(x, y));
    }
    vector<ld> ds;
    vector<int> p;
    for (int i = 0; i < n; ++i) p.emplace_back(i);
    do {
        ld d = 0.0;
        for (int i = 0; i < n - 1; ++i) {
            int j = p[i];
            int k = p[i+1];
            ld x0 = v[j].first;
            ld y0 = v[j].second;
            ld x1 = v[k].first;
            ld y1 = v[k].second;
            d += sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
        }
        ds.emplace_back(d);
    } while (next_permutation(p.begin(), p.end()));
    ld m = 0;
    ld acc = accumulate(ds.begin(), ds.end(), m);
    std::cout << std::setprecision(15);
    cout << acc / f(n) << endl;
    return 0;
}
