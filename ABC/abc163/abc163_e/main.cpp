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
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mpi = mp::cpp_int;
using mpf = mp::number<mp::cpp_dec_float<1024>>;

// consts
int MOD = 1000000007;  // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a

struct Swap { ll v; int x; int y; };

int main() {
    ll n, a;
    cin >> n;
    vector<pll> v;
    for (ll i = 0; i < n; ++i) {
        cin >> a;
        v.emplace_back(make_pair(a, i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INT_MIN));
    dp[0][0] = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i <= k + 1; ++i) {
            int j = k - i + 1;
            // k = 0 i = 0 j = 1
            // k = 0 i = 1 j = 0
            // k = n-1 i = 0 j = n
            // k = n-1 i = n j = 0
            ll A = v[k].first;
            ll i0 = v[k].second;
            if (i-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + A * abs(i - 1 - i0));
            if (j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + A * abs(n - j - i0));
            // cout << "i " << i << "\tj " << j << "\ti0 " << i0 << "\tA " << A << "\tdp[i][j] " << dp[i][j] << endl;
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        ll j = n - i;
        ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
    return 0;
}
