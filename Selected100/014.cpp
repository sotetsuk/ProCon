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


ll solve(ll n, ll k, ll i, vector<ll> &v, const vector<ll> &a) {
    if (n - i < k) return numeric_limits<ll>::max();
    if (i == n) {  // k should be zero
        ll m = a[v[0]];
        ll j = 0;
        for (; j < v[0]; ++j) m = max(m, a[j]);
        ll ret = 0;
        for (const auto &ix: v) {
            ret += max(static_cast<ll>(0), m - a[ix]);
            for (; j < ix; ++j) m = max(m, a[j]);
            m = max(m + 1, a[ix] + 1);
        }
        return ret;
    }

    ll ret = numeric_limits<ll>::max();
    if (k > 0) {
        v.push_back(i);
        ret = min(ret, solve(n, k - 1, i + 1, v, a));
        v.pop_back();
    }
    ret = min(ret, solve(n, k, i + 1, v, a));
    return ret;
}

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    vector<ll> v;
    ll ans = solve(n, k, 0, v, a);
    cout << ans << endl;
    return 0;
}
