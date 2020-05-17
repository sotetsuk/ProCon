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
#include <iomanip>
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
using P = pair<int, int>;
using pll = pair<ll, ll>;
// using mpi = mp::cpp_int;
// using mpf = mp::number<mp::cpp_dec_float<1024>>;

///////////////////////////////////////////////////////////////
// mod https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
///////////////////////////////////////////////////////////////
// ll MOD = 1000000007;
//
//  ll mod(ll val) {
//      ll res = val % MOD;
//      if (res < 0) res += MOD;
//      return res;
//  }
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

struct edge { int from, to, cost; };

vector<int> dijkstra(int start, int num_vertex, map<int, vector<edge>> &edges) {
    priority_queue<P, vector<P>, greater<>> q;
    vector<int> d(num_vertex, INT_MAX);
    d[start] = 0;
    q.push(P{0, start});
    while (!q.empty()) {
        P p = q.top(); q.pop();
        if (d[p.second] < p.first) continue;
        for (const auto &e: edges[p.second]) {
            if (d[e.from] != INT_MAX && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                q.push(P{d[e.to], e.to});
            }
        }
    }
    return d;
}

int main() {
    int N, M; std::cin >> N >> M;
    map<int, vector<edge>> edges;
    for (int i = 0; i < M; ++i) {
        int a, b; std::cin >> a >> b; --a; --b;
        edges[a].push_back(edge{a, b, 1});
        edges[b].push_back(edge{b, a, 1});
    }
    auto d = dijkstra(0, N, edges);
    vector<int> ans;
    for (int i = 1; i < N; ++i) {
        bool ok = false;
        for (auto &e: edges[i]) {
            if (d[i] - 1 == d[e.to]) {
                ans.push_back(e.to + 1);
                ok = true;
                break;
            }
        }
        if (!ok) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    for (const auto &a : ans) {
        std::cout << a << std::endl;
    }

    // cout << setprecision(10);
    return 0;
}
