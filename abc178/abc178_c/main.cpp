#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://github.com/atcoder-live/library/blob/master/mint.cpp
const std::int64_t mod = 1000000007;
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

int main() {
    ll N; cin >> N;
    mint a = 1;
    for (int i = 0; i < N; ++i) a *= 10;
    mint b = 1;
    for (int i = 0; i < N; ++i) b *= 9;
    mint c = 1;
    for (int i = 0; i < N; ++i) c *= 8;
    cout << a - mint(2) * b + c << endl;
    return 0;
}
