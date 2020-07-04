#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<pair<ll, ll>> v(N);
    for (ll i = 0; i < N; ++i) {
        ll a, b; cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end(), [](auto x, auto y){ return x.first + x.second > y.first + y.second; });
    ll ans = 0;
    for (ll i = 0; i < N; ++i) {
        const auto &[a, b] = v[i];
        if (i % 2 == 0) ans += a;
        else ans -= b;
    }
    cout << ans << endl;
    return 0;
}
