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

// namespace
using namespace std;
namespace mp = boost::multiprecision;

// types
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
using mpi = mp::cpp_int;
using mpf = mp::number<mp::cpp_dec_float<1024>>;

int main() {
    ll n, t;
    vector<ll> a;
    vector<ll> b;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
        cin >> t;
        b.push_back(t);
    }
    ll a_min = 0;
    ll tmp_max = numeric_limits<ll>::max();
    for(auto x: a) {
        ll tmp = 0;
        for(auto i: a) {
            tmp += abs(x - i);
        }
        if (tmp < tmp_max) {
            a_min = x;
            tmp_max = tmp;
        }
    }
    ll b_min = 0;
    tmp_max = numeric_limits<ll>::max();
    for(auto x: b) {
        ll tmp = 0;
        for(auto i: b) {
            tmp += abs(x - i);
        }
        if (tmp < tmp_max) {
            b_min = x;
            tmp_max = tmp;
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += abs(a_min - a[i]);
        ans += b[i] - a[i];
        ans += abs(b_min - b[i]);
    }
    cout << ans << endl;

    return 0;
}
