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
// ll MOD = 1000000007;
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

const int N = 55;
int h, w, num_w = 0;
char s[N][N];

struct P { int x, y; };

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> s[i][j];
            if (s[i][j] == '.') ++num_w;
        }
    }
    queue<pair<P, int>> q;
    q.emplace(P{0, 0}, 1);
    while (!q.empty()) {
        auto e = q.front(); q.pop();
        auto x = e.first.x;
        auto y = e.first.y;
        auto c = e.second;
        if (x == h - 1 && y == w - 1) {
            cout << num_w - c << endl;
            return 0;
        }
        if (x < 0 || x >= h || y < 0 || y >= w) continue;
        if (s[x][y] == '#') continue;
        s[x][y] = '#';
        for (int k = 0; k < 4; ++k) {
            auto next_x = x + dx[k];
            auto next_y = y + dy[k];
            q.emplace(P{next_x, next_y}, c + 1);
        }
    }
    cout << -1 << endl;
    return 0;
}
