#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, M, K; cin >> N >> M >> K;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];
    ll s = accumulate(B.begin(), B.end(), 0LL);
    int j = M;
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        while (j > 0 && K < s) {
            --j;
            s -= B[j];
        }
        if (K >= s) ans = max(ans, i + j);
        if (i < N) s += A[i];
    }
    cout << ans << endl;
    return 0;
}
