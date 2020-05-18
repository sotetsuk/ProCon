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
#include <complex>
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

/////////////////////////////////////////////////////////////////
// https://github.com/atcoder-live/library/blob/master/mint.cpp
/////////////////////////////////////////////////////////////////
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
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
    mint pow(ll t) const {
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
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


int main() {
    ll N; std::cin >> N;
    ll n_zero = 0;
    map<pll, pll> m;
    for (int i = 0; i < N; ++i) {
        ll x, y; std::cin >> x >> y;
        if (x == 0 && y == 0) {
            n_zero++;
            continue;
        }
        if (y < 0) x = -x, y = -y;
        if (x < 0 && y == 0) x = -x;
        auto g = gcd(x, y);
        x /= g;
        y /= g;
        if (x > 0 && y >= 0) m[{x, y}].first++;
        else m[{y, -x}].second++;
    }
    mint ans = 1;
    for (const auto kv: m) {
        auto key = kv.first;
        auto val = kv.second;
        auto s = val.first;
        auto t = val.second;
        // cout << key.first << " " << key.second << " " << s << " " << t << endl;
        mint tmp{1};
        tmp += mint(2).pow(s) - 1;
        tmp += mint(2).pow(t) - 1;
        ans = ans * tmp;
    }
    ans -= 1;
    ans += n_zero;
    cout << ans << endl;
    return 0;
}
