#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
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
    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; ++i) cin >> A[i];

    // setwise
    int g = A[0];
    for (int i = 0; i < N; ++i) {
        g = gcd(g, A[i]);
    }

    if (g != 1) {
        cout << "not coprime" << endl;
        return 0;
    }

    // pairwise
    unordered_set<int> divisors;
    for (int i = 0; i < N; ++i) {
        auto primes = prime_factor(A[i]);
        for (const auto &[p, cnt] : primes) {
            if (divisors.count(p)) {
                cout << "setwise coprime" << endl;
                return 0;
            }
            divisors.insert(p);
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}
