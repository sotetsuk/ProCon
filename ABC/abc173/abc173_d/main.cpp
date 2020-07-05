#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N; cin >> N;
    vector<ll> A(N); for (ll i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end(), greater<>());
    ll ans = 0;
    ll j = 0, k = 0;
    for (int i = 0; i < N; ++i) {
        // cout << i << " " << A[j] << " " << j << " " << k << endl;
        if (i == 0) continue;
        if (i == 1) {
            ans += A[j];
            ++j;
            continue;
        }
        if (k == 2) {
            ++j;
            k = 0;
        }
        ans += A[j];
        ++k;
    }
    cout << ans << endl;
    return 0;
}
