#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    vector<ll> positives;
    vector<ll> zeros;
    vector<ll> negatives;
    for (auto &a: A) {
        cin >> a;
        if (a > 0) {
            positives.push_back(a);
        } else if (a < 0) {
            negatives.push_back(a);
        } else {
            zeros.push_back(a);
        }
    }

    // corner cases
    // N = 1, K = 1
    // K = N
    // K = 1
    if (N == K) {
        mint ans(1);
        for (auto & a: A) ans*= a;
        cout << ans << endl;
        return 0;
    }

    bool is_always_negative = false;  // TODO
    if (positives.empty() && K % 2 == 1) is_always_negative = true;
    if (negatives.size() == 1 && positives.size() < K) is_always_negative = true;

    if (is_always_negative) {
        if (!zeros.empty()) {
            cout << 0 << endl;
            return 0;
        }
    } else {
        if (positives.size() + ((negatives.size() / 2) * 2) < K) {
            cout << 0 << endl;
            return 0;
        }
    }

    if (!is_always_negative) {
        sort(positives.begin(), positives.end(), greater<>());
        sort(negatives.begin(), negatives.end());

        int i = 0, j = 0;
        mint ans(1);  // TODO: modint
        auto mul_pos = [&](){
            ans *= positives[i];
            ++i;
            --K;
        };
        auto mul_neg = [&]() {
            ans *= negatives[j];
            ans *= negatives[j + 1];
            j += 2;
            K -= 2;
        };
        while(K > 0) {
            // cout << "K = " << K << endl;
            if (i >= positives.size() && j + 1 >= negatives.size()) {
                // cout << "cond #1" << endl; cout << 0 << endl;
                return 0;
            }
            // positivesを使うしかない　
            if (K < 2 || j + 1 >= negatives.size()) {
                // cout << "cond #2" << endl;
                mul_pos();
                continue;
            }
            // negativesを使うしかない　
            if (i >= positives.size()) {
                // cout << "cond #3" << endl;
                mul_neg();
                continue;
            }
            // どちらもつかえる
            if (i + 1 >= positives.size()) {
                // cout << "cond #4" << endl;
                if (K % 2 == 1) {
                    mul_pos();
                } else {
                    mul_neg();
                }
            } else {
                // cout << "cond #5" << endl;
                if (positives[i] * positives[i + 1] < negatives[j] * negatives[j + 1]) {
                    // cout << "cond #5-1" << endl;
                    mul_neg();
                } else {
                    // cout << "cond #5-2" << endl;
                    mul_pos();
                }
            }
        }
        cout << ans << endl;
    } else {
        sort(positives.begin(), positives.end());
        sort(negatives.begin(), negatives.end(), greater<>());

        int i = 0, j = 0;
        mint ans(1);  // TODO: modint
        while(K > 0) {
            // 両方使えない
            if (i >= positives.size() && j >= negatives.size()) {
                cout << 0 << endl;
                return 0;
            }
            // positive使えない
            if (i >= positives.size()) {
                ans *= negatives[j];
                ++j;
                --K;
                continue;
            }
            // negative使えない
            if (j >= negatives.size()) {
                ans *= positives[i];
                ++i;
                --K;
                continue;
            }
            // 両方使える
            if (positives[i] > abs(negatives[j])) {
                ans *= negatives[j];
                ++j;
                --K;
            } else {
                ans *= positives[i];
                ++i;
                --K;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
