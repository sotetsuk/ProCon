#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<ll> A(N); for (int i = 0; i < N; ++i) cin >> A[i];
    ll ans = 0;
    ll curr = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < curr) {
            ans += curr - A[i];
        }
        curr = max(curr, A[i]);
    }
    cout << ans << endl;
    return 0;
}
