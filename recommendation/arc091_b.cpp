#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;
    ll ans = 0;
    for (int k = K; k < N; ++k) {
        ll a = (k - K + 1);
        ll b = min(N, (N - K + 1)) / (k + 1);
        ll c = min(a, min(N, (N - K + 1)) % (k + 1));
        ans += a * b + c;
    }
    cout << ans << endl;
    return 0;
}
