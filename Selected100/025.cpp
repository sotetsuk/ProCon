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

int w, h;
vector<vector<int>> c;

bool dfs(int i, int j) {
    if (c[i][j] == 0) return false;
    c[i][j] = 0;
    if (i - 1 >= 0) dfs(i - 1, j);
    if (i + 1 < h) dfs(i + 1, j);
    if (j - 1 >= 0) dfs(i, j - 1);
    if (j + 1 < w) dfs(i, j + 1);
    if (i - 1 >= 0 && j - 1 >= 0) dfs(i - 1, j - 1);
    if (i - 1 >= 0 && j + 1 < w) dfs(i - 1, j + 1);
    if (i + 1 < h && j + 1 < w) dfs(i + 1, j + 1);
    if (i + 1 < h && j - 1 >= 0) dfs(i + 1, j - 1);
    return true;
}

bool solve() {
    cin >> w >> h;
    if (w == 0 && h == 0) return false;
    c = vector<vector<int>>(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans += dfs(i, j);
        }
    }
    cout << ans << endl;
    return true;
}

int main() {
    while (solve());
    return 0;
}
