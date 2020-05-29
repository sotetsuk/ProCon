#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL<<60;
const ll MAX_N = 17;
ll N, M;
pair<ll, ll> dist[MAX_N][MAX_N];
pair<ll, ll> dp[1<<MAX_N][MAX_N];

pair<ll, ll> tsp(ll S, ll v) {
    if (S == (1<<N) - 1) return v == 0 ? make_pair(0LL, 1LL) : make_pair(INF, 0LL);
    if (dp[S][v].first >= 0) return dp[S][v];
    pair<ll, ll> ret = {INF, 0};
    for (ll u = 0; u < N; ++u) {
        if (dist[u][v].first == INF || (S>>u)&1) continue;
        auto p = tsp(S|(1<<u), u);
        p.first += dist[u][v].first;
        if (p.first > dist[u][v].second) continue;
        if (p.first < ret.first) {
            ret = p;
        } else if (p.first == ret.first) {
            ret.second += p.second;
        }
    }
    return dp[S][v] = ret;
}

int main() {
    cin >> N >> M;
    for (ll i = 0; i < 1<<MAX_N; ++i) for (ll j = 0; j < MAX_N; ++j) dp[i][j] = {-1, -1};
    for (ll i = 0; i < MAX_N; ++i) for (ll j = 0; j < MAX_N; ++j) dist[i][j] = {INF, INF};
    for (ll i = 0; i < M; ++i) {
        ll s, t, d, time; cin >> s >> t >> d >> time; --s; --t;
        dist[s][t] = {d, time};
        dist[t][s] = {d, time};
    }
    tsp(0, 0);
    if (dp[0][0].first == INF) cout << "IMPOSSIBLE" << endl;
    else cout << dp[0][0].first << " " << dp[0][0].second << endl;
    return 0;
}
