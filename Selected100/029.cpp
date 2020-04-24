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

int r, c, sy, sx, gy, gx;
char grid[55][55];

struct P {
    pii p;
    int n;
};

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

int main() {
    cin >> r >> c;
    cin >> sy >> sx >> gy >> gx;
    for (int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    queue<P> q;
    q.push(P{make_pair(sy-1, sx-1), 0});
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.p.first;
        int x = p.p.second;
        int n = p.n;
        // cout << y << " "  << x << " " << n << endl;
        if (grid[y][x] == '#') continue;
        if (y == gy-1 && x == gx-1) {
            cout << n << endl;
            return 0;
        }
        grid[y][x] = '#';
        for (int k = 0; k < 4; ++k) {
            int y_next = y + dy[k];
            int x_next = x + dx[k];
            if (0 <= y_next && y_next < r && 0 <= x_next && y_next < c && grid[y_next][x_next] == '.') {
                q.push(P{make_pair(y_next, x_next), n + 1});
            }
        }
    }

    return 0;
}
