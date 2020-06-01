#include <bits/stdc++.h>

int main() {
    using namespace std;
    using ll = long long;

    int N; std::cin >> N;
    std::vector<ll> A(N + 1), B(N + 1);
    for (int i = 0; i <= N; ++i) cin >> A[i];
    B[N] = A[N];
    for (int i = N - 1; i >= 0; --i) B[i] = B[i + 1] + A[i];
    B[0] = 1;
    for (int i = 1; i <= N; ++i) B[i] = min(B[i], 2 * (B[i - 1] - A[i - 1]));
    ll ans = 0;
    for (int i = 0; i <= N; ++i) {
        if (B[i] < A[i]) {
            cout << -1 << endl;
            return 0;
        }
        ans += B[i];
    }
    cout << ans << endl;
    return 0;
}
