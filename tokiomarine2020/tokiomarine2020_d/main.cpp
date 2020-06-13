#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 513;
const int MAX_L = 1e5 + 1;
int N, Q, v, w, l;
vector<int> V = {-1};
vector<int> W = {-1};
int dp[MAX_N][MAX_L];

int solve(int v, int l) {
    if (v == 0) return 0;
    if (v < MAX_N && dp[v][l] >= 0) return dp[v][l];
    int ret;
    if (W[v] > l) {
        ret = solve(v / 2, l);
    } else {
        ret = max(solve(v / 2, l), solve(v / 2, l - W[v]) + V[v]);
    }
    if (v < MAX_N) dp[v][l] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> v >> w;
        V.push_back(v);
        W.push_back(w);
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> v >> l;
        cout << solve(v, l) << endl;
    }
    return 0;
}
