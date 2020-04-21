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

int N, W;
vector<int> v;
vector<int> w;
vector<int> dp;

// dp[i][u]: Maximum value using products (<i) under the weight limit <=u
//   dp[i][u] = max_k(dp[i-1][u - k * w[i]] + k * v[i])

int knapsack() {
    for (int i = 0; i < N; ++i)
        for (int u = 0; u <= W; ++u)
            for (int k = 0; k * w[i] <= u; ++k)
                dp[i+1][u] = max(dp[i+1][u], dp[i][u - k * w[i]] + k * v[i]);
    return dp[N][W];
}

int knapsack() {
    for (int i = 0; i < N; ++i)
        for (int u = 0; u <= W; ++u)
            dp[i+1][u] = w[i] <= u ? max(dp[i][u], dp[i+1][u - w[i]] + v[i]) : dp[i][u];
    return dp[N][W];
}

int knapsack() {
    for (int i = 0; i < N; ++i)
        for (int u = w[i]; u <= W; ++u)
            dp[u] = max(dp[u], dp[u - w[i]] + v[i]);
    return dp[W];
}

int main() {
    cin >> N >> W;
    int s, t;
    for (int i = 0; i < N; ++i) {
        cin >> s >> t;
        v.push_back(s);
        w.push_back(t);
    }
    dp = vector<int>(W + 5, 0);
    int ans = knapsack();
    cout << ans << endl;
    return 0;
}
