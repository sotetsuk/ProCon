#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int N, K;
const int MAX_N = 300005;
unordered_map<ll, vector<ll>> m;
unordered_set<ll> s;
vector<ll> v;
vector<ll> A(MAX_N, 0);
vector<ll> memo(MAX_N, 0);

ll dfs(int i) {
    if (i >= N) return 0;
    if (memo[i] >= 1) return memo[i];
    ll ret = 1;
    ll a = A[i];
    auto lit = lower_bound(v.begin(), v.end(), a - K);
    auto rit = lower_bound(v.begin(), v.end(), a + K + 1);
    // cout << i << " " << a << " " << *lit << " " << *rit << endl;
    for (auto jit = lit; jit != rit; ++jit) {
        ll val = *jit;
        auto it = lower_bound(m[val].begin(), m[val].end(), i + 1);
        if (it != m[val].end()) {
            ret = max(ret, 1 + dfs(*it));
        }
    }
    return memo[i] = ret;
}

int main() {
    cin >> N >> K; for (int i = 0; i < N; ++i) {
        cin >> A[i];
        m[A[i]].push_back(i);
        s.insert(A[i]);
    }
    v = vector<ll>(s.begin(), s.end());
    sort(v.begin(), v.end());
    // for (auto e: v) {
    //     cout << e << ": ";
    //     for (auto e2: m[e]) cout << e2 << " ";
    //     cout << endl;
    // }
    ll ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, dfs(i));
    cout << ans << endl;
    return 0;
}
