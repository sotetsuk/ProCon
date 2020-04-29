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

const int max_h = 105, max_w = 105;
int h, w;
int a[max_h][max_w];
bool visited[max_h][max_w];
int dx[2][6] = { {-1, 0, 1, 0, 1, -1},  {-1, 0, 1, 0, -1, 1} };
int dy[2][6] = { {0, -1, 0, 1, 1, 1},  {0 ,-1, 0, 1, -1, -1} };

int main() {
    memset(a, 0, sizeof(a));
    memset(visited, false, sizeof(visited));
    cin >> w >> h;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
        cin >> a[i+2][j+2];
        // if (a[i+2][j+2] == 1) cout << i+1 << " " << j+1 << endl;
    }
    queue<pii> q;
    q.emplace(0, 0);
    int ans = 0;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first, y = p.second;
        if (x < 0 || x >= max_h || y < 0 || y >= max_w || a[x][y] == 1) continue;
        if (visited[x][y]) continue;
        visited[x][y] = true;
        for (int k = 0; k < 6; ++k) {
            int m = x % 2;
            int next_x = x + dx[m][k];
            int next_y = y + dy[m][k];
            if (next_x >= 0 && next_x < max_h && next_y >= 0 && next_y < max_w && a[next_x][next_y] == 1) {
                // cout << x-2+1 << "\t" << y-2+1 << "\t" << next_x-2+1 << "\t" << next_y-2+1 << endl;
                ++ans;
                continue;
            }
            q.emplace(next_x, next_y);
        }
    }
    cout << ans << endl;

    return 0;
}
