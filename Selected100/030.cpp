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


int main() {
    int h, w, n; cin >> h >> w >> n;
    vector<vector<char>> c(h, vector<char>(w, '.'));
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int sx, sy;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> c[i][j];
            if (c[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    struct P { int x, y, c; };
    queue<P> q;
    char target = '1';
    q.push(P{sx, sy, 0});
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.x;
        int y = p.y;
        int cnt = p.c;
        if (x < 0 || x >= h || y < 0 || y >= w) continue;
        if (c[x][y] == 'X') continue;
        if (visited[x][y]) continue;
        visited[x][y] = true;
        // cout << c[x][y] << endl;
        if (c[x][y] == target && c[x][y] == '0' + n) {
            // cout << x << " " << y << " " << target << endl;
            cout << cnt << endl;
            return 0;
        }
        if (c[x][y] == target) {
            // cout << x << " " << y << " " << target << endl;
            for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) visited[i][j] = false;
            ++target;
            while (!q.empty()) q.pop();
        }
        q.push({x + 1, y, cnt + 1});
        q.push({x - 1, y, cnt + 1});
        q.push({x, y + 1, cnt + 1});
        q.push({x, y - 1, cnt + 1});
    }
    return 0;
}
