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
// ll MOD = 1000000007;
//
//  ll mod(ll val) {
//      ll res = val % MOD;
//      if (res < 0) res += MOD;
//      return res;
//  }
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

int D, N;
int T[201];
int A[201];
int B[201];
int C[201];
int dp[201][101];

void dump (int d, int n) {
    for (int i = 0; i <= d; ++i) {
        for (int j = 0; j <= 100; ++j) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    cin >> D >> N;
    memset(T, 0, sizeof(T));
    for (int i = 1; i <= D; ++i) cin >> T[i];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        cin >> B[i];
        cin >> C[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; ++i) if (A[i] <= T[1] && T[1] <= B[i]) dp[1][C[i]] = 0;
    for (int d = 2; d <= D; ++d) {
        for (int i = 0; i < N; ++i) {
            if (A[i] > T[d] || T[d] > B[i]) continue;
            for (int j = 0; j < N; ++j) {
                if (dp[d-1][C[j]] == -1) continue;
                dp[d][C[i]] = max(dp[d][C[i]], dp[d-1][C[j]] + abs(C[j] - C[i]));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; ++i) ans = max(ans, dp[D][i]);
    // dump(D, N);
    cout << ans << endl;
    // cout << setprecision(10);
    return 0;
}
