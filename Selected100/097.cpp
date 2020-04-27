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

vector<int> A;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll n, m; cin >> n >> m;
    ll d = 0;
    for (int i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        A.push_back(t);
        // if (t % 2 != 0 || t % 4 == 0) {
        //     cout << 0 << endl;
        //     return 0;
        // }
        d = i == 0 ? t / 2 : lcm(d, t / 2);
    }
    for (const int &x: A) {
        if (d % x == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << m / d / 2 + m / d % 2 << endl;
    return 0;
}
