#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, x; cin >> N >> x;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < N-1; ++i) {
        if (a[i] + a[i+1] <= x) continue;
        ans += a[i] + a[i+1] - x;
        a[i+1] = max(0LL, a[i+1] - (a[i] + a[i+1] - x));
        a[i] -= max(0LL, a[i] + a[i+1] - x);
    }
    cout << ans << endl;
    return 0;
}
