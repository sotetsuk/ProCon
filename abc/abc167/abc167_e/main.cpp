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
#include <iomanip>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

///////////////////////////////////////////////////////////////
// namespace
///////////////////////////////////////////////////////////////
using namespace std;
// namespace mp = boost::multiprecision;

///////////////////////////////////////////////////////////////
// types
///////////////////////////////////////////////////////////////
using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// using mpi = mp::cpp_int;
// using mpf = mp::number<mp::cpp_dec_float<1024>>;

///////////////////////////////////////////////////////////////
// mod https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
///////////////////////////////////////////////////////////////
ll MOD = 98244353;

ll mod(ll val) {
    ll res = val % MOD;
    if (res < 0) res += MOD;
    return res;
}

// ll modinv(ll a) {
//     ll b = MOD, u = 1, v = 0;
//     while (b) {
//         ll t = a / b;
//         a -= t * b; swap(a, b);
//         u -= t * v; swap(u, v);
//     }
//     u %= MOD;
//     if (u < 0) u += MOD;
//     return u;
// }
//
// const int MAX = -1;
// ll fac[MAX], finv[MAX], inv[MAX];
// void com_init() {  // initialize nCk table with O(N)
//     fac[0] = fac[1] = 1;
//     finv[0] = finv[1] = 1;
//     inv[1] = 1;
//     for (int i = 2; i < MAX; i++){
//         fac[i] = fac[i - 1] * i % MOD;
//         inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
//         finv[i] = finv[i - 1] * inv[i] % MOD;
//     }
// }
// ll com(int n, int k){  // nCk
//     if (n < k) return 0;
//     if (n < 0 || k < 0) return 0;
//     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
// }

void dump(const vector<ll> &dp0, const vector<ll> &dp1, ll N) {
    for (int i = 0; i <= N + 1; ++i) {
        cout << dp0[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i <= N + 1; ++i) {
        cout << dp1[i] << "\t";
    }
    cout << endl;
}
int main() {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> dp0(N + 5, 0);
    vector<ll> dp1(N + 5, 0);
    dp0[1] = mod(M);
    ll L = 1;
    for (int k = 0; k < K + 1; ++k) {
        // dump(dp0, dp1, N);
        for (int n = 1; n < N + 1; ++n) {
            if (k != K) dp1[n + 1] = mod(dp0[n]);
            dp0[n + 1] = mod(mod(dp0[n] * (M - 1)) + mod(dp1[n] * (M - 1)));
        }
        ++L;
    }
    cout << mod(dp0[N] + dp1[N]) << endl;
    return 0;
}
