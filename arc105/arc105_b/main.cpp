#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> v(N);
    map<ll, ll> m;
    set<ll> s;
    for (ll i = 0; i < N; ++i) {
        cin >> v[i];
        m[v[i]]++;
        s.insert(v[i]);
    }
    ll x = m.begin()->first;
    ll X = m.rbegin()->first;
    while(m.size() > 1) {
        s.erase(X);
        ll next_X = *s.rbegin();
        ll a = (X - next_X) % x == 0 ? (X - next_X) / x : (X - next_X) / x + 1;
        // std::cerr << "m.size()=" << m.size() << " x=" << x << " X=" << X << " next_X=" << next_X << " a=" << a << endl;
        // for (const auto& [k, v]: m) std::cerr << k << ":" << v << ",";
        // std::cerr << std::endl;
        // std::cerr << m.begin()->first << ":" << m.begin()->second << endl;
        // std::cerr << m.rbegin()->first << ":" << m.rbegin()->second << endl;
        ll X_prime = X - a * x;
        m[X_prime] += m[X];
        m.erase(X);
        s.insert(X_prime);
        x = m.begin()->first;
        X = m.rbegin()->first;
    }
    cout << m.begin()->first << endl;
    return 0;
}
