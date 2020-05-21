#include <bits/stdc++.h>

// https://github.com/atcoder-live/library/blob/master/mint.cpp
const std::int64_t mod = 10007;
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

const std::int32_t MAX_N = 1005;
mint dp[MAX_N][1<<3];

int main() {
    std::unordered_map<char, std::int32_t> m = { {'J', 0 }, {'O', 1 }, {'I', 2 }   };
    std::int32_t N; std::cin >> N;
    std::string s; std::cin >> s;
    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    for (std::uint32_t i = 0; i < N; ++i) {
        for (std::uint32_t b1 = 0; b1 < 1<<3; ++b1) {
            for (std::uint32_t b2 = 0; b2 < 1<<3; ++b2) {
                if (!(1<<m[s[i]]&b2)) continue;
                bool ok = false;
                for (std::uint32_t j = 0; j < 3; ++j) {
                    if ((1<<j&b2) && (1<<j&b1)) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    dp[i+1][b2] += dp[i][b1];
                }
            }
        }
    }
    mint ans = 0;
    for (std::uint32_t i = 0; i < 8; ++i) {
        ans += dp[N][i];
    }

    std::cout << ans << std::endl;
}