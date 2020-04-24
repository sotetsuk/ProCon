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
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
// using mpi = mp::cpp_int;
// using mpf = mp::number<mp::cpp_dec_float<1024>>;

///////////////////////////////////////////////////////////////
// mod https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
///////////////////////////////////////////////////////////////
// ll MOD = 1000000007;
// ll mod(long long val) {
//     long long res = val % MOD;
//     if (res < 0) res += MOD;
//     return res;
// }
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

int n, m;
int c[25];
int dp[50005];

// int coin(int cost) {
//     if (cost == 0) return 0;
//     if (dp[cost] >= 0) return dp[cost];
//     int ret = INT_MAX;
//     for (int i = 0; i < m; ++i) {
//         if (cost - c[i] >= 0) ret = min(ret, coin(cost - c[i]) + 1);
//     }
//     return dp[cost] = ret;
// }

int coin(int cost) {
    for (int i = 0; i <= cost; ++i) dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 0; i <= cost; ++i)
        for (int j = 0; j < m; ++j)
            dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
    return dp[cost];
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> c[i];
    memset(dp, -1, sizeof(dp));
    int ans = coin(n);
    cout << ans << endl;
    return 0;
}
