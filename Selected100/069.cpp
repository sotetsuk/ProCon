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

void sieve(vector<bool> &is_prime) {  // O(n log log n)
    int n = is_prime.size();
    for (int i = 0; i < n; ++i) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 0; i < n; ++i) {
        if (!is_prime[i]) continue;
        for (int j = 2 * i; j < n; j += i) is_prime[j] = false;
    }
}

int main() {
    int N = 100005;
    vector<bool> is_prime(N + 5, false);
    sieve(is_prime);
    vector<int> v(N + 5, 0);
    for (int i = 1; i <= N; ++i) {
        v[i] += v[i-1];
        if (i % 2 == 1 && is_prime[i] && is_prime[(i + 1) / 2]) ++v[i];
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        cout << v[r] - v[l-1] << endl;
    }
    return 0;
}
