#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> A(N), B(M), S(M+1, 0);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];
    for (int i = 0; i < M; ++i) S[i+1] = S[i] + B[i];
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i <= N; ++i) {
        if (sum > K) break;
        ll j = upper_bound(S.begin(), S.end(), K - sum) - S.begin() - 1;
        ans = max(ans, i + j);
        if (i < N) sum += A[i];
    }
    cout << ans << endl;
    return 0;
}
