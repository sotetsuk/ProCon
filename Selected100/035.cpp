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

int N, W, t, s;
vector<int> v;
vector<int> w;
vector<vector<int>> dp;

// dp[i][u]: Maximum total values using goods (>=i) under the weight u
// Answer is dp[0][W]
int knapsack(int i, int u) {
    if (i >= N) return 0;
    if (dp[i][u] >= 0) return dp[i][u];
    if (u < w[i]) return knapsack(i + 1, u);
    return dp[i][u] = max(knapsack(i + 1, u), knapsack(i + 1, u - w[i]) + v[i]);
}

// dp element is initialized by 0
int knapsack() {
    for (int i = N - 1; i >= 0; --i) {
        for (int u = 0; u <= W; ++u) {
            if (u - w[i] < 0) dp[i][u] = dp[i + 1][u];
            else dp[i][u] = max(dp[i + 1][u], dp[i + 1][u - w[i]] + v[i]);
        }
    }
    return dp[0][W];
}

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        cin >> t >> s;
        v.push_back(t);
        w.push_back(s);
    }
    dp = vector<vector<int>>(N + 1, vector<int>(W + 1, 0));
    int ans = knapsack();
    cout << ans << endl;
    return 0;
}
