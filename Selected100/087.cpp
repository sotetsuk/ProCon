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
    vector<int> rank;  // height of tree
    vector<ll> size_;
    UnionFind(int m) : par(m), rank(m), size_(m) {
        for(int i = 0; i < m; i++){
            par[i] = i;
            rank[i] = 0;
            size_[i] = 1;
        }
    }
    ll size(int x) {
        return size_[root(x)];
    }
    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        if(same(x, y)) return;
        if(rank[x] < rank[y]) {
            size_[root(y)] += size(x);
            par[root(x)] = root(y);  // make y above
        } else {
            size_[root(x)] += size(y);
            par[root(y)] = root(x);
            if(rank[x] == rank[y]) ++rank[x];
        }
    }
};

int main() {
    ll n, m; cin >> n >> m;
    auto uf = UnionFind(n);
    vector<pii> v;
    for (ll i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b; --a; --b;
        v.emplace_back(make_pair(a, b));
    }
    reverse(v.begin(), v.end());
    ll M = n * (n-1) / 2;
    vector<ll> ans;
    for (const auto &ab: v) {
        ans.push_back(M);
        ll a = ab.first; ll b = ab.second;
        if (!uf.same(a, b)) {
            auto comb = [&](ll i) { ll l = uf.size(i); return (l >= 2) ? l * (l - 1) / 2 : 0; };
            M += (ll)(comb(a) + comb(b));
            uf.unite(a, b);
            M -= (ll)(comb(a));
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto e: ans) cout << e << endl;
    return 0;
}
