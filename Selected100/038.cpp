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

vector<vector<int>> dp;

int lcs(const string &x, const string &y, int i, int j) {
    if (i >= x.size() || j >= y.size()) return 0;
    if (dp[i][j] >= 0) return dp[i][j];
    int ret = 0;
    ret = max(ret, lcs(x, y, i + 1, j));
    ret = max(ret, lcs(x, y, i, j + 1));
    if (x[i] == y[j]) ret = max(ret, lcs(x, y, i + 1, j + 1) + 1);
    return dp[i][j] = ret;
}

int lcs(const string &x, const string &y) {
    for (int i = x.size() - 1; i >= 0; --i) {
        for (int j = y.size() - 1; j >= 0; --j) {
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j + 1]);
            if (x[i] == y[j]) dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
        }
    }
    return dp[0][0];
    // return lcs(x, y, 0, 0);
}

int main() {
    int n;
    string x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        dp = vector<vector<int>>(x.size() + 5, vector<int>(y.size() + 5, 0));
        cout << lcs(x, y) << endl;
    }
    return 0;
}
