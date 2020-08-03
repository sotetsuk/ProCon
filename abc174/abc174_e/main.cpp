#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); for (ll i = 0; i < N; ++i) cin >> A[i];
    ld l = 1, r = *max_element(A.begin(), A.end()) + 1;
    while (r - l > 1e-10) {
        ld m = l + (r - l) / 2;
        ll cnt = 0;
        for (ll i = 0; i < N; ++i) {
            cnt += ceil(A[i] / m) - 1;
            if (cnt > K) break;
        }
        // cout << "m = " << m << " cnt = " << cnt << endl;
        if (cnt <= K) {
            r = m;
        } else {
            l = m;
        }
    }
    std::cout << std::setprecision(15);
    cout << ceil(l) << endl;
    return 0;
}
