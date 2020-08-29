#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool is_triangle(ll a, ll b, ll c) {
    if (a == b || b == c || c == a) return false;
    // cout << "debug1" << endl;
    if (a + b > c && b + c > a && c + a > b) return true;
    // cout << "debug2" << endl;
    return false;
}

int main() {
    int N; cin >> N;
    vector<ll> v(N); for (int i = 0; i < N; ++i) cin >> v[i];
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                // cout << "===" << endl;
                // cout << i + 1  << " " << j + 1  << " " << k + 1 << endl;
                // cout << "===" << endl;
                if (is_triangle(v[i], v[j], v[k])) ++ ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
