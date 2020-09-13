#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll dist(pll a, pll b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll optimize(const pll &init, const vector<pll> &v) {
    pll p = init;
    pll q = init;
    ll max_d = 0;
    bool updated = true;
    while (updated) {
        updated =false;
        for (const auto &c: v) {
            ll d_ = dist(p, c);
            if (d_ > max_d) {
                q = c;
                max_d = d_;
                updated = true;
            }
        }
        if (updated) p = q;
    }
    return max_d;
}

int main() {
    ll N; cin >> N;
    vector<pll> v(N);
    for (int i = 0; i < N; ++i) {
        ll x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    ll ans = 0;
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<int> d(0, N - 1);
    for (int i = 0; i < 2000; ++i) {
        int r = d(mt);
        ans = max(ans, optimize(v[r], v));
    }
    ans = max(ans, optimize(v[0], v));
    ans = max(ans, optimize(v[N-1], v));
    for (int i = 0; i < N - 1; ++i) {
        ans = max(ans, dist(v[i], v[i + 1]));
    }
    cout << ans << endl;
    return 0;
}
