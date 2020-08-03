#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, D; cin >> N >> D;
    ll cnt = 0;
    for (ll i = 0; i < N; ++i) {
        ll X, Y; cin >> X >> Y;
        if (X * X + Y * Y <= D * D) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
