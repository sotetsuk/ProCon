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
#include <numeric>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

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


int main() {
    int n; cin >> n;
    ll t;
    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (i > 0) v.emplace_back(v[i - 1] + t);
        else v.emplace_back(t);
    }

    for (int k = 1; k <= n; ++k) {
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && i + k - 1 < n) {
                ans = max(ans,  v[i + k - 1] - v[i - 1]);
            } else if (i == 0) {
                ans = max(ans, v[i + k - 1]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
