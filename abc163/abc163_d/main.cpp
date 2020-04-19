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

long long modinv(long long a) {
    long long b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

long long mod(long long val) {
    long long res = val % MOD;
    if (res < 0) res += MOD;
    return res;
}

ll dp[200005];

ll f(ll n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = mod(n + f(n - 1));
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < 200005; ++i) dp[i] = -1;
    for (ll i = k; i <= n + 1; ++i) {
        // cout << "===" << endl;
        // cout << "k = " << i << endl;
        // cout << "===" << endl;
        ll m = f(i - 1);  // i = 2 => f(1) = 1, i = 3 => f(2) = 3, i = 1 => f(0) = 0
        ll M = f(n);
        ll d = f(n - i);
        auto c = mod(mod(M - d) - m + 1);
        // cout << "m = " << m << ", M = " << M << ", d = " << d << "c = " << c << endl;
        ans += c;
        ans = mod(ans);
    }
    cout << ans << endl;
    return 0;
}
