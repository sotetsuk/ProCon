#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> P(N), C(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        --P[i];
    }
    ll sum = 0LL;
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        sum += C[i];
    }
    ll Q;
    if (K >= N) {
        Q = K / N;
        K %= N;
    }
    // mmeo[k][i] = iにいて、k回の移動が残っているときに得られるスコア
    ll M = (ll)(*max_element(C.begin(), C.end()));
    auto memo = vector<vector<ll>>(K + 5, vector<ll>(N, 0));
    for (int i = 0; i < N; ++i) memo[1][i] = C[P[i]];
    for (int k = 2; k <= K; ++k) {
        for (int i = 0; i < N; ++i) {
            memo[k][i] = memo[k-1][P[i]] + C[P[i]];
            M = max(memo[k][i], M);
        }
    }
    // for (int k = 1; k <= K; ++k) {
    //     for (int i = 0; i < N; ++i) {
    //         cout << memo[k][i] << " ";
    //     }
    //     cout << endl;
    // }
    cout << sum << endl;
    cout << Q << endl;
    cout << M << endl;
    cout << sum * Q + M << endl;
    cout << sum * max(0LL, Q - 1) + 2 * M << endl;
    if (sum <= 0) {
        cout << M << endl;
    } else {
        cout << sum * Q + M << endl;
    }
    return 0;
}

