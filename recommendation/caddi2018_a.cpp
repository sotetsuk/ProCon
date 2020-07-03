#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<ll, ll> prime_factor(ll n) {
    unordered_map<ll, ll> primes;
    for (ll p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
            primes[p]++;
            n /= p;
        }
    }
    if (n != 1) primes[n]++;
    return primes;
}

int main() {
    ll N, P; cin >> N >> P;
    auto primes = prime_factor(P);
    ll gcd = 1LL;
    for (const auto&[prime, power] : primes) gcd *= pow(prime, power/ N);
    cout << gcd << endl;
    return 0;
}
