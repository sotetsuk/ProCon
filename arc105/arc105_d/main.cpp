#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll solve(ll N, const vector<ll> & a) {
}

int main() {
    ll T; cin >> T;
    for (int i = 0; i < T; ++i) {
        ll N; cin >> N;
        vector<ll> a(N); for (int j = 0; j < N; ++j) cin >> a[j];
        cout << solve(N, a) << endl;
    }
    return 0;
}
