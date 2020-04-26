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
int MOD = 10000;
//
// ll mod(long long val) {
//     long long res = val % MOD;
//     if (res < 0) res += MOD;
//     return res;
// }
//
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

const int N = 105;
int n, k, a, b;
int determined[N];
int dp[N][3][2];  // dp[n][t][m] = # of possible patterns end withs source t is used for the last m days during first n days

int main() {
    cin >> n >> k;
    memset(determined, -1, sizeof(determined));
    for (int i = 0; i < k; ++i) {
        cin >> a >> b; --a; --b;
        determined[a] = b;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int t1 = 0; t1 < 3; ++t1) {
            if (determined[i] != -1 && determined[i] != t1) continue;
            if (i == 0) dp[i+1][t1][0] = 1;
            for (int t0 = 0; t0 < 3; ++t0) {
                if (t1 == t0) continue;
                for (int d0 = 0; d0 < 2; ++d0) {
                    dp[i+1][t1][0] += dp[i][t0][d0];
                    dp[i+1][t1][0] %= MOD;
                }
            }
            dp[i+1][t1][1] += dp[i][t1][0];
            dp[i+1][t1][1] %= MOD;
        }
    }
    int ans = 0;
    for (int t = 0; t < 3; ++t) {
        for (int d = 0; d < 2; ++d) {
            ans += dp[n][t][d];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
