#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

ll dp[1<<17][18];
ll INF = 1e18;
vector<ll> X(18); vector<ll> Y(18); vector<ll> Z(18);

ll dist(ll a, ll b, ll c, ll p, ll q, ll r) {
    return abs(p - a) + abs(q - b) + max(0LL, r - c);
}

// v: current node
// S: all visited nodes
// dp[S][v]: Minimum total cost from current node v to node 0 given visited nodes
// answer: dp[0][0];
ll tsp(int S, int v, int num_vertex) {
    // cerr << bitset<17>(S) << " " << S << " v = " << v  << endl;
    if (dp[S][v] >= 0) return dp[S][v];
    ll ret = INF;
    for (int u = 0; u < num_vertex; ++u) {
        // cerr << bitset<17>(S) << " v = " << v << " u = " << u << endl;
        if (S == (1<<num_vertex) - 1) return v == 0 ? 0 : INF;
        ll d = dist(X[v], Y[v], Z[v], X[u], Y[u], Z[u]);
        // cerr << "dist = " << d << endl;
        if ((S>>u)&1) continue;
        // cerr << "a" << endl;
        ll n = tsp(S|(1<<u), u, num_vertex);
        // cerr << n << endl;
        ret = min(ret, n + d);  // take care of overflow
        // cerr << "ret = " << ret << endl;
    }
    return dp[S][v] = ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    ll N; cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        cin >> Y[i];
        cin >> Z[i];
    }
    cout << tsp(0, 0, N) << endl;
    return 0;
}
