#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> grid;
vector<vector<vector<ll>>> dp;

ll dfs(ll r, ll c, ll l) {
    if (r < 0 || c < 0) return 0;
    if (dp[r][c][l] != -1) return dp[r][c][l];
    ll ret = - 2e15;
    // ひろう
    // ひろわない
    return dp[r][c][l] = ret;
}

int main() {
    ll R, C, K; cin >> R >> C >> K;
    grid = vector<vector<ll>>(R, vector<ll>(C, 0));
    dp = vector<vector<vector<ll>>>(R, vector<vector<ll>>(C, vector<ll>(3, -1)));
    for (int i = 0; i < K; ++i) {
        ll r, c, v; cin >> r >> c >> v;
        --r; --c;
        grid[r][c] = v;
    }
    ll ans = - 2e-15;
    for (int l = 0; l < 4; ++l) {
        ans = dfs(R-1, C-1, l);
    }
    cout << ans << endl;
    return 0;
}
