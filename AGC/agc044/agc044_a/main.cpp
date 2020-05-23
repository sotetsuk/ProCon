#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll N, ll A, ll B, ll C, ll D, unordered_map<ll, ll> &memo) {
    // cout << N << endl;
    if (N == 0) return 0;
    if (N == 1) return D;
    if (memo.find(N) != memo.end()) return memo[N];
    ll N2 = (N / 2) * 2;
    ll N3 = (N / 3) * 3;
    ll N5 = (N / 5) * 5;
    ll ret = 1e18;
    if (N < ret / D) ret = N * D;
    ret = min(ret, solve(N2 / 2, A, B, C, D, memo) + A + D * abs(N - N2));
    if (N % 2 != 0) ret = min(ret, solve((N2 + 2) / 2, A, B, C, D, memo) + A + D * abs(N2 + 2 - N));
    ret = min(ret, solve(N3 / 3, A, B, C, D, memo) + B + D * abs(N - N3));
    if (N % 3 != 0) ret = min(ret, solve((N3 + 3) / 3, A, B, C, D, memo) + B + D * abs(N3 + 3 - N));
    ret = min(ret, solve(N5 / 5, A, B, C, D, memo) + C + D * abs(N - N5));
    if (N % 5 != 0) ret = min(ret, solve((N5 + 5) / 5, A, B, C, D, memo) + C + D * abs(N5 + 5 - N));
    return memo[N] = ret;
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
        unordered_map<ll, ll> memo;
        ll ans = solve(N, A, B, C, D, memo);
        cout << ans << endl;
    }

    return 0;
}
