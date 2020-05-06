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

const ll MAX_H = 130, MAX_W = 130;
ll H, W, K, V;
ll A[MAX_W][MAX_W];

void dump() {
    for (int i = 0; i <= H; ++i) {
        for (int j = 0; j <= W; ++j) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    cin >> H >> W >> K >> V;
    memset(A, 0, sizeof(A));
    for (ll i = 0; i < H; ++i) for (ll j = 0; j < W; ++j) cin >> A[i+1][j+1];
    // take care of i <= H and j <= W
    for (int i = 0; i <= H; ++i) for (int j = 0; j < W; ++j) A[i][j+1] += A[i][j];
    for (int j = 0; j <= W; ++j) for (int i = 0; i < H; ++i) A[i+1][j] += A[i][j];
    int ans = 0;
    for (int i0 = 0; i0 < H; ++i0) {
        for (int j0 = 0; j0 < W; ++j0) {
            for (int i1 = i0; i1 <= H; ++i1) {
                for (int j1 = j0; j1 <= W; ++j1) {
                    // volume of [i0, i1) x [j0, j1)
                    auto cost = A[i1][j1] - A[i1][j0] - A[i0][j1] + A[i0][j0];
                    auto v = (i1 - i0) * (j1 - j0);
                    if (cost <= V - v * K) ans = max(ans, v);
                }
            }
        }
    }
    cout << ans << endl;
}
