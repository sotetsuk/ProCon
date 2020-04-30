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

struct UnionFind{
    vector<int> par;
    UnionFind(int m) : par(m) {
        for (int i = 0; i < m; i++) par[i] = i;
    }
    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        if (!same(x, y)) par[root(x)] = root(y);
    }
};

struct edge { int i, j, cost; };

int main() {
    int N; cin >> N;
    vector<pii> xs;
    vector<pii> ys;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        xs.emplace_back(t, i);
        cin >> t;
        ys.emplace_back(t, i);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    vector<edge> v;
    for (int k = 0; k < N - 1; ++k) {
        auto i = xs[k].second;
        auto j = xs[k+1].second;
        v.emplace_back(edge{i, j, abs(xs[k].first - xs[k+1].first)});
    }
    for (int k = 0; k < N - 1; ++k) {
        auto i = ys[k].second;
        auto j = ys[k+1].second;
        v.emplace_back(edge{i, j, abs(ys[k].first - ys[k+1].first)});
    }
    auto comp = [](edge e1, edge e2){ return e1.cost < e2.cost; };
    sort(v.begin(), v.end(), comp);
    UnionFind uf(N);
    int total_cost = 0;
    for (const auto &e : v) {
        if (uf.same(e.i, e.j)) continue;
        uf.unite(e.i, e.j);
        total_cost += e.cost;
    }
    cout << total_cost << endl;
    return 0;
}
