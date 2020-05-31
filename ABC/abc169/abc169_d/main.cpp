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

void sieve(vector<bool> &is_prime) {  // O(n log log n)
    ll n = is_prime.size();
    for (ll i = 0; i < n; ++i) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (ll i = 0; i < n; ++i) {
        if (!is_prime[i]) continue;
        for (ll j = 2 * i; j < n; j += i) is_prime[j] = false;
    }
    for (ll i = 2; i < n; ++i) {
        if (!is_prime[i]) continue;
        for (ll j = i; j < n; j *= i) {
            is_prime[j] = true;
        }
    }
}

map< int64_t, int > prime_factor(int64_t n) {
    map< int64_t, int > ret;
    for(int64_t i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll N; cin >> N;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }
    // vector<bool> is_prime(5e6, false);
    // sieve(is_prime);
    // ll ans = 0;
    // for (int i = 2; i < 5e6; ++i) {
    //     if (N == 1) break;
    //     if (i > 5e6) break;
    //     if (!is_prime[i]) continue;
    //     if (N % i == 0) {
    //         cout << "* " << i  << " " << N / i << endl;
    //         N /= i;
    //         ans++;
    //     }
    // }
    // if (ans == 0) cout << 1 << endl;
    // else cout << ans << endl;
    auto m = prime_factor(N);
    ll ans = 0;
    for(auto &kv: m) {
        int i = 1;
        while (i <= kv.second) {
            ans++;
            kv.second -= i;
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}
