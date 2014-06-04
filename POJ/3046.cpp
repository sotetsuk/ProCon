#include <iostream>
using namespace std;

const int MAX_T = 1000, MAX_N = 100;
const int MAX_A = 10000;

int dp[MAX_T+5][MAX_A];

int T, A, S, B;
int l[MAX_T+5];

int dfs(int n, int s) {
    if(s > B) {
        return 0;
    }

    if(dp[n][s] != -1) {
        return dp[n][s];
    }

    if(n == T+1) {
        if(s >= S) {
            return 1;
        } else {
            return 0;
        }
    }

    int ret = 0;
    for(int i = 0; i <= l[n]; i++) {
        ret += dfs(n+1, s+i);
    }

    dp[n][s] = ret % 1000000;
    return dp[n][s];
}


int solve() {
    cin >> T >> A >> S >> B;
    int tmp;
    for(int i = 0; i < A; i++) {
        cin >> tmp;
        l[tmp]++;

    }
    int ans = dfs(1, 0);
    cout << ans << endl;
    return 0;
}

int main() {
    memset(dp, -1, sizeof(dp));
    solve();
    return 0;
}
