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
using pii = pair<int, int>;
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

const int MAX_N = 5005;
int N, K;
int C[MAX_N];
int R[MAX_N];
unordered_map<int, vector<int>> edges;
int d[MAX_N];

void visit(int curr, int r, vector<bool> &visited, vector<int> &nodes) {
    // cout << "visit " << curr << endl;
    if (visited[curr]) return;
    if (r < 0) return;
    visited[curr] = true;
    nodes.push_back(curr);
    for (const auto &next : edges[curr]) {
        visit(next, r - 1, visited, nodes);
    }
}
void dump() {
    for (int i = 0; i < N; ++i) {
        cout << d[i] << "\t";
    }
    cout << endl;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> C[i] >> R[i];
    }
    for (int i = 0; i < K; ++i) {
        int u, v; cin >> u >> v; u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    priority_queue<pii, vector<pii>, greater<>> q;
    for (int i = 0; i < MAX_N; ++i) d[i] = INT_MAX;
    d[0] = 0;
    q.push(pii{0, 0});
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        auto curr = p.second;
        auto cost = p.first;
        // cout << "=========" << endl;
        // cout << curr << " " << C[curr] << " " << R[curr] << endl;
        // cout << "=========" << endl;
        // dump();
        if (d[curr] < cost) continue;
        vector<bool> visited(N, false);
        vector<int> nodes;
        visit(curr, R[curr], visited, nodes);
        for (const auto &next: nodes) {
            // cout << "  " << curr << " " << next << endl;
            if (curr != next && d[curr] != INT_MAX && d[next] > d[curr] + C[curr]) {
                d[next] = d[curr] + C[curr];
                q.push(pii{d[next], next});
            }
        }
    }
    cout << d[N-1] << endl;
    return 0;
}
