#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, X, M; cin >> N >> X >> M;
    map<ll, pair<ll, ll>> m;
    // vector<ll> v(M, -1);  // v[a(i)] = a(i+1)
    // a0 = X
    // a1 = f(a0^2, M) = a0 * a0 % M
    // a2 = f(a1^2, M) = a1 * a1 % M
    ll a = X;
    ll i = 0;
    while(m.count(a) == 0) {
        m[a] = {(a % M) * (a % M) % M, i};
        a = m[a].first;
        ++i;
    }
    ll cycle_start = a;
    ll cycle_size = i - m.at(a).second;
    ll cycle_sum = 0;
    while(true) {
        cycle_sum += a;
        a = m[a].first;
        if (a == cycle_start) break;
    }

    // for (const auto &[k, v]: m) {
    //     cout << k << "\t" << v.first << "\t" << v.second << endl;
    // }
    // cout << cycle_start << endl;
    // cout << cycle_size << endl;
    // cout << cycle_sum << endl;

    ll ans = 0;
    a = X;
    while(a != cycle_start && N > 0) {
        ans += a;
        a = m[a].first;
        --N;
    }
    // std::cout << "p1 " << ans << endl;
    ans += (N / cycle_size) * cycle_sum;
    N = N % cycle_size;
    // std::cout << "p2 " << ans << endl;
    while(N > 0) {
        ans += a;
        a = m[a].first;
        --N;
    }
    // std::cout << "p3 " << ans << endl;
    cout << ans << endl;
    return 0;
}
