#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, Q; cin >> N >> Q;
    unordered_map<ll, ll> m;
    vector<ll> cnt(N);
    vector<unordered_map<ll, ll>> acc(N+1);
    for (int i = 0; i < N; ++i) {
        unordered_map<ll, ll> n = m;
        ll c; cin >> c;
        if (n.find(cnt[c]) != n.end()) n[cnt[c]]--;
        cnt[c]++;
        n[cnt[c]]++;
        acc[i+1] = n;
        m = n;
    }
    for (int i = 0; i < Q; ++i) {
        ll l, r; cin >> l >> r;
        auto m1 = acc[r];
        auto m2 = acc[l-1];
        ll ans = 0;
        for (auto [k, v] : m1) {
            ans += v - m2[k];
        }
        cout << ans << endl;
    }
    return 0;
}
