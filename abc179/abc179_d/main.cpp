#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://github.com/atcoder-live/library/blob/master/mint.cpp
const std::int64_t mod = 998244353;
struct mint {
    std::int64_t x; // typedef long long ll;
    mint(std::int64_t x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(std::int64_t t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
std::istream& operator>>(std::istream& is, const mint& a) { return is >> a.x;}
std::ostream& operator<<(std::ostream& os, const mint& a) { return os << a.x;}

const ll MAX_N = 200005;
vector<mint> a(MAX_N, 0);
vector<mint> memo(MAX_N, 0);
vector<pair<ll, ll>> ranges;

int main() {
    ll N, K; cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        ll l, r; cin >> l >> r;
        ranges.emplace_back(l, r);
    }
    a[0] = 1;
    for (int n = 0; n < N; ++n) {
        if (n > 0) memo[n] += memo[n-1];
        a[n] += memo[n];
        for (const auto& [l, r] : ranges) {
            memo[min(n + l, MAX_N - 1)] += a[n];
            memo[min(n + r + 1, MAX_N - 1)] -= a[n];
        }
    }
    // for (int i = 0; i < 10; ++i) std::cout << i << "\t"; cout << endl;
    // for (int i = 0; i < 10; ++i) std::cout << a[i] << "\t"; cout << endl;
    // for (int i = 0; i < 10; ++i) std::cout << memo[i] << "\t"; cout << endl;
    cout << a[N - 1] << endl;
    return 0;
}
