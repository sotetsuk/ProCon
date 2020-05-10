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


int main() {
    ll N; ll K;
    cin >> N >> K;
    vector<ll> A;
    vector<ll> v(N, -1);
    for (ll i = 0; i < N; ++i) {
        ll a; cin >> a; --a;
        A.push_back(a);
    }
    ll n = 0;
    v[0] = 0;
    ll k = 0;
    ll m;
    ll o;
    while(true) {
        // cout << n << endl;
        ll next = A[n];
        ++k;
        if (k == K) {
            cout << next + 1 << endl;
            return 0;
        }
        if (v[next] != -1) {
            o = v[next];
            m = k - o;
            break;
        }
        v[next] = k;
        n = next;
    }
    // for (int i = 0; i < N; ++i) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < N; ++i) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    // cout << m << endl;
    K = (K - o) % m + o;
    n = 0;
    k = 0;
    // cout << K << " " << n << endl;
    if (K == 0) {
        cout << n + 1 << endl;
        return 0;
    }
    while(true) {
        // cout << n << endl;
        ll next = A[n];
        ++k;
        if (k == K) {
            cout << next + 1 << endl;
            return 0;
        }
        n = next;
    }
    return 0;
}
