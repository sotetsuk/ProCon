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


int grid[100][100];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int dfs(int i, int j) {
    if (i < 0 || i >= 100 || j < 0 || j >= 100 || grid[i][j] == 0) return 0;
    int ret = 0;
    grid[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        auto next_x = i + dx[k];
        auto next_y = j + dy[k];
        ret = max(ret, dfs(next_x, next_y));
    }
    grid[i][j] = 1;
    return ret + 1;
}

int main() {
    int n, m; cin >> n >> m;
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> grid[i+5][j+5];
    int ans = 0;
    for (int i = 0; i < 100; ++i) for (int j = 0; j < 100; ++j) ans = max(ans, dfs(i, j));
    cout << ans << endl;
    // cout << setprecision(10);
    return 0;
}
