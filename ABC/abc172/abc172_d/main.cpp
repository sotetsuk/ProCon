#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

unordered_map<int, vector<pii>> m;

std::vector<int> Eratosthenes( const int N )
{
    std::vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}

vector<pii> prime_factorize(int N, const vector<int> &primes) {
    if (m.find(N) != m.end()) return m[N];
    for (const auto &p: primes) {
        if (N % p == 0 && m.find(N / p) != m.end()) {
            auto v = m.at(N/p);
            for (auto &q: v) {
                if (q.first == p) {
                    q.second++;
                    return m[N] = v;
                }
            }
        }
    }
    vector<pii> res;
    int tmp = N;
    for (int a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return m[tmp] = res;
}

template <typename T>
struct PrimeFact {
    vector<T> spf;
    PrimeFact(T N) { init(N); }
    void init(T N) { // 前処理。spf を求める
        spf.assign(N + 1, 0);
        for (T i = 0; i <= N; i++) spf[i] = i;
        for (T i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (T j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    map<T, T> get(T n) { // nの素因数分解を求める
        map<T, T> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};

vector<pii> prime_factorize_(int N) {
    vector<pii> res;
    for (int a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int num(const map<int, int>& primes) {
    int ret = 1;
    for (const auto &p: primes) ret *= p.second + 1;
    return ret;
}

int main() {
    int N; cin >> N;
    int ans = 0;
    // auto primes = Eratosthenes(sqrt(N));
    auto p = PrimeFact<int>(N+1);
    p.init(10000);
    for (int k = 1; k <= N; ++k) {
        // auto p = prime_factorize(k, primes);
        // auto p_ = prime_factorize_(k);
        ans += k * num(p.get(k));
    }
    cout << ans << endl;
    return 0;
}
